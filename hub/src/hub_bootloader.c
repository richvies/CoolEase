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

#include "hub/hub_bootloader.h"

#include "common/board_defs.h"
#include "common/memory.h"
#include "common/timers.h"
#include "common/log.h"
#include "common/test.h"

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
static bool download_and_program_bin(const char *url, uint8_t num_attempts);

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */

/** @addtogroup HUB_BOOTLOADER_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	// Stop unused warnings
	(void)download_and_program_bin;
	
	init();

	// download_and_program_bin("http://cooleasetest.000webhostapp.com/hub.bin", 3);

	// test_sim_serial_passtrhough();
	// test_sim_get_request();

	boot_jump_to_application(FLASH_APP_ADDRESS);

	// serial_printf("Hub Bootloader Ready");

	for (;;)
	{
		// serial_printf("Hub Bootloader Loop\n\n");
		// timers_delay_milliseconds(1000);
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
	clock_setup_msi_2mhz();
	log_init();
	timers_lptim_init();
	timers_tim6_init();
	flash_led(100, 10);
	log_printf("Hub Bootloader Start\n");
}

static bool download_and_program_bin(const char *url, uint8_t num_attempts)
{
	bool result = true;

	serial_printf("Download and program bin: %s\n", url);

	for (uint8_t attempt = 0; attempt < num_attempts; attempt++)
	{
		serial_printf("Attempt %i\n", attempt);

		if (sim_init() && sim_set_full_function() && sim_register_to_network())
		{
			uint32_t file_size = sim_http_get(url);

			if (file_size)
			{
				// Todo: make sure num half pages is an even integer, otherwise will program garbage at end
				uint16_t num_half_pages = (file_size / (FLASH_PAGE_SIZE / 2)) + 1;

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
						uint8_t buf8[64];
						uint32_t buf32[16];
					} half_page;

					// HTTPREAD command & get number of bytes read
					// 		*number of bytes returned may be less than requested depending how many are left in file
					// 		SIM800 signifies how many bytes are returned
					uint8_t num_bytes = sim_http_read_response((n * FLASH_PAGE_SIZE / 2), (FLASH_PAGE_SIZE / 2));

					// SIM800 now returns that number of bytes
					for (uint8_t i = 0; i < num_bytes; i++)
					{
						while (!sim_available())
						{
						};
						half_page.buf8[i] = (uint8_t)sim_read();
					}

					// Wait for final ok reply
					sim_printf_and_check_response(2000, "OK", "");

					// Print out for debugging
					serial_printf("Got half page %8x\n", (n * FLASH_PAGE_SIZE / 2));
					// for (uint8_t i = 0; i < num_bytes; i++)
					// {
					// 	if(!(i % 4))
					// 	{
					// 		// Print 32 bit version every 4 bytes
					// 		serial_printf("\n%8x\n", half_page.buf32[(i / 4)]);
					// 	}
					// 	serial_printf("%2x ", half_page.buf8[i]);
					// }

					serial_printf("\nHalf page Done\nProgramming\n");

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
				sim_http_term();
				sim_end();
			}
		}
	}

	return result;
}

/** @} */
/** @} */
