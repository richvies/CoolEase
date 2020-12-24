#include "coolease/reset.h"

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

#include "coolease/serial_printf.h"

void reset_print_cause(void)
{
	rcc_periph_clock_enable(RCC_PWR);
	
    if(pwr_get_standby_flag())
	{
		spf_serial_printf("Standby flag set\n");
		pwr_clear_standby_flag();
	}

	if(pwr_get_wakeup_flag())
	{
		spf_serial_printf("Wakeup flag set\n");
		pwr_clear_wakeup_flag();
	}

    if(RCC_CSR & RCC_CSR_LPWRRSTF)
	{
		spf_serial_printf("Low Power Reset\n");
	}

	if(RCC_CSR & RCC_CSR_WWDGRSTF)
	{
		spf_serial_printf("Window Watchdog Reset\n");
	}

	if(RCC_CSR & RCC_CSR_IWDGRSTF)
	{
		spf_serial_printf("I Watchdog Reset\n");
	}

	if(RCC_CSR & RCC_CSR_SFTRSTF)
	{
		spf_serial_printf("SFTRSTF Reset\n");
	}

	if(RCC_CSR & RCC_CSR_PORRSTF)
	{
		spf_serial_printf("PORRSTF Reset\n");
	}

	if(RCC_CSR & RCC_CSR_PINRSTF)
	{
		spf_serial_printf("PINRSTF Reset\n");
	}

    RCC_CSR |= RCC_CSR_RMVF;
}
