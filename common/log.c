/**
 ******************************************************************************
 * @file    log.c
 * @author  Richard Davies
 * @date    30/Dec/2020
 * @brief   Log Source File
 *
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <string.h>

#include "common/log.h"

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>

#include "common/log.h"
#include "common/memory.h"
#include "common/printf.h"
#include "common/timers.h"
#include "config/board_defs.h"

#ifdef COOLEASE_DEVICE_HUB
#include "hub/cusb.h"
#endif

/** @addtogroup LOG_FILE
 * @{
 */

/** @addtogroup LOG_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

// Vars used during normal operation
static uint16_t write_index;
static uint16_t read_index;

#define LOG_SIZE (EEPROM_LOG_SIZE - 8)

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void _putchar_main(char character);
static void _putchar_mem(char character);

#ifdef DEBUG
static void usart_setup(void);
static void usart_end(void);
static void _putchar_spf(char character);
#ifdef COOLEASE_DEVICE_HUB
static void _putchar_usb(char character);
#endif
#endif

/** @} */

/** @addtogroup LOG_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void log_init(void) {
    write_index = log_file->idx % LOG_SIZE;
    read_index = write_index;

#ifdef DEBUG
    usart_setup();
#endif

    serial_printf("\nLog Init\n");
    serial_printf("Log size: %u\n", LOG_SIZE);
    serial_printf("Log idx: %u\n----------------\n", write_index);
}

void log_end(void) {
    // Update write location
    mem_eeprom_write_half_word((uint32_t)&log_file->idx, write_index);

#ifdef DEBUG
    usart_end();
#endif
}

void log_printf(const char* format, ...) {
    va_list va;
    va_start(va, format);
    fnprintf(_putchar_main, format, va);
    va_end(va);
}

void log_error(uint16_t error) {
    log_printf("LError %4x\n", error);
}

uint8_t log_get_byte(uint16_t index) {
    uint8_t byte;

    if (index > LOG_SIZE) {
        byte = 0;
    } else {
        byte = log_file->log[index];
    }

    return byte;
}

uint8_t log_read(void) {
    uint8_t byte;

    read_index = (read_index + 1) % LOG_SIZE;

    if (read_index == write_index) {
        byte = 0;
    } else {
        byte = log_file->log[read_index];
        // serial_printf("Log Reading %8x %c\n", EEPROM_LOG_BASE + read_index,
        // byte);
    }

    return byte;
}

void log_read_reset(void) {
    read_index = write_index;
}

uint16_t log_size(void) {
    return LOG_SIZE;
}

void log_erase(void) {
    serial_printf("Log Erase Start: %8x\n", &(log_file->log[0]));
    for (write_index = 0; write_index < LOG_SIZE; write_index++) {
        mem_eeprom_write_byte((uint32_t)(&(log_file->log[write_index])), 0);
    }

    // Update write location
    write_index = 0;
    mem_eeprom_write_half_word((uint32_t)&log_file->idx, write_index);
}

void log_create_backup(void) {
    log_erase_backup();

    log_read_reset();

    for (uint16_t i = 0; i < log_size(); i += 4) {
        mem_flash_write_word(FLASH_LOG_BKP + i,
                             (log_read() << 0 | log_read() << 8 |
                              log_read() << 16 | log_read() << 24));
    }
}

void log_erase_backup(void) {
    uint32_t address;

    for (address = FLASH_LOG_BKP; address < FLASH_LOG_BKP + EEPROM_LOG_SIZE;
         address += FLASH_PAGE_SIZE) {
        mem_flash_erase_page(address);
    }
}

void print_aes_key(app_info_t* info) {
    serial_printf("AES Key:");
    for (uint8_t i = 0; i < 16; i++) {
        serial_printf(" %2x", info->aes_key[i]);
    }
    serial_printf("\n");
}

/** @} */

/** @addtogroup LOG_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void _putchar_main(char character) {
    _putchar_mem(character);

#ifdef DEBUG
    _putchar_spf(character);
#ifdef COOLEASE_DEVICE_HUB
    _putchar_usb(character);
#endif
#endif
}

static void _putchar_mem(char character) {
    mem_eeprom_write_byte((uint32_t) & (log_file->log[write_index]), character);

    write_index = (write_index + 1) % LOG_SIZE;
}

#ifdef DEBUG

#define SPF_BUFFER_SIZE 64

static char    spf_tx_buf[SPF_BUFFER_SIZE];
static char    spf_rx_buf[SPF_BUFFER_SIZE];
static uint8_t spf_tx_head = 0;
static uint8_t spf_tx_tail = 0;
static uint8_t spf_rx_head = 0;
static uint8_t spf_rx_tail = 0;

static void usart_setup(void) {
    rcc_periph_clock_enable(SPF_USART_RCC);
    rcc_periph_reset_pulse(SPF_USART_RCC_RST);
    usart_disable(SPF_USART);
    usart_set_baudrate(SPF_USART, SPF_USART_BAUD);
    usart_set_databits(SPF_USART, 8);
    usart_set_stopbits(SPF_USART, USART_STOPBITS_1);
    usart_set_mode(SPF_USART, USART_MODE_TX_RX);
    usart_set_parity(SPF_USART, USART_PARITY_NONE);
    usart_set_flow_control(SPF_USART, USART_FLOWCONTROL_NONE);
    usart_enable(SPF_USART);

    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);

    // Set AF first to avoid initial garbage on serial line
    gpio_set_af(SPF_USART_TX_PORT, SPF_USART_AF, SPF_USART_TX);
    gpio_set_af(SPF_USART_RX_PORT, SPF_USART_AF, SPF_USART_RX);

    gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE,
                    SPF_USART_TX);
    gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE,
                    SPF_USART_RX);

    gpio_set_output_options(SPF_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ,
                            SPF_USART_TX);

    usart_enable_rx_interrupt(SPF_USART);

    nvic_clear_pending_irq(SPF_USART_NVIC);
    nvic_set_priority(SPF_USART_NVIC, IRQ_PRIORITY_SPF);
    nvic_enable_irq(SPF_USART_NVIC);
}

static void usart_end(void) {
    nvic_clear_pending_irq(SPF_USART_NVIC);
    nvic_disable_irq(SPF_USART_NVIC);
    usart_disable_rx_interrupt(SPF_USART);

    gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    SPF_USART_RX);
    gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    SPF_USART_TX);

    usart_disable(SPF_USART);
    rcc_periph_reset_pulse(SPF_USART_RCC_RST);
    rcc_periph_clock_disable(SPF_USART_RCC);
}

static void _putchar_spf(char character) {
    bool done = false;

    // send immediatly if tx buffer empty
    if ((spf_tx_head == spf_tx_tail) &&
        usart_get_flag(SPF_USART, USART_ISR_TXE)) {
        usart_send(SPF_USART, character);
        done = true;
    } else {
        while (!done) {
            cm_disable_interrupts();

            uint8_t i = (spf_tx_head + 1) % SPF_BUFFER_SIZE;

            if (i == spf_tx_tail) {
                done = false;
                cm_enable_interrupts();
                timers_delay_milliseconds(1);
            } else {

                spf_tx_buf[spf_tx_head] = character;

                spf_tx_head = i;

                usart_enable_tx_interrupt(SPF_USART);

                done = true;
            }
            cm_enable_interrupts();
        }
    }
}

void serial_printf(const char* format, ...) {
    va_list va;
    va_start(va, format);
    fnprintf(_putchar_spf, format, va);
    va_end(va);
}

bool serial_available(void) {
    return (((spf_rx_head + SPF_BUFFER_SIZE - spf_rx_tail) % SPF_BUFFER_SIZE));
}

char serial_read(void) {
    char c = 0;

    if (serial_available()) {
        c = spf_rx_buf[spf_rx_tail];
        spf_rx_tail = (spf_rx_tail + 1) % SPF_BUFFER_SIZE;
    }

    return c;
}

SPF_ISR() {
    // Received data from serial monitor
    // Read data (clears flag automatically)
    if (usart_get_flag(SPF_USART, USART_ISR_RXNE)) {
        if (((spf_rx_head + 1) % SPF_BUFFER_SIZE) == spf_rx_tail) {
            // Read overflow
            usart_recv(SPF_USART);
        } else {
            spf_rx_buf[spf_rx_head] = usart_recv(SPF_USART);

            // if (spf_rx_buf[spf_rx_head] == '\n')
            // {
            // 	spf_rx_buf[spf_rx_head + 1] = '\0'
            // }

            spf_rx_head = (spf_rx_head + 1) % SPF_BUFFER_SIZE;
        }
    }

    // Transmit buffer empty
    // Fill it (clears flag automatically)
    if (usart_get_flag(SPF_USART, USART_ISR_TXE)) {
        // Fill it if data waiting
        if ((SPF_BUFFER_SIZE + spf_tx_head - spf_tx_tail) % SPF_BUFFER_SIZE) {
            usart_send(SPF_USART, spf_tx_buf[spf_tx_tail]);
            spf_tx_tail = (spf_tx_tail + 1) % SPF_BUFFER_SIZE;
        }
        // Otherwise tranfer is done, disable interrupt (prevent irq firing
        // constantly waiting for TX Data Reg to be filled)
        else {
            usart_disable_tx_interrupt(SPF_USART);
        }
    }
}

#ifdef COOLEASE_DEVICE_HUB
static void _putchar_usb(char character) {
    cusb_send(character);
}
#endif // COOLEASE_DEVICE_HUB
#endif // DEBUG

/** @} */
/** @} */
