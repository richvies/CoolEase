#include <stdlib.h>
#include <string.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/dma.h>

#include <tinyAES/aes.h>
#include "coolease/encryption.h"
#include "coolease/serial_printf.h"

static uint8_t key[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
struct AES_ctx ctx;

static uint32_t seed = 0;
static uint8_t adc_vals[4] = {0, 0, 0, 0};
static uint8_t adc_channels[4] = {0, 1, 8, 9};

/**
 * crypt_init
 * 
 * Seed random generator
 * Initialize AES context
*/
void crypt_init(void)
{
    crypt_update_random_seed();
    AES_init_ctx(&ctx, key);
}

/**
 * PA0 - CH0
 * PA1 - CH1
 * PB0 - CH8
 * PB1 - CH9
 */
void crypt_update_random_seed(void)
{
    for(int i = 0; i < 4; i++)
        seed |= adc_vals[i] << (8 * i);

    /* 
    spf_serial_printf("Before\nFirst: %08x \n", adc_vals[0]);
    spf_serial_printf("Second: %08x \n", adc_vals[1]);
    spf_serial_printf("Third: %08x \n", adc_vals[2]);
    spf_serial_printf("Fourth: %08x \n", adc_vals[3]);
    spf_serial_printf("Seed: %08x\n", seed);
    */

    rcc_periph_clock_enable(RCC_ADC1);
    adc_power_off(ADC1);
    rcc_periph_reset_pulse(RST_ADC1);
    adc_enable_dma(ADC1);
    rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV8);
    adc_enable_scan_mode(ADC1);
    adc_set_single_conversion_mode(ADC1);
    adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_1DOT5CYC);
    adc_enable_external_trigger_regular(ADC1, ADC_CR2_EXTSEL_SWSTART);
    adc_power_on(ADC1);

    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_ANALOG, GPIO0 | GPIO1);
    gpio_set_mode(GPIOB, GPIO_MODE_INPUT, GPIO_CNF_INPUT_ANALOG, GPIO0 | GPIO1);

    rcc_periph_clock_enable(RCC_DMA1);
    dma_channel_reset(DMA1, DMA_CHANNEL1);
    dma_set_read_from_peripheral(DMA1, DMA_CHANNEL1);
    dma_set_number_of_data(DMA1, DMA_CHANNEL1, 4);
    dma_set_priority(DMA1, DMA_CHANNEL1, DMA_CCR_PL_VERY_HIGH);

    dma_set_peripheral_address(DMA1, DMA_CHANNEL1, (uint32_t)&ADC1_DR);
    dma_set_peripheral_size(DMA1, DMA_CHANNEL1, DMA_CCR_PSIZE_32BIT);
    dma_disable_peripheral_increment_mode(DMA1, DMA_CHANNEL1);

    dma_set_memory_address(DMA1, DMA_CHANNEL1, (uint32_t)adc_vals);
    dma_set_memory_size(DMA1, DMA_CHANNEL1, DMA_CCR_PSIZE_8BIT);
    dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL1);

    dma_enable_channel(DMA1, DMA_CHANNEL1);


    for(int i = 0; i < 1000; i++) __asm__("nop");

    adc_set_regular_sequence(ADC1, 4, adc_channels);
    adc_start_conversion_regular(ADC1);
    while (!dma_get_interrupt_flag(DMA1, DMA_CHANNEL1, DMA_TCIF | DMA_TEIF));

    dma_channel_reset(DMA1, DMA_CHANNEL1);

    for(int i = 0; i < 4; i++)
        seed |= adc_vals[i] << (8 * i);

    /*  
    spf_serial_printf("After\nFirst: %08x \n", adc_vals[0]);
    spf_serial_printf("Second: %08x \n", adc_vals[1]);
    spf_serial_printf("Third: %08x \n", adc_vals[2]);
    spf_serial_printf("Fourth: %08x \n", adc_vals[3]);
    spf_serial_printf("Seed: %08x\n\n", seed);
    */

    srand(seed);

    seed = 0;
    for(int i = 0; i < 4; i++)
        adc_vals[i] = 0;

    adc_power_off(ADC1);
    rcc_periph_clock_disable(RCC_ADC1);

    rcc_periph_clock_disable(RCC_DMA1);
}

/**
 * crypt_encrypt_message
 * 
 * Take message and convert to 16 byte encrypted packet
 * Message 5 bytes long, rest is random
 * B0 - Group #
 * B1 - Dev #
 * B2 - Ver #
 * B3 - Mesage #
 * B3 - V Batt
 * B4 - Temp
 */
void crypt_encrypt_message(uint8_t (*message), uint8_t (*cpiher_text))
{
    for (int i = 0; i < 5; i++)
    {
        cpiher_text[i] = message[i];
        message[i] = 0;
    }
    
    for (int i = 5; i < 16; i++)
        cpiher_text[i] = rand()%256;

    AES_ECB_encrypt(&ctx, cpiher_text);
}

/**
 * crypt_decrypt_message
 * 
 * Take cipher text and convert to 5 message
 * Cipher text 16 bytes long
 * B0 - Group #
 * B1 - Dev #
 * B2 - Ver #
 * B3 - Mesage #
 * B3 - V Batt
 * B4 - Temp
 */
void crypt_decrypt_message(uint8_t (*cipher_text), uint8_t (*message))
{
    AES_ECB_decrypt(&ctx, cipher_text);

    for(int i = 0; i < 5; i++)
        message[i] = cipher_text[i];

    for(int i = 0; i < 16; i++)
        cipher_text[i] = 0;
}




// Monocypher Implementation
/*void encrypt_message(uint8_t* plain_text, uint8_t* cipher_text, uint8_t* message)
{
    srand(rand());
    for(int i = 0; i < 32; i++)
    {
        key[i] = rand()%255;
    }
    for(int i = 0; i < 24; i++)
    {
        nonce[i] = rand()%255;
    }

    crypto_lock(mac, cipher_text, key, nonce, plain_text, 10);

    memmove(message, cipher_text, 10);
    memmove(message+10, mac, 16);
    memmove(message+10+16, nonce, 24);

    crypto_wipe(plain_text, 10);
    crypto_wipe(mac, 16);
    crypto_wipe(nonce, 24);
}

int decrypt_message(uint8_t* plain_text, uint8_t* cipher_text, uint8_t* message)
{
    memcpy(cipher_text, message, 10);
    memcpy(mac, message+10, 16);
    memcpy(nonce, message+10+16, 24);

    if(crypto_unlock(plain_text, key, nonce, mac, cipher_text, 10))
        return -1;
    return 0;
}*/