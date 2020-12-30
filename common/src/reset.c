#include "common/reset.h"

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

#include "common/log.h"

void reset_print_cause(void)
{
	rcc_periph_clock_enable(RCC_PWR);
	
    if(pwr_get_standby_flag())
	{
		log_printf(MAIN, "Standby flag set\n");
		pwr_clear_standby_flag();
	}

	if(pwr_get_wakeup_flag())
	{
		log_printf(MAIN, "Wakeup flag set\n");
		pwr_clear_wakeup_flag();
	}

    if(RCC_CSR & RCC_CSR_LPWRRSTF)
	{
		log_printf(MAIN, "Low Power Reset\n");
	}

	if(RCC_CSR & RCC_CSR_WWDGRSTF)
	{
		log_printf(MAIN, "Window Watchdog Reset\n");
	}

	if(RCC_CSR & RCC_CSR_IWDGRSTF)
	{
		log_printf(MAIN, "I Watchdog Reset\n");
	}

	if(RCC_CSR & RCC_CSR_SFTRSTF)
	{
		log_printf(MAIN, "SFTRSTF Reset\n");
	}

	if(RCC_CSR & RCC_CSR_PORRSTF)
	{
		log_printf(MAIN, "PORRSTF Reset\n");
	}

	if(RCC_CSR & RCC_CSR_PINRSTF)
	{
		log_printf(MAIN, "PINRSTF Reset\n");
	}

    RCC_CSR |= RCC_CSR_RMVF;
}
