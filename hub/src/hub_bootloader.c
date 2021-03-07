/**
 ******************************************************************************
 * @file    hub_bootloader.c
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Hub Bootloader Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <string.h>

#include "hub/hub_bootloader.h"

#include "common/board_defs.h"
#include "common/memory.h"
#include "common/timers.h"
#include "common/log.h"
#include "common/test.h"
#include "common/printf.h"

#include "hub/cusb.h"
#include "hub/hub_test.h"
#include "hub/w25qxx.h"
#include "hub/sim.h"

/** @addtogroup HUB_BOOTLOADER_FILE 
 * @{
 */

/** @addtogroup HUB_BOOTLOADER_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void deinit(void);
static void test(void);
static bool program_bin(void);
static bool check_bin(void);
static bool check_crc(void);
static bool net_task(void);

static void sim_buf_clear(void);
static uint32_t sim_buf_append_printf(const char *format, ...);
static void _putchar_buffer(char character);

static char sim_buf[1536];
static uint16_t sim_buf_idx = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

typedef enum
{
	NET_0 = 0,
	NET_INIT,
	NET_REGISTERING,
	NET_REGISTERED,
	NET_CONNECTING,
	NET_CONNECTED,
	NET_ASSEMBLE_PACKET,
	NET_HTTPPOST,
	NET_HTTP_DONE,
	NET_SEND_ERROR_SMS,
	NET_DONE,
	NET_ERROR,
	NET_NUM_STATES,
} net_state_t;

typedef enum
{
	UPGRADE_INIT = 0,
	// Critical Section Start. Don't Change
	UPGRADE_DOWNLOAD_BIN,
	UPGRADE_CHECK_BIN,
	UPGRADE_PROGRAM_BIN,
	// Critical End
	UPGRADE_TEST_RUN_APP,
	UPGRADE_CHECK_APP_OK,
	UPGRADE_RECOVER_PREVIOUS_APP,
	UPGRADE_RECOVER_BACKUP_APP,
	UPGRADE_RECOVERY_FAILED,
	UPGRADE_CHECK_CLOUD,
	UPGRADE_DONE,
	UPGRADE_DO_NOTHING,
	UPGRADE_ERROR,
} upg_state_e;

typedef enum
{
	MSG_GET_NEXT_BIN,
	MSG_UPGRADE_ERROR,
	MSG_CHECK_FOR_UPDATE,
} msg_type_e;

static void prepare_msg(msg_type_e msg_type);

#define NET_LOG        \
	log_printf("NET: "); \
	log_printf

#define BACKUP_VERSION 100

#define BOOT_CLEAR_UPG_FLAG(x) mem_eeprom_write_word_ptr(&boot_info->upg_flags, (boot_info->upg_flags & (~(x))))
#define BOOT_SET_UPG_FLAG(x) mem_eeprom_write_word_ptr(&boot_info->upg_flags, (boot_info->upg_flags | (x)))

#define UPG_FLAG_DATA_ERR (1 << 0)
#define UPG_FLAG_DOWNLOAD_ERR (1 << 1)
#define UPG_FLAG_NO_BIN_ERR (1 << 2)
#define UPG_FLAG_CRC_ERR (1 << 3)
#define UPG_FLAG_PROG_ERR (1 << 4)
#define UPG_FLAG_TEST_ERR (1 << 5)

#define UPG_FLAG_FIRST_CHECK (1 << 6)
#define UPG_FLAG_APP_UPGRADE (1 << 7)
#define UPG_FLAG_RECOVERY (1 << 8)
#define UPG_FLAG_BACKUP (1 << 9)
#define UPG_FLAG_IWDG_UPGRADE (1 << 10)

#define BIN_HEADER_SIZE 64

typedef enum upg_type
{
	FIRST_BOOT,
	APP_UPGRADE,
	RECOVERY,
	BACKUP,
	IWDG,
} upg_type_e;

/** @} */

/** @addtogroup HUB_BOOTLOADER_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	init();

	uint32_t recovery_auto_timer = timers_millis();
	uint32_t recovery_check_timer = timers_millis();

	// If first power on
	if (boot_info->init_key != BOOT_INIT_KEY2)
	{
		BOOT_LOG("First App Check\n");

		serial_printf("Boot Version: %8u\n", VERSION);

		mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_fail_runs, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, 0);

		mem_eeprom_write_word_ptr(&boot_info->app_version, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_update_version, BACKUP_VERSION);
		mem_eeprom_write_word_ptr(&boot_info->app_previous_version, BACKUP_VERSION); // Default backup version (definitely working)

		mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_TEST_RUN_APP);
		mem_eeprom_write_word_ptr(&boot_info->upg_flags, UPG_FLAG_FIRST_CHECK);
		mem_eeprom_write_word_ptr(&boot_info->upg_in_progress, BOOT_UPGRADE_IN_PROGRESS_KEY);
		mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, BOOT_UPGRADE_NEW_APP_INSTALLED_KEY);

		// Set initialized
		mem_eeprom_write_word_ptr(&boot_info->init_key, BOOT_INIT_KEY2);
	}
	// Try downgrade to backup version if watchdog resetting app
	else if (boot_info->app_num_iwdg_reset > 3 &&
			 (boot_info->upg_in_progress != BOOT_UPGRADE_IN_PROGRESS_KEY))
	{
		mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVER_BACKUP_APP);

		mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);

		mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, 0);
		mem_eeprom_write_word_ptr(&boot_info->upg_done, 0);

		mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, 0);
		mem_eeprom_write_word_ptr(&boot_info->upg_flags, UPG_FLAG_IWDG_UPGRADE);

		mem_eeprom_write_word_ptr(&boot_info->upg_in_progress, BOOT_UPGRADE_IN_PROGRESS_KEY);
	}
	// Begin upgrade if signaled by main app, if not already happening
	else if ((shared_info->upg_pending == SHARED_UPGRADE_PENDING_KEY) &&
			 (boot_info->app_ok_key == BOOT_APP_OK_KEY) &&
			 (boot_info->upg_in_progress != BOOT_UPGRADE_IN_PROGRESS_KEY))
	{

		mem_eeprom_write_word_ptr(&boot_info->app_version, shared_info->app_curr_version);
		mem_eeprom_write_word_ptr(&boot_info->app_update_version, shared_info->app_next_version);
		mem_eeprom_write_word_ptr(&boot_info->app_previous_version, shared_info->app_curr_version);

		mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_INIT);
		mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, 0);
		mem_eeprom_write_word_ptr(&boot_info->upg_done, 0);

		mem_eeprom_write_word_ptr(&boot_info->upg_version_to_download, 0);
		mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, 0);
		mem_eeprom_write_word_ptr(&boot_info->upg_flags, UPG_FLAG_APP_UPGRADE);

		// Only try upgrade once
		mem_eeprom_write_word_ptr(&boot_info->upg_in_progress, BOOT_UPGRADE_IN_PROGRESS_KEY);
	}

	// State machine for upgrade procedure,
	// if upgrade fail, install previous version
	// then try backup version
	// then wait for instructions from cloud
	if (boot_info->upg_in_progress == BOOT_UPGRADE_IN_PROGRESS_KEY)
	{
		bool break_upg_loop = false;
		bool download_ok = false;
		uint32_t timer = 0;

		// If reset occurs during critical part (downloading/ programming .bin), restart download section
		if ((boot_info->upg_state >= UPGRADE_DOWNLOAD_BIN) && (boot_info->upg_state <= UPGRADE_PROGRAM_BIN))
		{

			mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DOWNLOAD_BIN);
		}

		while (break_upg_loop == false)
		{
			timers_pet_dogs();

			serial_printf("Upgrade State: %u\n", boot_info->upg_state);

			switch (boot_info->upg_state)
			{
			case UPGRADE_INIT:
				BOOT_LOG("Begin upgrade from v%u to v%u\n", boot_info->app_version, boot_info->app_update_version);

				// Check info is set
				if ((boot_info->app_version != 0) &&
					(boot_info->app_update_version != 0) &&
					(boot_info->app_previous_version != 0))
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_version_to_download, boot_info->app_update_version);

					prepare_msg(MSG_GET_NEXT_BIN);

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DOWNLOAD_BIN);
				}
				else
				{
					BOOT_LOG("Upgrade data incorrect\n");
					BOOT_SET_UPG_FLAG(UPG_FLAG_DATA_ERR);
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_ERROR);
				}
				break;

			case UPGRADE_DOWNLOAD_BIN:
				// Check for version & try download for 3 min
				BOOT_LOG("Download Version %u\n", boot_info->upg_version_to_download);
				timer = timers_millis();
				download_ok = false;
				while ((false == download_ok) && ((timers_millis() - timer) < 180000))
				{
					download_ok = net_task();
				}

				if (download_ok == true)
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_CHECK_BIN);
				}
				else
				{
					BOOT_SET_UPG_FLAG(UPG_FLAG_DOWNLOAD_ERR);
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_ERROR);
				}
				break;

			case UPGRADE_CHECK_BIN:
				if (check_bin() == true)
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_PROGRAM_BIN);
				}
				else
				{
					// UPG flags set in check_bin()
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_ERROR);
				}
				break;

			case UPGRADE_PROGRAM_BIN:
				// Once this state is reached assume that program memory is garbage unless succesfull programming
				mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);

				if (program_bin() == true)
				{
					BOOT_LOG("Binary installed\n");
					mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, BOOT_UPGRADE_NEW_APP_INSTALLED_KEY);

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_TEST_RUN_APP);
				}
				else
				{
					BOOT_LOG("Programming fail\n");
					BOOT_SET_UPG_FLAG(UPG_FLAG_PROG_ERR);
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_ERROR);
				}

				break;

			case UPGRADE_TEST_RUN_APP:
				// Break while loop to allow program to run and check if its ok
				break_upg_loop = true;
				mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_CHECK_APP_OK);
				break;

			case UPGRADE_CHECK_APP_OK:
				if (shared_info->app_ok_key == SHARED_APP_OK_KEY)
				{
					// Program running succesfully
					mem_eeprom_write_word_ptr(&boot_info->app_ok_key, BOOT_APP_OK_KEY);

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DONE);
				}
				else
				{
					// Currently fail after first failed run
					mem_eeprom_write_word_ptr(&boot_info->app_num_fail_runs, boot_info->app_num_fail_runs + 1);

					if (boot_info->app_num_fail_runs >= 1)
					{
						BOOT_SET_UPG_FLAG(UPG_FLAG_TEST_ERR);
						mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_ERROR);
					}
					else
					{
						// Try again
						mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_TEST_RUN_APP);
					}
				}
				break;

			case UPGRADE_RECOVER_PREVIOUS_APP:
				mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, boot_info->upg_num_recovery_attempts + 1);
				if (boot_info->upg_num_recovery_attempts > 3)
				{
					// Reset counter for backup attempt
					mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, 0);
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVER_BACKUP_APP);
				}
				else
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_version_to_download, boot_info->app_previous_version);
					mem_eeprom_write_word_ptr(&boot_info->upg_flags, UPG_FLAG_RECOVERY);

					prepare_msg(MSG_GET_NEXT_BIN);

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DOWNLOAD_BIN);
				}
				break;

			case UPGRADE_RECOVER_BACKUP_APP:
				mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, boot_info->upg_num_recovery_attempts + 1);
				if (boot_info->upg_num_recovery_attempts > 3)
				{
					recovery_auto_timer = timers_millis();
					recovery_check_timer = timers_millis();

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVERY_FAILED);
				}
				else
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_version_to_download, BACKUP_VERSION);
					mem_eeprom_write_word_ptr(&boot_info->upg_flags, UPG_FLAG_BACKUP);

					prepare_msg(MSG_GET_NEXT_BIN);

					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DOWNLOAD_BIN);
				}
				break;

			case UPGRADE_RECOVERY_FAILED:
				// Worst case senario, failed to update and then failed to install previous & backup bins. Check for instructions from cloud every minute. Send report & try auto recover every hour
				timers_delay_milliseconds(5000);
				if ((timers_millis() - recovery_check_timer) > 60000)
				{
					recovery_check_timer = timers_millis();
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_CHECK_CLOUD);
				}
				else if ((timers_millis() - recovery_auto_timer) > 3600000)
				{
					recovery_auto_timer = timers_millis();
					mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, 0);
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVER_BACKUP_APP);
				}
				break;

			case UPGRADE_CHECK_CLOUD:
				prepare_msg(MSG_CHECK_FOR_UPDATE);
				timer = timers_millis();
				download_ok = false;
				while ((false == download_ok) && ((timers_millis() - timer) < 180000))
				{
					download_ok = net_task();
				}

				if (download_ok == true)
				{
					// Check response, download new bin
					serial_printf("Todo UPGRADE_CHECK_CLOUD\n");
					while (1)
						;
				}
				else
				{
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVERY_FAILED);
				}
				break;

			case UPGRADE_DONE:
				mem_eeprom_write_word_ptr(&boot_info->upg_done, BOOT_UPGRADE_DONE_KEY);
				mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DO_NOTHING);
				break;

			case UPGRADE_DO_NOTHING:
				break_upg_loop = true;
				break;

			// If any problems during upgrade, check if old version still programmed and ok. If so, signal app to send error message and continue
			// Otherwise download previous working version.
			case UPGRADE_ERROR:
				BOOT_LOG("Upgrade Error\n");

				// Send error + flags
				prepare_msg(MSG_UPGRADE_ERROR);
				timer = timers_millis();
				download_ok = false;
				while ((false == download_ok) && ((timers_millis() - timer) < 60000))
				{
					download_ok = net_task();
				}

				// Check if old version still programmed
				if (boot_info->app_ok_key == BOOT_APP_OK_KEY)
				{
					BOOT_LOG("App still Ok\n");

					// Send error message
					mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_DONE);
				}
				// Otherwise recover
				else
				{
					// Try previous app
					if ((boot_info->upg_version_to_download == boot_info->app_update_version) ||
						(boot_info->upg_version_to_download == boot_info->app_previous_version))
					{
						BOOT_LOG("Recover Old\n");
						mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVER_PREVIOUS_APP);
					}
					// Try backup
					else if (boot_info->upg_version_to_download == BACKUP_VERSION)
					{
						BOOT_LOG("Recover Backup\n");
						mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVER_BACKUP_APP);
					}
					// All other cases, check for instructions from cloud, and try install backup every hour
					else
					{
						BOOT_LOG("Recover Failed\n");
						mem_eeprom_write_word_ptr(&boot_info->upg_state, UPGRADE_RECOVERY_FAILED);
					}
				}
				break;
			}

			timers_pet_dogs();
		}
	}

	// Setup fresh app after new bin installed
	if (boot_info->upg_new_app_installed == BOOT_UPGRADE_NEW_APP_INSTALLED_KEY)
	{
		BOOT_LOG("New App Installed\n");
		// Boot Info

		// Default app info setup by boot_init() when app_init_key is not set
		mem_eeprom_write_word_ptr(&boot_info->app_init_key, 0);

		mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, 0);
	}

	// Setup eeprom for first run of new app
	if (boot_info->app_init_key != BOOT_APP_INIT_KEY)
	{
		BOOT_LOG("Setup App\n");

		// Boot Info
		mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_fail_runs, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, 0);

		mem_eeprom_write_word_ptr(&boot_info->app_version, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_update_version, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_previous_version, 100); // Default backup version (definitely working)

		// Shared Info
		mem_eeprom_write_word_ptr(&shared_info->app_curr_version, 0);
		mem_eeprom_write_word_ptr(&shared_info->app_next_version, 0);
		mem_eeprom_write_word_ptr(&shared_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&shared_info->upg_pending, 0);
		mem_eeprom_write_word_ptr(&shared_info->upg_flags, boot_info->upg_flags);

		// App Info
		mem_eeprom_write_word_ptr(&app_info->init_key, 0);
		mem_eeprom_write_word_ptr(&app_info->app_version, 0);
		mem_eeprom_write_word_ptr(&app_info->dev_num, boot_info->dev_num);
		mem_eeprom_write_word_ptr(&app_info->boot_version, VERSION);
		mem_eeprom_write_word_ptr(&app_info->registered_key, 0);

		uint8_t *u8ptr = NULL;

		for (uint8_t i = 0; i < sizeof(app_info->aes_key); i++)
		{
			u8ptr = &app_info->aes_key[i];
			mem_eeprom_write_byte((uint32_t)u8ptr, boot_info->aes_key[i]);
		}

		for (uint8_t i = 0; i < sizeof(app_info->pwd); i++)
		{
			u8ptr = (uint8_t *)&app_info->pwd[i];
			mem_eeprom_write_byte((uint32_t)u8ptr, boot_info->pwd[i]);
		}

		mem_eeprom_write_word_ptr(&boot_info->app_init_key, BOOT_APP_INIT_KEY);
	}

	// Reinitialize upgrade procedure, only run after confirmed that app is running successfully
	if (boot_info->upg_done == BOOT_UPGRADE_DONE_KEY)
	{
		BOOT_LOG("Upgrade Done %8x\n", boot_info->upg_flags);

		mem_eeprom_write_word_ptr(&boot_info->app_version, shared_info->app_curr_version);

		mem_eeprom_write_word_ptr(&boot_info->app_previous_version, shared_info->app_curr_version);

		mem_eeprom_write_word_ptr(&boot_info->upg_in_progress, 0);

		mem_eeprom_write_word_ptr(&boot_info->upg_done, 0);
	}

	test();

	// serial print finish
	timers_delay_milliseconds(1000);

	// Deinit peripherals
	deinit();

	// Run Application
	timers_pet_dogs();
	boot_jump_to_application(boot_info->vtor);

	for (;;)
	{
		serial_printf("Hub Bootloader Loop\n\n");
		__asm__("nop");
	}

	return 0;
}

/** @} */

/** @addtogroup HUB_BOOTLOADER_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void)
{
	clock_setup_hsi_16mhz();
	// cusb_init();
	timers_lptim_init();
	log_init();
	flash_led(100, 5);

	BOOT_LOG("Hub Bootloader Init\n");
	boot_init();
}

static void deinit(void)
{
	// cusb_end();
	// clock_setup_msi_2mhz();
	// log_init();
}

static void test(void)
{
	// download_and_program_bin("https://cooleasetest.000webhostapp.com/hub.php", 3);
}

static void prepare_msg(msg_type_e msg_type)
{
	sim_buf_clear();
	sim_buf_append_printf("pwd=%s"
						  "&id=%8u"
						  "&upg_flags=%8u",
						  boot_info->pwd,
						  boot_info->dev_num,
						  boot_info->upg_flags);
	switch (msg_type)
	{
	case MSG_GET_NEXT_BIN:
		sim_buf_append_printf("version=%u\n", boot_info->upg_version_to_download);
		break;

	case MSG_UPGRADE_ERROR:
		sim_buf_append_printf("error=true\n");
		break;

	case MSG_CHECK_FOR_UPDATE:
		sim_buf_append_printf("version=get\n");
		break;
	default:
		break;
	}

	sim_buf_append_printf("\0");
}

static bool net_task(void)
{
	timers_pet_dogs();

	static net_state_t net_state = NET_0;
	static net_state_t net_next_state = NET_0;
	static net_state_t net_fallback_state = NET_0;
	bool net_finish = false;

	sim800.state = SIM_ERROR;

	switch (net_state)
	{
	// Upload inital message
	case NET_0:
		NET_LOG("Init\n");
		net_next_state = NET_INIT;
		net_fallback_state = NET_INIT;

		sim800.state = SIM_SUCCESS;

		break;

	case NET_INIT:
		net_next_state = NET_REGISTERING;
		net_fallback_state = NET_INIT;

		sim800.state = sim_init();

		if (sim800.state == SIM_SUCCESS)
		{
			NET_LOG("Registering\n");
		}

		break;

	case NET_REGISTERING:
		net_next_state = NET_REGISTERED;
		net_fallback_state = NET_INIT;

		sim800.state = sim_register_to_network();

		if (sim800.state == SIM_SUCCESS)
		{
			NET_LOG("Connecing\n");
		}
		break;

	case NET_CONNECTING:
		net_next_state = NET_CONNECTED;
		net_fallback_state = NET_REGISTERING;

		sim800.state = sim_open_bearer("data.rewicom.net", "", "");
		break;

	case NET_CONNECTED:
		net_next_state = NET_ASSEMBLE_PACKET;
		net_fallback_state = NET_CONNECTING;

		sim800.state = sim_is_connected();

		if (sim800.state == SIM_SUCCESS)
		{
			NET_LOG("Connected\n");
		}
		else if (sim800.state != SIM_BUSY)
		{
			NET_LOG("Connection Lost\n");
		}
		break;

	// Assembled by main program (prepare_msg())
	case NET_ASSEMBLE_PACKET:
		net_next_state = NET_HTTPPOST;
		net_fallback_state = NET_CONNECTED;

		sim800.state = SIM_SUCCESS;

		serial_printf("--------\nMSG: %s\n--------\n", sim_buf);
		break;

	case NET_HTTPPOST:
		net_next_state = NET_HTTP_DONE;
		net_fallback_state = NET_CONNECTED;

		sim800.state = sim_http_post_str("http://rickceas.azurewebsites.net/CE/hub.php", sim_buf, false, 3);
		break;

	case NET_HTTP_DONE:
		net_next_state = NET_CONNECTED;
		net_fallback_state = NET_CONNECTED;

		// Goto next state
		sim800.state = SIM_SUCCESS;

		serial_printf("HTTP: %u %u\n", sim800.http.status_code, sim800.http.response_size);
		break;

	// Reset and return true, main will install downloaded bin
	case NET_DONE:
		net_next_state = NET_CONNECTED;
		net_fallback_state = NET_0;

		sim800.state = SIM_SUCCESS;

		NET_LOG("Download Succesfull\n");

		net_finish = true;
		break;

	case NET_ERROR:
		NET_LOG("ERROR State\n");
		net_next_state = NET_INIT;
		sim800.state = SIM_SUCCESS;
		break;

	default:
		NET_LOG("DEFAULT State\n");
		net_next_state = NET_INIT;
		sim800.state = SIM_SUCCESS;
		break;
	}

	if (sim800.state == SIM_SUCCESS)
	{
		net_state = net_next_state;
	}
	else if (sim800.state == SIM_ERROR || sim800.state == SIM_TIMEOUT)
	{
		NET_LOG("SIM ERR %u fb %u\n", net_state, net_fallback_state);
		net_state = net_fallback_state;
	}

	return net_finish;
}

static bool check_bin(void)
{
	bool ret = false;

	// Check header (no bin)
	char buf[BIN_HEADER_SIZE] = {0};
	uint32_t num_bytes = sim_http_read_response(0, 63, (uint8_t *)buf);
	buf[num_bytes] = '\0';

	if (strstr(buf, "No Bin"))
	{
		BOOT_SET_UPG_FLAG(UPG_FLAG_NO_BIN_ERR);
	}
	// Todo: check returned version number same as expected
	else if(check_crc() == false)
	{
		BOOT_SET_UPG_FLAG(UPG_FLAG_CRC_ERR);
	}
	else
	{
		BOOT_LOG("Bin Check OK\n");
		ret = true;
	}

	return ret;
}

static bool check_crc(void)
{
	bool ret = false;
	uint32_t file_size = 0;

	if (sim800.http.response_size <= BIN_HEADER_SIZE)
	{
		file_size = 0;
	}
	else
	{
		file_size = sim800.http.response_size - BIN_HEADER_SIZE;
	}

	if (file_size)
	{
		// Todo: make sure num half pages is an even integer, otherwise will program garbage at end
		uint16_t num_half_pages = ((file_size - 1) / (FLASH_PAGE_SIZE / 2)) + 1;

		serial_printf("Num half pages %i\n", num_half_pages);

		// Get data and program
		for (uint16_t n = 0; n < num_half_pages; n++)
		{
			serial_printf("------------------------------\n");
			serial_printf("-----------Half Page %i-------\n", n);
			serial_printf("------------------------------\n");

			// Half page buffer
			// Using union so that data can be read as bytes and programmed as u32
			// this automatically deals with endianness
			union
			{
				uint8_t buf8[FLASH_PAGE_SIZE / 2];
				uint32_t buf32[(FLASH_PAGE_SIZE / 2) / 4];
			} half_page;

			// HTTPREAD command & get number of bytes read
			// 		*number of bytes returned may be less than requested depending how many are left in file
			// 		SIM800 signifies how many bytes are returned
			uint8_t num_bytes = sim_http_read_response(BIN_HEADER_SIZE + (n * FLASH_PAGE_SIZE / 2), (FLASH_PAGE_SIZE / 2), half_page.buf8);

			// Print out for debugging
			serial_printf("Got half page %8x\n", (n * FLASH_PAGE_SIZE / 2));

			// Program half page
			static bool lower = true;
			uint32_t crc = boot_get_half_page_checksum(half_page.buf32);
			if (boot_program_half_page(lower, crc, n / 2, half_page.buf32))
			{
				serial_printf("Programming success\n");
			}
			else
			{
				serial_printf("Programming Fail\n");
			}

			lower = !lower;
		}
		serial_printf("Programming Done\n\n");
	}
	
	return ret;
}

static bool program_bin(void)
{
	bool ret = false;
	uint32_t file_size;

	if (sim800.http.response_size <= BIN_HEADER_SIZE)
	{
		file_size = 0;
	}
	else
	{
		file_size = sim800.http.response_size - BIN_HEADER_SIZE;
	}

	BOOT_LOG("Program %u bytes\n", file_size);

	if (file_size)
	{
		// Todo: make sure num half pages is an even integer, otherwise will program garbage at end
		uint16_t num_half_pages = ((file_size - 1) / (FLASH_PAGE_SIZE / 2)) + 1;

		serial_printf("Num half pages %i\n", num_half_pages);

		// Get data and program
		for (uint16_t n = 0; n < num_half_pages; n++)
		{
			serial_printf("------------------------------\n");
			serial_printf("-----------Half Page %i-------\n", n);
			serial_printf("------------------------------\n");

			// Half page buffer
			// Using union so that data can be read as bytes and programmed as u32
			// this automatically deals with endianness
			union
			{
				uint8_t buf8[FLASH_PAGE_SIZE / 2];
				uint32_t buf32[(FLASH_PAGE_SIZE / 2) / 4];
			} half_page;

			// HTTPREAD command & get number of bytes read
			// 		*number of bytes returned may be less than requested depending how many are left in file
			// 		SIM800 signifies how many bytes are returned
			uint8_t num_bytes = sim_http_read_response(BIN_HEADER_SIZE + (n * FLASH_PAGE_SIZE / 2), (FLASH_PAGE_SIZE / 2), half_page.buf8);

			// Print out for debugging
			serial_printf("Got half page %8x\n", (n * FLASH_PAGE_SIZE / 2));

			// Program half page
			if (mem_flash_write_half_page(FLASH_APP_ADDRESS + (n * FLASH_PAGE_SIZE / 2), half_page.buf32))
			{
				serial_printf("Programming success\n");
			}
			else
			{
				serial_printf("Programming Fail\n");
				ret = false;
				break;
			}
		}
		serial_printf("Programming Done\n\n");
		ret = true;
	}
	return ret;
}

static void sim_buf_clear(void)
{
	for (uint16_t i = 0; i < sim_buf_idx; i++)
	{
		sim_buf[i] = '\0';
	}
	sim_buf_idx = 0;
}

static uint32_t sim_buf_append_printf(const char *format, ...)
{
	va_list va;
	va_start(va, format);
	uint32_t res = fnprintf(_putchar_buffer, format, va);
	va_end(va);

	return res;
}

static void _putchar_buffer(char character)
{
	sim_buf[sim_buf_idx++] = character;
}

/** @} */
/** @} */
