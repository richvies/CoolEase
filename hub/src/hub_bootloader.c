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
	test_cusb_get_log();
	// cusb_init();

    // boot_jump_to_application(APP_ADDRESS);

	(void)init;
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
    log_printf("Hub Bl Start\n");
}

/** @} */
/** @} */
