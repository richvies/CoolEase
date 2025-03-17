#ifndef BOARD_DEFS_H
#define BOARD_DEFS_H

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>

#include "common/log.h"

extern enum rcc_osc sys_clk;

#define PRINT_REG(reg) serial_printf("%s : %8x\n",#reg, reg);

#define PRINT_OK() serial_printf("OK\n")

/*////////////////////////////////////////////////////////////////////////////*/
// Flash Map
/*////////////////////////////////////////////////////////////////////////////*/

#define FLASH_PAGE_SIZE     	128U
#define FLASH_NUM_PAGES     	512U
#define FLASH_HALF_PAGE_SIZE_BYTES	(FLASH_PAGE_SIZE / 2)

#define FLASH_START         	0x08000000U
#define FLASH_APP_ADDRESS     	0x08008000U
#define FLASH_APP_END       	0x08010000U
#define FLASH_END           	0x08010000U

#define FLASH_BOOT_ADDRESS    	0x08000000U
#define FLASH_APP_ADDRESS       0x08008000U

/*////////////////////////////////////////////////////////////////////////////*/
// EEPROM Map
/*////////////////////////////////////////////////////////////////////////////*/

#define EEPROM_PAGE_SIZE    4U
#define EEPROM_NUM_PAGES    512U
#define EEPROM_START        0x08080000U
#define EEPROM_SIZE         2048U
#define EEPROM_END          (EEPROM_START + EEPROM_SIZE)

// Size of sections within eeprom
#define EEPROM_BOOT_INFO_SIZE 		256U
#define EEPROM_APP_INFO_SIZE        256U
#define EEPROM_LOG_SIZE             1024U
#define EEPROM_SHARED_INFO_SIZE     64U

// Check EEPROM memory large enough
#if ((EEPROM_SHARED_INFO_SIZE + EEPROM_BOOT_INFO_SIZE + EEPROM_APP_INFO_SIZE + EEPROM_LOG_SIZE) > EEPROM_SIZE)
#warning "EEPROM: Data does not fit"
#endif

// Bootloader Information
#define EEPROM_BOOT_INFO_BASE      		EEPROM_START
#define EEPROM_BOOT_INFO_END       		(EEPROM_BOOT_INFO_BASE + EEPROM_BOOT_INFO_SIZE)

// Device information
#define EEPROM_APP_INFO_BASE            EEPROM_BOOT_INFO_END
#define EEPROM_APP_INFO_END             (EEPROM_APP_INFO_BASE + EEPROM_APP_INFO_SIZE)

// Logging
#define EEPROM_LOG_BASE                 EEPROM_APP_INFO_END
#define EEPROM_LOG_END                  (EEPROM_LOG_BASE + EEPROM_LOG_SIZE)
// Backup log in flash
#define FLASH_LOG_BKP                   (FLASH_END - EEPROM_LOG_SIZE)

// Shared information
#define EEPROM_SHARED_INFO_BASE         EEPROM_LOG_END
#define EEPROM_SHARED_INFO_END          (EEPROM_SHARED_INFO_BASE + EEPROM_SHARED_INFO_SIZE)

/*////////////////////////////////////////////////////////////////////////////*/
// RTC Backup Registers
/*////////////////////////////////////////////////////////////////////////////*/

#define BKUP_0	0
#define BKUP_1	1
#define BKUP_2	2
#define BKUP_3	3
#define BKUP_4	4

#define BKUP_BOOT_MAGIC_SKIP	BKUP_0
#define BKUP_NUM_IWDG_RESET		BKUP_1
#define BKUP_RESET_FLAGS		BKUP_2
#define BKUP_BOOT_OK			BKUP_3
#define BKUP_APP_STATE			BKUP_4

#define BOOT_OK_KEY 0x12FEC43A

/*////////////////////////////////////////////////////////////////////////////*/
// Runtime info
/*////////////////////////////////////////////////////////////////////////////*/
#define SHARED_UPGRADE_PENDING_KEY 0x1234FEDC
#define SHARED_APP_OK_KEY 0x2468FECA

#define BOOT_MAGIC_SKIP_KEY 0xABC3F982
#define BOOT_INIT_KEY 0x135725AB
#define BOOT_INIT_KEY2 0x24FEC571
#define BOOT_APP_INIT_KEY 0x26FED390
#define BOOT_APP_OK_KEY 0xFDC378F2

#define BOOT_UPGRADE_IN_PROGRESS_KEY 0xACD15FE6
#define BOOT_UPGRADE_NEW_APP_INSTALLED_KEY 0xFDC378F2
#define BOOT_UPGRADE_DONE_KEY 0xACD15FE6

#define APP_INIT_KEY 0x1357ACDE


typedef struct
{
	uint32_t boot_version;
	uint32_t upg_pending;
	uint32_t upg_flags;

	uint32_t app_ok_key;
	uint32_t app_curr_version;
	uint32_t app_next_version;
} shared_info_t;

typedef enum
{
    BOOT_RESET = 0,
    BOOT_CONNECTED,
    BOOT_GET_LOG
} boot_state_t;

typedef struct
{
	// Permanent, need to be programed before hand
	uint32_t dev_id;
	char 	 dev_type[8]; // 'hub' / 'sensor'
	uint32_t vtor;
	uint8_t	 aes_key[16];
	char 	 pwd[33];

	// Variable
	uint32_t init_key;

	uint32_t upg_in_progress;
	uint32_t upg_new_app_installed;
	uint32_t upg_done;
	uint32_t upg_state;
	uint32_t upg_flags;

	uint32_t upg_version_to_download;
	uint32_t upg_num_recovery_attempts;

	uint32_t app_init_key;
	uint32_t app_ok_key;
	uint32_t app_num_iwdg_reset;
	uint32_t app_num_fail_runs;
	uint32_t app_version;
	uint32_t app_update_version;
	uint32_t app_previous_version;
} boot_info_t;

typedef struct
{
	uint32_t init_key;

	uint32_t dev_id;
	uint32_t registered_key;
	uint8_t  aes_key[16];
	char 	 pwd[33];
} app_info_t;

typedef struct
{
	uint16_t size;
	uint16_t idx;
	uint8_t log[];
} log_t;

// Uncomment to check size
// uint32_t size = sizeof(shared_info_t);
// uint32_t size = sizeof(boot_info_t);
// uint32_t size = sizeof(app_info_t);
// uint32_t size = sizeof(log_t);

extern shared_info_t *shared_info;
extern boot_info_t *boot_info;
extern app_info_t *app_info;
extern log_t *log_file;


#ifdef COOLEASE_DEVICE_HUB
#include "hub_defs.h"
#else
#include "sensor_defs.h"
#endif

void clock_setup_msi_2mhz(void);
void clock_setup_hsi_16mhz(void);
void set_gpio_for_standby(void);
void set_app_ok(void);
void flash_led(uint16_t milliseconds, uint8_t num_flashes);


#endif