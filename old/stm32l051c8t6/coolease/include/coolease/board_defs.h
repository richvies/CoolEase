#ifndef BOARD_DEFS_H
#define BOARD_DEFS_H

// GPIOA
#define GPIO_SPI_NSS       GPIO8
// GPIOB
#define GPIO_SPI_MOSI      GPIO15
#define GPIO_SPI_MISO      GPIO14
#define GPIO_SPI_SCK       GPIO13

// GPIOA
#define GPIO_USART2_TX      GPIO2
#define GPIO_USART2_RX      GPIO3

// GPIOB
#define GPIO_I2C1_SCL       GPIO6
#define GPIO_I2C1_SDA       GPIO7

/**
 * Switch active high
 * Busy active high
 * The max value for TSW from NSS rising edge to the BUSY rising edge is, in all cases, 600 ns.
 * */

// GPIOA
#define GPIO_RF_IO_1        GPIO6
#define GPIO_RF_IO_2        GPIO4
#define GPIO_RF_IO_3        GPIO5
#define GPIO_RF_BUSY        GPIO7
// GPIOB
#define GPIO_RF_TX_SW       GPIO0
#define GPIO_RF_RX_SW       GPIO2
#define GPIO_RF_RESET       GPIO1

#endif