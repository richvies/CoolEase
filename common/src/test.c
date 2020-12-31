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
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/lptimer.h>
#include <libopencm3/stm32/pwr.h>
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

/** @addtogroup TEST_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */

/** @addtogroup TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Memory tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_mem_write_read(void)
{
    uint32_t eeprom_address = EEPROM_END - EEPROM_PAGE_SIZE;
    uint32_t eeprom_word    = 0x12345678;

    uint32_t flash_address = FLASH_END - FLASH_PAGE_SIZE;
    uint32_t *flash_data   = (uint32_t*)malloc(64); 
    flash_data[0] = 0x12345678;
    flash_data[1] = 0x24681234;

    log_printf("Test Mem Write Read\n\n");

    log_printf("EEPROM Start: %08x : %08x\n", eeprom_address, MMIO32(eeprom_address));
    log_printf("Programming: %08x\n", eeprom_word); mem_eeprom_write_word(eeprom_address, eeprom_word);
    log_printf("EEPROM End: %08x : %08x\n\n", eeprom_address, MMIO32(eeprom_address));

    log_printf("Flash Erase\n"); mem_flash_erase_page(flash_address);
    log_printf("Flash Start: %08x : %08x\n%08x : %08x\n", flash_address, MMIO32(flash_address), flash_address+4, MMIO32(flash_address+4));
    log_printf("Programming %08x %08x\n", flash_data[0], flash_data[1]); mem_flash_write_half_page(flash_address, flash_data);
    // log_printf("Programming %08x\n", flash_data[1]); mem_flash_write_word(flash_address, flash_data[1]);
    log_printf("Flash End: %08x : %08x\n%08x : %08x\n", flash_address, MMIO32(flash_address), flash_address+4, MMIO32(flash_address+4));
}

/*////////////////////////////////////////////////////////////////////////////*/
// Bootloader utils tests
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Test jumping to user defined address
 * 
 * @ref boot_jump_to_application() 
 * Updates VTOR, stack pointer and calls fn(address+4) i.e.reset handler()
 */
void test_boot_jump_to_application(uint32_t address)
{
	log_printf("test_boot_jump_to_application\n");
	log_printf("Address: %8x\n", address);
    boot_jump_to_application(address);
}

void test_boot_verify_checksum(void)
{
	log_printf("test_boot_verify_checksum\n");

	uint32_t data[16] = {
		0x12345678, 0x24681357, 0x12345678, 0x24681357,
		0x12345678, 0x24681357, 0x12345678, 0x24681357,
		0x12345678, 0x24681357, 0x12345678, 0x24681357,
		0x12345678, 0x24681357, 0x12345678, 0x24681357,
	};

	uint32_t expected = 0xB63CFBCD;

	if (boot_verify_checksum(data, 1, expected))
	{
		log_printf("Checksum Good\n");
	}
	else
	{
		log_printf("Checksum Bad\n");
	}
}

void test_boot_crc(void)
{
	// Initialize CRC Peripheral
    rcc_periph_clock_enable(RCC_CRC);
    crc_reset();
	CRC_INIT = 0xFFFFFFFF;

    crc_reverse_output_enable();
    crc_set_reverse_input(CRC_CR_REV_IN_WORD);


	serial_printf("Checksum initial: %8x\n", CRC_DR);
	serial_printf("CR: %8x\n", CRC_CR);
	serial_printf("INT: %8x\n", CRC_INIT);
	serial_printf("POL: %8x\n", CRC_POL);

	// uint8_t data[4] = {'h', 'e', 'l', 'l'};
	uint32_t data[1] = {'T'};

    // Calc CRC32
    int i;
  
    for (i = 0; i < 1; i++) 
	{
    	CRC_DR = data[i];
    }

    uint32_t crc = 0xf0;
	uint32_t not_crc = (crc ^ 0xFFFFFFFF);

	serial_printf("%i\n", crc); serial_printf("%8x\n", crc); serial_printf("%32b\n", crc);
	serial_printf("%i\n", not_crc); 
	serial_printf("%8x\n", not_crc); serial_printf("%32b\n", not_crc);

    // Deinit
    crc_reset();
    rcc_periph_clock_disable(RCC_CRC);

    serial_printf("Checksum value: %8x %8x %8x %8x\n", crc, not_crc, 0x01, ~0x01);
}


void flash_led(uint16_t milliseconds, uint8_t num_flashes)
{
	gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED);
	gpio_clear(LED_PORT, LED);
	for(uint8_t i = 0; i < num_flashes; i++)
	{
		gpio_set(LED_PORT, LED);
		timers_delay_milliseconds(milliseconds / 4);
		gpio_clear(LED_PORT, LED);
		timers_delay_milliseconds(3 * milliseconds / 4);
	}
}

void test_wakeup(void)
{
	log_printf("Reset\n");
	reset_print_cause();
	
	batt_init();
	batt_update_voltages();

	log_printf("Battery = %uV\n", batt_voltages[BATT_VOLTAGE]);
	#ifdef _HUB
	log_printf("Power = %uV\n", batt_voltages[PWR_VOLTAGE]);
	#endif
}

void test_standby(uint32_t standby_time)
{
	log_printf("Testing Standby for %i seconds\n", standby_time);

	timers_rtc_init(standby_time);

	// rfm_init();
	// rfm_end();

	// tmp112_init();
	// tmp112_end();

	// #ifdef _HUB
	// sim_init();
	// sim_reset_hold();
	// #endif

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);
	
	log_printf("Entering Standby\n");
	timers_enter_standby();
}

void test_rf(void)
{
	log_printf("Testing RF\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);

    rfm_packet_t *packet_received;
    rfm_packet_t packet_send;

	char msg[16] = {'H', 'E', 'L', 'L', '0', '\n', 0};

	packet_send.data.buffer[0] = msg[0];

    for (;;)
	{
		rfm_transmit_packet(packet_send);
		log_printf("Sent\n");

		rfm_start_listening();
		for (int i = 0; i < 300000; i++) __asm__("nop");
		if(rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			log_printf("%i us\n", (uint16_t)(timer2 - timer));

			log_printf("Packet Received\n");

			for(int i = 0; i < RFM_PACKET_LENGTH; i++)
				log_printf("%02x, ", packet_received->data.buffer[i]);

			log_printf("\n");
		}

		for (int i = 0; i < 300000; i++) __asm__("nop");
	}
}

void test_rf_listen(void)
{
	log_printf("Testing RF Listen\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

    rfm_packet_t *packet_received;

    for (;;)
	{
		if(rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			log_printf("%i us\n", (uint16_t)(timer2 - timer));

			log_printf("Packet Received\n");

			for(int i = 0; i < RFM_PACKET_LENGTH; i++)
				log_printf("%02x, ", packet_received->data.buffer[i]);

			log_printf("\n");
		}

		for (int i = 0; i < 300000; i++) __asm__("nop");
	}
}

void test_receiver(uint32_t dev_num)
{
	log_printf("Testing Receiver\n");

	// Sensors
	num_sensors = 3;
	sensors[0].dev_num = dev_num;
	sensors[1].dev_num = 0x12345678;
	sensors[2].dev_num = 0x87654321;

	sensor_t *sensor = NULL;

	// Start listening on rfm
	rfm_packet_t *packet = NULL;
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	// Get First message number
	log_printf("Waiting for first message\n");
	bool recv = false;
	while(!recv)
	{
		// Wait for first packet to arrive
		while(!rfm_get_num_packets());

		// Get packet, decrypt and organise
		packet = rfm_get_next_packet();
		aes_ecb_decrypt(packet->data.buffer);
		rfm_organize_packet(packet);

		// Print data received
		log_printf("Received "); for(int i = 0; i < 16; i++){log_printf("%02X ", packet->data.buffer[i]);} log_printf("\n");

		// Skip if not correct device number
		sensor = get_sensor(packet->data.device_number);
		if(sensor == NULL)
		{
			log_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
			continue;
		}
		else
		{
			sensor->msg_num 		= packet->data.msg_number;
			sensor->msg_num_start 	= packet->data.msg_number;
			log_printf("First Message Number: %i %i\n", packet->data.msg_number, sensor->msg_num);
			recv = true;
		}
	}

	log_printf("Ready\n");

	for(;;)
	{
		if(rfm_get_num_packets())
		{
			while(rfm_get_num_packets())
			{
				// Get packet, decrypt and organise
				packet = rfm_get_next_packet();
				aes_ecb_decrypt(packet->data.buffer);
				rfm_organize_packet(packet);

				// Check CRC
				if( !packet->crc_ok )
				{
					log_printf("CRC Fail\n");
					flash_led(100, 5);
					continue;
				}
				else
				{
					log_printf("CRC OK\n");
				}

				// Get sensor from device number
				sensor = get_sensor(packet->data.device_number);

				// Skip if wrong device number
				if(sensor == NULL)
				{
					log_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
					flash_led(100, 3);
					continue;
				}

				// Update sensor ok packet counter
				sensor->ok_packets++;
				flash_led(100, 1);

				// Check if message number is correct
				if(packet->data.msg_number != ++sensor->msg_num)
				{
					log_printf("Missed Message %i\n", sensor->msg_num);
				}

				sensor->total_packets = packet->data.msg_number - sensor->msg_num_start;

				// Print packet details
				log_printf("Device ID: %08x\n", packet->data.device_number);
				log_printf("Packet RSSI: %i dbm\n", packet->rssi);
				log_printf("Packet SNR: %i dB\n", packet->snr);
				log_printf("Power: %i\n", packet->data.power);
				log_printf("Battery: %uV\n", packet->data.battery);
				log_printf("Temperature: %i\n", packet->data.temperature);
				log_printf("Message Number: %i\n", packet->data.msg_number);
				log_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);
			}
		}
	}	
}

void test_voltage_scale(uint8_t scale)
{
	log_printf("Testing Voltage Scale\n");

	rfm_init();
	rfm_end();

	// #ifdef _HUB
	// sim_init();
	// sim_end();

	// #else
	// // tmp112_init();
	// // tmp112_end();
	// #endif


	log_printf("Testing Voltage Scaling\n");
	log_printf("Current Scaling: %08x\n", PWR_CR);

	batt_set_voltage_scale(scale);

	log_printf("New Scaling: %08x\n", PWR_CR);

	for (;;)
	{
		for(int i = 0; i < 1000000; i++){__asm__("nop");}
	}
}

void test_low_power_run(void)
{
	log_printf("Testing LP Run\n");

	rfm_init();
	rfm_end();

	// #ifdef _HUB
	// sim_init();
	// sim_end();

	// #else
	// // tmp112_init();
	// // tmp112_end();
	// #endif

	log_printf("Testing Low Power Run\n");

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);

	batt_set_low_power_run();

	for (;;)
	{
	}
}

void test_eeprom(void)
{
	log_printf("Testing EEPROM\n");

	rcc_periph_clock_enable(RCC_MIF);

	for(;;)
	{
		log_printf("Device: %04x\n", mem_get_dev_num());
		log_printf("Message: %04x\n", mem_get_msg_num());

		// mem_update_msg_num(mem_get_msg_num() + 1);

		timers_delay_milliseconds(500);
	}
}

void test_eeprom_keys(void)
{
	log_printf("Testing EEPROM Encryption Keys\n");

	mem_init();

	uint8_t aes_key[16];
	for(int i = 0; i < 16; i++)
	{
		aes_key[i] = i;
	}
	mem_set_aes_key(aes_key);

	uint8_t aes_key_exp[176];
	mem_get_aes_key_exp(aes_key_exp);


	log_printf("AES Key: ");
	for(int i = 0; i < 16; i++){log_printf("%02x ", aes_key[i]);}

	log_printf("\n\nAES Key Exp: ");
	for(int i = 0; i < 176; i++){log_printf("%02x ", aes_key_exp[i]);}

	aes_expand_key();
	mem_get_aes_key_exp(aes_key_exp);

	log_printf("\n\nAES Key Exp: ");
	for(int i = 0; i < 176; i++){log_printf("%02x ", aes_key_exp[i]);}
}

void test_eeprom_wipe(void)
{
	log_printf("Testing EEPROM Wipe\n");

	rcc_periph_clock_enable(RCC_MIF);

	int address = 0x08080000;

	while(address <  0x080807FF)
	{
		log_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	address = 0x08080000;

	while(address <  0x080807FF)
	{
		eeprom_program_word(address, 0x00);
		address += 4;
	}

	address = 0x08080000;

	while(address <  0x080807FF)
	{
		log_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	log_printf("Done\n");
}

void test_lptim(void)
{
	log_printf("Testing LP Timer\n");

	timers_lptim_init();

	for(;;)
	{
		log_printf("LPTim Count: %i\n", lptimer_get_counter(LPTIM1));
		for(int i = 0; i < 1000; i++){__asm__("nop");}
	}
}

void test_rfm(void)
{
	log_printf("Testing RFM\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, -5);
	rfm_set_tx_continuous();
}

void test_reset_eeprom(void)
{
	log_printf("Resetting MEM\n");

	rcc_periph_clock_enable(RCC_MIF);
	eeprom_program_word(0x08080000, 0);
	eeprom_program_word(0x08080004, 6);
	eeprom_program_word(0x08080008, 2);
	eeprom_program_word(0x0808000C, 0);

	log_printf("%04x : %i\n", 0x08080000, MMIO32(0x08080000));
	log_printf("%04x : %i\n", 0x08080004, MMIO32(0x08080004));
	log_printf("%04x : %i\n", 0x08080008, MMIO32(0x08080008));
	log_printf("%04x : %i\n", 0x0808000C, MMIO32(0x0808000C));
	log_printf("Done\n");
}

void test_encryption(void)
{
	log_printf("Testing Encryption\n");

	aes_init();
	mem_init();

	uint8_t data[16] = {'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '1', '2', '3', '4', '5'};
	for(int i = 0; i < 16; i++){log_printf("%c ", data[i]);}
	log_printf("\n");

	aes_ecb_encrypt(data);
	for(int i = 0; i < 16; i++){log_printf("%c ", data[i]);}
	log_printf("\n");

	aes_ecb_decrypt(data);
	for(int i = 0; i < 16; i++){log_printf("%c ", data[i]);}
	log_printf("\n");
}

bool test_timeout(void)
{
	log_printf("Testing Timeout\n");
	
	timeout_init();

	// TIMEOUT(test_func(90), 5000000);
	// WAIT_US(test_func(90), 65000);
	// WAIT_MS(test_func(90), 1000);

	while(!timeout(4094967296, "TEST", 0))
	{
		timers_delay_microseconds(1);
	}

	return true;
}

void test_log(void)
{
	log_init();
	log_printf("Testing Log\n");

	for(int i = 0; i < 10; i++)
	{
		log_printf("Number: %i\n", i);
	}

	log_printf("Done\n");

	mem_print_log();
}

void test_analog_watchdog(void)
{
	log_printf("Testing Analog Watchdog\n");
	batt_enable_interrupt();
	// batt_enable_comp();

	for(;;)
	{
		__asm__("nop");
	}
}


/** @} */

/** @addtogroup TEST_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */
/** @} */