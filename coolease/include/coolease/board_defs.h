#ifndef BOARD_DEFS_H
#define BOARD_DEFS_H

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>

#ifdef _HUB  

// Sensor Struct
#define MAX_SENSORS 50
typedef struct
{
	bool 		msg_pend;
	bool 		active;
	uint32_t 	dev_num;
	uint32_t 	msg_num;
	uint32_t 	msg_num_start;
	uint32_t 	ok_packets;
	uint32_t 	total_packets;
}sensor_t;

extern sensor_t 	sensors[MAX_SENSORS];
extern uint8_t 		num_sensors;
sensor_t 			*get_sensor(uint32_t dev_num);


// Memory Map
#define FLASH_START     0x08000000
#define FLASH_END       0x08010000
#define FLASH_PAGE_SIZE 128
#define EEPROM_START    0x08080000   
#define EEPROM_END      0x08080800 


// Battery Voltage
#define BATT_SENS_PORT          GPIOA
#define BATT_SENS               GPIO0
// Power Supply Voltage
#define PWR_SENS_PORT           GPIOA
#define PWR_SENS                GPIO1


// Status LED
#define LED_PORT                GPIOB
#define LED                     GPIO8


// USART / Serial Printf
#define SPF_USART_BAUD          115200
#define SPF_USART               USART1 
#define SPF_USART_AF            GPIO_AF4 
#define SPF_USART_RCC           RCC_USART1
#define SPF_USART_RCC_RST       RST_USART1 
#define SPF_USART_TX_PORT       GPIOA
#define SPF_USART_TX            GPIO9
#define SPF_USART_RX_PORT       GPIOA   
#define SPF_USART_RX            GPIO10   


// RFM
// SPI
#define RFM_SPI                 SPI2
#define RFM_SPI_AF              GPIO_AF0
#define RFM_SPI_RCC             RCC_SPI2
#define RFM_SPI_RST             RST_SPI2

#define RFM_SPI_NSS_PORT        GPIOA
#define RFM_SPI_NSS             GPIO6

#define RFM_SPI_MISO_PORT       GPIOB
#define RFM_SPI_MISO            GPIO14

#define RFM_SPI_MOSI_PORT       GPIOB
#define RFM_SPI_MOSI            GPIO15

#define RFM_SPI_SCK_PORT        GPIOB
#define RFM_SPI_SCK             GPIO13

// IO
#define RFM_RESET_PORT          GPIOA
#define RFM_RESET               GPIO4

#define RFM_IO_0_PORT           GPIOB
#define RFM_IO_0                GPIO10
#define RFM_IO_0_EXTI           EXTI10
#define RFM_IO_0_NVIC           NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT           GPIOB
#define RFM_IO_1                GPIO11

#define RFM_IO_2_PORT           GPIOA
#define RFM_IO_2                GPIO8

#define RFM_IO_3_PORT           GPIOB
#define RFM_IO_3                GPIO1

#define RFM_IO_4_PORT           GPIOB
#define RFM_IO_4                GPIO2

#define RFM_IO_5_PORT           GPIOB
#define RFM_IO_5                GPIO0


// USART / SIM
#define SIM_USART_BAUD          38400
#define SIM_USART_NVIC          NVIC_USART2_IRQ
#define SIM_USART               USART2 
#define SIM_USART_AF            GPIO_AF4 
#define SIM_USART_RCC           RCC_USART2
#define SIM_USART_RCC_RST       RST_USART2 

#define SIM_USART_TX_PORT       GPIOA
#define SIM_USART_TX            GPIO2

#define SIM_USART_RX_PORT       GPIOA  
#define SIM_USART_RX            GPIO3  

#define SIM_RESET_PORT          GPIOA          
#define SIM_RESET               GPIO4   


// W25
// SPI
#define W25_SPI                 SPI1
#define W25_SPI_AF              GPIO_AF0
#define W25_SPI_RCC             RCC_SPI1
#define W25_SPI_RST             RST_SPI1

#define W25_SPI_NSS_PORT        GPIOB
#define W25_SPI_NSS             GPIO6

#define W25_SPI_MISO_PORT       GPIOB
#define W25_SPI_MISO            GPIO4

#define W25_SPI_MOSI_PORT       GPIOB
#define W25_SPI_MOSI            GPIO5

#define W25_SPI_SCK_PORT        GPIOB
#define W25_SPI_SCK             GPIO3


#else

// Sensor Struct
#define MAX_SENSORS 50
typedef struct
{
	bool 		msg_pend;
	bool 		active;
	uint32_t 	dev_num;
	uint32_t 	msg_num;
	uint32_t 	msg_num_start;
	uint32_t 	ok_packets;
	uint32_t 	total_packets;
}sensor_t;

extern sensor_t 	sensors[MAX_SENSORS];
extern uint8_t 		num_sensors;
sensor_t 			*get_sensor(uint32_t dev_num);

// Memory Map
#define FLASH_START     0x08000000
#define FLASH_END       0x08010000
#define FLASH_PAGE_SIZE 128
#define EEPROM_START    0x08080000   
#define EEPROM_END      0x08080800   

// Battery Voltage
#define BATT_SENS_PORT          GPIOA
#define BATT_SENS               GPIO0


// Status LED
#define LED_PORT                GPIOA
#define LED                     GPIO14

// USART / Serial Printf
#define SPF_USART_BAUD          115200
#define SPF_USART               USART2 
#define SPF_USART_AF            GPIO_AF4 
#define SPF_USART_RCC           RCC_USART2
#define SPF_USART_RCC_RST       RST_USART2 

// GPIOA
#define SPF_USART_TX_PORT       GPIOA
#define SPF_USART_TX            GPIO2

#define SPF_USART_RX_PORT       GPIOA   
#define SPF_USART_RX            GPIO3   

// SPI / RFM
#define RFM_SPI                 SPI1
#define RFM_SPI_AF              GPIO_AF0
#define RFM_SPI_RCC             RCC_SPI1
#define RFM_SPI_RST             RST_SPI1

// RFM
// SPI
#define RFM_SPI                 SPI1
#define RFM_SPI_AF              GPIO_AF0
#define RFM_SPI_RCC             RCC_SPI1
#define RFM_SPI_RST             RST_SPI1

#define RFM_SPI_NSS_PORT        GPIOA
#define RFM_SPI_NSS             GPIO4

#define RFM_SPI_SCK_PORT        GPIOA
#define RFM_SPI_SCK             GPIO5

#define RFM_SPI_MISO_PORT       GPIOA
#define RFM_SPI_MISO            GPIO6

#define RFM_SPI_MOSI_PORT       GPIOA
#define RFM_SPI_MOSI            GPIO7

// IO
#define RFM_RESET_PORT          GPIOB
#define RFM_RESET               GPIO0

#define RFM_IO_0_PORT           GPIOB
#define RFM_IO_0                GPIO15
#define RFM_IO_0_EXTI           EXTI15
#define RFM_IO_0_NVIC           NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT           GPIOB
#define RFM_IO_1                GPIO12

#define RFM_IO_2_PORT           GPIOB
#define RFM_IO_2                GPIO11

#define RFM_IO_3_PORT           GPIOB
#define RFM_IO_3                GPIO2

#define RFM_IO_4_PORT           GPIOB
#define RFM_IO_4                GPIO10

#define RFM_IO_5_PORT           GPIOB
#define RFM_IO_5                GPIO1


// Temp Sensor
// I2C
#define TEMP_I2C                I2C2
#define TEMP_I2C_AF             GPIO_AF5
#define TEMP_I2C_RCC            RCC_I2C2
#define TEMP_I2C_RCC_RST        RST_I2C2

#define TEMP_I2C_SCL_PORT       GPIOB
#define TEMP_I2C_SCL            GPIO13

#define TEMP_I2C_SDA_PORT       GPIOB
#define TEMP_I2C_SDA            GPIO14

#endif

void gpio_init(void);

#endif