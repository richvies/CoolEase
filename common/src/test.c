/**
 ******************************************************************************
 * @file    testing.c
 * @author  Richard Davies
 * @date    26/Dec/2020
 * @brief   Testing Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <common/test.h>

#include <string.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/lptimer.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/crc.h>

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/bootloader_utils.h"
#include "common/memory.h"
#include "common/log.h"
#include "common/reset.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/timers.h"

/** @addtogroup TEST_FILE 
 * @{
 */

/** @addtogroup TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Utils
/*////////////////////////////////////////////////////////////////////////////*/

void test_init(const char *test_name)
{
	for (uint32_t i = 0; i < 10000; i++)
	{
		__asm__("nop");
	}

	serial_printf("%s\n------------------\n\n", test_name);
}


void print_aes_key(app_info_t *info)
{
	serial_printf("AES Key:");
	for (uint8_t i = 0; i < 16; i++)
	{
		serial_printf(" %2x", info->aes_key[i]);
	}
	serial_printf("\n");
}

/*////////////////////////////////////////////////////////////////////////////*/
// Memory tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_mem_write_read(void)
{
	test_init("test_mem_write_read()");

	uint32_t eeprom_address = EEPROM_END - EEPROM_PAGE_SIZE;
	uint32_t eeprom_word = 0x12345678;

	uint32_t flash_address = FLASH_END - FLASH_PAGE_SIZE;
	uint32_t *flash_data = (uint32_t *)malloc(16);
	flash_data[0] = 0x12345678;
	flash_data[1] = 0x24681234;

	serial_printf("EEPROM Start: %08x : %08x\n", eeprom_address, MMIO32(eeprom_address));
	serial_printf("Programming: %08x\n", eeprom_word);
	mem_eeprom_write_word(eeprom_address, eeprom_word);
	serial_printf("EEPROM End: %08x : %08x\n\n", eeprom_address, MMIO32(eeprom_address));

	serial_printf("Flash Erase\n");
	mem_flash_erase_page(flash_address);
	serial_printf("Flash Start: %08x : %08x\n%08x : %08x\n", flash_address, MMIO32(flash_address), flash_address + 4, MMIO32(flash_address + 4));
	serial_printf("Programming %08x %08x\n", flash_data[0], flash_data[1]);
	mem_flash_write_half_page(flash_address, flash_data);
	// serial_printf("Programming %08x\n", flash_data[1]); mem_flash_write_word(flash_address, flash_data[1]);
	serial_printf("Flash End: %08x : %08x\n%08x : %08x\n", flash_address, MMIO32(flash_address), flash_address + 4, MMIO32(flash_address + 4));
}

void test_eeprom(void)
{
	test_init("test_eeprom()");

	rcc_periph_clock_enable(RCC_MIF);

	for (;;)
	{
		serial_printf("Device: %04x\n", mem_get_dev_num());
		serial_printf("Message: %04x\n", mem_get_msg_num());

		// mem_update_msg_num(mem_get_msg_num() + 1);

		timers_delay_milliseconds(500);
	}
}

void test_eeprom_read(void)
{
	test_init("test_eeprom_read()");

	serial_printf("Bytes\n---------------------\n");

	for (uint32_t i = EEPROM_START; i < EEPROM_END; i++)
	{
		serial_printf("%2x", MMIO8(i));
	}

	serial_printf("\n----------------------------\nChars\n---------------------\n");

	for (uint32_t i = EEPROM_START; i < EEPROM_END; i++)
	{
		serial_printf("%c", MMIO8(i));
	}
}

void test_eeprom_keys(void)
{
	test_init("test_eeprom_keys()");

	mem_init();

	uint8_t aes_key[16];
	for (int i = 0; i < 16; i++)
	{
		aes_key[i] = i;
	}
	mem_set_aes_key(aes_key);

	uint8_t aes_key_exp[176];
	mem_get_aes_key_exp(aes_key_exp);

	serial_printf("AES Key: ");
	for (int i = 0; i < 16; i++)
	{
		serial_printf("%02x ", aes_key[i]);
	}

	serial_printf("\n\nAES Key Exp: ");
	for (int i = 0; i < 176; i++)
	{
		serial_printf("%02x ", aes_key_exp[i]);
	}

	// aes_expand_key();
	mem_get_aes_key_exp(aes_key_exp);

	serial_printf("\n\nAES Key Exp: ");
	for (int i = 0; i < 176; i++)
	{
		serial_printf("%02x ", aes_key_exp[i]);
	}
}

void test_eeprom_wipe(void)
{
	test_init("test_eeprom_wipe()");

	rcc_periph_clock_enable(RCC_MIF);

	int address = 0x08080000;

	while (address < 0x080807FF)
	{
		serial_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	address = 0x08080000;

	while (address < 0x080807FF)
	{
		eeprom_program_word(address, 0x00);
		address += 4;
	}

	address = 0x08080000;

	while (address < 0x080807FF)
	{
		serial_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	serial_printf("Done\n");
}

void test_reset_eeprom(void)
{
	test_init("test_reset_eeprom()");

	rcc_periph_clock_enable(RCC_MIF);
	eeprom_program_word(0x08080000, 0);
	eeprom_program_word(0x08080004, 6);
	eeprom_program_word(0x08080008, 2);
	eeprom_program_word(0x0808000C, 0);

	serial_printf("%04x : %i\n", 0x08080000, MMIO32(0x08080000));
	serial_printf("%04x : %i\n", 0x08080004, MMIO32(0x08080004));
	serial_printf("%04x : %i\n", 0x08080008, MMIO32(0x08080008));
	serial_printf("%04x : %i\n", 0x0808000C, MMIO32(0x0808000C));
	serial_printf("Done\n");
}

void test_log(void)
{
	test_init("test_log()");

	serial_printf("Wiping Log\n");
	log_erase();
	serial_printf("Writing Log\n");
	for (uint16_t i = 0; i < 10; i++)
	{
		log_printf("Test %i\n", i);
	}
	log_read_reset();
	serial_printf("\nPrinting Log\n\n");
	for (uint16_t i = 0; i < log_size(); i++)
	{
		serial_printf("%c", log_read());
	}
}

void test_bkp_reg(void)
{
	for (uint8_t i = 0; i < 5; i++)
	{
		mem_program_bkp_reg(i, i+7);

		serial_printf("BKP %u : %u\n", i, mem_read_bkp_reg(i));
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// Bootloader util tests
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Test jumping to user defined address
 * 
 * @ref boot_jump_to_application() 
 * Updates VTOR, stack pointer and calls fn(address+4) i.e.reset handler()
 */
void test_boot_jump_to_application(uint32_t address)
{
	test_init("test_boot_jump_to_application()");

	serial_printf("Address: %8x\n", address);
	boot_jump_to_application(address);
}

void test_boot_verify_checksum(void)
{
	test_init("test_boot_verify_checksum()");

	uint32_t data[] = {
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
		0x12345678,
		0x24681357,
	};

	uint32_t expected = 0x55484138;

	if (boot_verify_checksum(data, sizeof(data) / sizeof(uint32_t), expected))
	{
		serial_printf("Checksum Good\n");
	}
	else
	{
		serial_printf("Checksum Bad\n");
	}
}

void test_crc(void)
{
	test_init("test_crc()");

	/** To work with zlib needs byte reversed input and reversed inverse output 
	 * Also zlib can work on bytes but stm32 only on 32 bits so need to pad zlib 
	 * data with zeros to keep crc same
	 */
	// Init: 0xFFFFFFFF Rev In Byte Out Enable != 0XE9910FAE  //matches zlib normal
	// Init: 0x00000000 Rev In Byte Out Enable != 0X734C2F38  //matches zlib 0xFFFFFFFF

	// Initialize CRC Peripheral
	rcc_periph_clock_enable(RCC_CRC);

	// data = ['0x12', '0x34', '0x56', '0x78'] in Python
	uint32_t data[2] = {0x12345678, 0x24681357};
	uint32_t res;
	int i;

	// uint32_t data2[16] = {0X03020100, 0X07060504};
	uint32_t data2[16] = {0x03020100, 0x07060504, 0x0B0A0908, 0x0F0E0D0C, 0x13121110, 0x17161514, 0x1B1A1918, 0x1F1E1D1C, 0x23222120, 0x27262524, 0x2B2A2928, 0x2F2E2D2C, 0x33323130, 0x37363534, 0x3B3A3938, 0x3F3E3D3C};
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
	crc_reverse_output_enable();
	for (i = 0; i < 16; i++)
	{
		CRC_DR = data2[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Byte Out Enable = %8x != %8x\n\n\n", CRC_DR, ~CRC_DR);

	// Test 1
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_NONE);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In None Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 2
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_NONE);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In None Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 3
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Byte Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 4
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Byte Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 5
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_HALF);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Half Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 6
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_HALF);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Half Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 7
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_WORD);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Word Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 8
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_WORD);
	crc_reverse_output_disable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Word Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 9
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_NONE);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In None Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 10
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_NONE);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In None Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 11
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Byte Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 12
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Byte Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 13
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_HALF);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Half Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 14
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_HALF);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Half Out Enable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 15
	crc_reset();
	CRC_INIT = 0xFFFFFFFF;
	crc_set_reverse_input(CRC_CR_REV_IN_WORD);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0xFFFFFFFF Rev In Word Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Test 16
	crc_reset();
	CRC_INIT = 0x00000000;
	crc_set_reverse_input(CRC_CR_REV_IN_WORD);
	crc_reverse_output_enable();
	for (i = 0; i < 2; i++)
	{
		CRC_DR = data[i];
	};
	serial_printf("Init: 0x00000000 Rev In Word Out Disable = %8x != %8x\n", CRC_DR, ~CRC_DR);

	// Deinit
	crc_reset();
	rcc_periph_clock_disable(RCC_CRC);
}

/*////////////////////////////////////////////////////////////////////////////*/
// RFM tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_rf(void)
{
	test_init("test_rf()");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);

	rfm_packet_t *packet_received;
	rfm_packet_t packet;

	strcpy((char *)packet.data.buffer, "Hello 123456789");

	serial_printf("Message: %s\n", packet.data.buffer);

	for (;;)
	{
		rfm_transmit_packet(packet);
		serial_printf("Sent\n");

		rfm_start_listening();
		for (int i = 0; i < 300000; i++)
		{
			__asm__("nop");
		}
		if (rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			serial_printf("Packet Received: %s\n", packet_received->data.buffer);

			serial_printf("\n");
		}

		for (int i = 0; i < 300000; i++)
		{
			__asm__("nop");
		}
	}
}

void test_rf_listen(void)
{
	test_init("test_rf_listen()");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	rfm_packet_t *packet_received;

	for (;;)
	{
		if (rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			serial_printf("Packet Received\n");

			for (int i = 0; i < RFM_PACKET_LENGTH; i++)
				serial_printf("%02x, ", packet_received->data.buffer[i]);

			serial_printf("\n");
		}

		for (int i = 0; i < 300000; i++)
			__asm__("nop");
	}
}

void test_rfm(void)
{
	test_init("test_rfm()");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, -5);
	rfm_set_tx_continuous();
}

/*////////////////////////////////////////////////////////////////////////////*/
// Timer tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_rtc(void)
{
	test_init("test_rtc()");
	timers_rtc_init();
	timers_delay_milliseconds(3000);
	PRINT_REG(RTC_TR);
	PRINT_REG(RTC_DR);
	// timers_rtc_set_time(94, 6, 24, 8, 40, 30);

	uint8_t i = 1;

	for (;;)
	{
		timers_rtc_set_time(94, 6, ((i * 4) % 30), 8, 40, 30);
		PRINT_REG(RTC_TR);
		PRINT_REG(RTC_DR);
		timers_delay_milliseconds(3000);
		PRINT_REG(RTC_TR);
		PRINT_REG(RTC_DR);

		i++;

		serial_printf("\n\n");
	}
}

void test_rtc_wakeup(void)
{
	test_init("test_rtc_wakeup()");

	timers_rtc_init();
	timers_rtc_set_time(1, 1, 1, 1, 1, 1);
	timers_set_wakeup_time(5);

	for (;;)
	{
		while (!(RTC_ISR & RTC_ISR_WUTF))
		{
		}

		timers_clear_wakeup_flag();
		
		serial_printf("Wakeup\n");
	}
}

void test_lptim(void)
{
	test_init("test_lptim()");

	timers_lptim_init();

	for (;;)
	{
		serial_printf("Counter : %u %u %u\n", lptimer_get_counter(LPTIM1), timers_micros(), timers_millis());
	}
}

void test_micros(void)
{
	test_init("test_micros()");

	timers_lptim_init();

	for (;;)
	{
		timers_delay_microseconds(1000000);

		serial_printf("L\n");
	}
}

void test_millis(void)
{
	test_init("test_millis()");

	timers_lptim_init();

	for (;;)
	{
		timers_delay_milliseconds(1000);

		serial_printf("L\n");
	}
}

void test_tim6(void)
{
	test_init("test_tim6()");

	timers_tim6_init();

	for (;;)
	{
		serial_printf("Count %u\n", (uint16_t)timer_get_counter(TIM6));

		serial_printf("L\n");
	}
}

void test_wakeup(void)
{
	test_init("test_wakeup()");

	reset_print_cause();

	batt_init();
	batt_update_voltages();

	serial_printf("Battery = %uV\n", batt_get_batt_voltage());
	serial_printf("Power = %uV\n", batt_get_pwr_voltage());
}

bool test_timers_timeout(void)
{
	test_init("test_timeout()");

	timers_timeout_init();

	// TIMEOUT(test_func(90), 5000000);
	// WAIT_US(test_func(90), 65000);
	// WAIT_MS(test_func(90), 1000);

	while (!timers_timeout(4094967296, "TEST", 0))
	{
		timers_delay_microseconds(1);
	}

	return true;
}

/*////////////////////////////////////////////////////////////////////////////*/
// Low Power tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_standby(uint32_t standby_time)
{
	test_init("test_standby()");

	serial_printf("%i seconds\n", standby_time);

	timers_rtc_init();
	timers_rtc_set_time(1, 1, 1, 1, 1, 1);
	timers_set_wakeup_time(standby_time);
	timers_enable_wut_interrupt();

	rfm_init();
	rfm_end();

	serial_printf("Entering Standby\n");
	timers_enter_standby();
}

void test_voltage_scale(uint8_t scale)
{
	test_init("test_voltage_scale()");

	rfm_init();
	rfm_end();

	// #ifdef _HUB
	// sim_init();
	// sim_end();

	// #else
	// // tmp112_init();
	// // tmp112_end();
	// #endif

	serial_printf("Testing Voltage Scaling\n");
	serial_printf("Current Scaling: %08x\n", PWR_CR);

	batt_set_voltage_scale(scale);

	serial_printf("New Scaling: %08x\n", PWR_CR);

	for (;;)
	{
		for (int i = 0; i < 1000000; i++)
		{
			__asm__("nop");
		}
	}
}

void test_low_power_run(void)
{
	test_init("test_low_power_run()");

	rfm_init();
	rfm_end();

	// #ifdef _HUB
	// sim_init();
	// sim_end();

	// #else
	// // tmp112_init();
	// // tmp112_end();
	// #endif

	serial_printf("Testing Low Power Run\n");

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);

	batt_set_low_power_run();

	for (;;)
	{
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// Battery
/*////////////////////////////////////////////////////////////////////////////*/

void test_batt_update_voltages(void)
{
	test_init("test_adc_voltages()");

	for (;;)
	{
		batt_update_voltages();

		serial_printf("Battery = %uV\n", batt_get_batt_voltage());
		serial_printf("Power = %uV\n", batt_get_batt_voltage());

		timers_delay_milliseconds(1000);
	}
}

void test_batt_interrupt(void)
{
	test_init("test_adc_voltages()");

	batt_enable_interrupt();

	for (;;)
	{
		serial_printf("Battery = %uV\n", batt_get_batt_voltage());
		serial_printf("Power = %uV\n", batt_get_batt_voltage());

		timers_delay_milliseconds(1000);
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// Other tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_encryption(uint8_t *key)
{
	test_init("test_encryption()");

	serial_printf("Key: ");
	for (uint8_t i = 0; i < 16; i++)
	{
		serial_printf("%2x ", key[i]);
	}
	serial_printf("\n");

	aes_init(key);

	uint8_t data[16] = "Hello There 123";
	serial_printf("Raw: %s\n", data);

	aes_ecb_encrypt(data);
	serial_printf("Enc: %s\n", data);

	aes_ecb_decrypt(data);
	serial_printf("Dec: %s\n", data);
}

void test_analog_watchdog(void)
{
	test_init("test_analog_watchdog()");

	batt_enable_interrupt();
	// batt_enable_comp();

	for (;;)
	{
		__asm__("nop");
	}
}

// Init: 0xFFFFFFFF Rev In None Out Disable = 0X4E780056 != 0XB187FFA9
// Init: 0x00000000 Rev In None Out Disable = 0X277CBB0F != 0XD88344F0
// Init: 0xFFFFFFFF Rev In Byte Out Disable = 0X8A0F7668 != 0X75F08997
// Init: 0x00000000 Rev In Byte Out Disable = 0XE30BCD31 != 0X1CF432CE
// Init: 0xFFFFFFFF Rev In Half Out Disable = 0X357FD5D1 != 0XCA802A2E
// Init: 0x00000000 Rev In Half Out Disable = 0X5C7B6E88 != 0XA3849177
// Init: 0xFFFFFFFF Rev In Word Out Disable = 0XD41BDC9F != 0X2BE42360
// Init: 0x00000000 Rev In Word Out Disable = 0XBD1F67C6 != 0X42E09839
// Init: 0xFFFFFFFF Rev In None Out Enable = 0X6A001E72 != 0X95FFE18D
// Init: 0x00000000 Rev In None Out Enable = 0XF0DD3EE4 != 0X0F22C11B
// Init: 0xFFFFFFFF Rev In Byte Out Enable = 0X166EF051 != 0XE9910FAE
// Init: 0x00000000 Rev In Byte Out Enable = 0X8CB3D0C7 != 0X734C2F38
// Init: 0xFFFFFFFF Rev In Half Out Enable = 0X8BABFEAC != 0X74540153
// Init: 0x00000000 Rev In Half Out Enable = 0X1176DE3A != 0XEE8921C5
// Init: 0xFFFFFFFF Rev In Word Out Disable = 0XF93BD82B != 0X06C427D4
// Init: 0x00000000 Rev In Word Out Disable = 0X63E6F8BD != 0X9C190742

void test_spf_tx(void)
{
	test_init("test_spf_tx()");

	while (1)
	{
		serial_printf("Testing\n");
		for (uint32_t i = 0; i < 1000000; i++)
		{
			serial_printf("hello int %i\n", i);
		}
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// Interrupts
/*////////////////////////////////////////////////////////////////////////////*/

void nmi_handler(void)
{
	log_printf("nmi\n");
	while (1)
	{
	}
}

void hard_fault_handler(void)
{
	log_printf("hard fault\n");
	while (1)
	{
	}
}

/** @} */
/** @} */