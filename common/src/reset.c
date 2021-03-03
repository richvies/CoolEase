#include "common/reset.h"

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

#include "common/log.h"
#include "common/memory.h"
#include "common/timers.h"

#define RESET_WAKEUP_FLAG	(1 << 0)
#define RESET_STANDBY_FLAG	(1 << 1)

void reset_print_cause(void)
{
	uint32_t reset_flags = reset_get_flags();

    if(reset_flags & RCC_CSR_LPWRRSTF)
	{
		log_printf("Low Power Reset\n");
	}

	if(reset_flags & RCC_CSR_WWDGRSTF)
	{
		log_printf("Window Watchdog Reset\n");
	}

	if(reset_flags & RCC_CSR_IWDGRSTF)
	{
		log_printf("I Watchdog Reset\n");
	}

	if(reset_flags & RCC_CSR_SFTRSTF)
	{
		log_printf("SFTRSTF Reset\n");
	}

	if(reset_flags & RCC_CSR_PORRSTF)
	{
		log_printf("PORRSTF Reset\n");
	}

	if(reset_flags & RCC_CSR_PINRSTF)
	{
		log_printf("PINRSTF Reset\n");
	}
}

void reset_save_flags(void)
{
	mem_program_bkp_reg(BKUP_RESET_FLAGS, (RCC_CSR & RCC_CSR_RESET_FLAGS));
	RCC_CSR |= RCC_CSR_RMVF;
}

uint32_t reset_get_flags(void)
{
	return mem_read_bkp_reg(BKUP_RESET_FLAGS);
}