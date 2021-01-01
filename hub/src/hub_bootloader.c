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

/** @addtogroup HUB_BOOTLOADER_FILE 
 * @{
 */

#define APP_ADDRESS 0x08004000

/** @addtogroup HUB_BOOTLOADER_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/


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
	clock_setup_MSI_2MHZ();

    log_init();
	timers_lptim_init();
	timers_tim6_init();

	#ifdef DEBUG
	for(int i = 0; i < 100000; i++){__asm__("nop");};
	#endif 
	
    log_printf("Hub Bl Start\n");

	// cusb_init();
	// cusb_test_poll();

	// test_boot_verify_checksum();
	// test_crc();

    // boot_jump_to_application(APP_ADDRESS);

    for (;;)
	{
		// log_printf("Hub Bootloader Loop\n\n");
		// timers_delay_milliseconds(1000);
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

/** @} */
/** @} */
