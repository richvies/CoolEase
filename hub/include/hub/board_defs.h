#include <libopencm3/stm32/rcc.h>

// Sensor Struct
#define MAX_SENSORS 20

typedef struct
{
	uint32_t dev_num;
	uint32_t msg_num;
	uint32_t msg_num_start;
	uint32_t ok_packets;
	uint32_t total_packets;
	int8_t power;
	uint16_t battery;
	int16_t temperature;
	int16_t rssi;
	bool msg_pend;
	bool active;
} sensor_t;

// Battery Voltage
#define BATT_SENS_PORT GPIOA
#define BATT_SENS GPIO0
// Power Supply Voltage
#define PWR_SENS_PORT GPIOA
#define PWR_SENS GPIO1

// Status LED
#define LED_PORT 	GPIOB
#define LED 		GPIO8
#define LED_RCC 	RCC_GPIOB

// USART / Serial Printf
#define SPF_USART_BAUD 115200
#define SPF_USART USART1
#define SPF_USART_AF GPIO_AF4
#define SPF_USART_RCC RCC_USART1
#define SPF_USART_RCC_RST RST_USART1
#define SPF_USART_TX_PORT GPIOA
#define SPF_USART_TX GPIO9
#define SPF_USART_RX_PORT GPIOA
#define SPF_USART_RX GPIO10

// RFM
// SPI
#define RFM_SPI SPI2
#define RFM_SPI_AF GPIO_AF0
#define RFM_SPI_RCC RCC_SPI2
#define RFM_SPI_RST RST_SPI2

#define RFM_SPI_NSS_PORT GPIOA
#define RFM_SPI_NSS GPIO6

#define RFM_SPI_MISO_PORT GPIOB
#define RFM_SPI_MISO GPIO14

#define RFM_SPI_MOSI_PORT GPIOB
#define RFM_SPI_MOSI GPIO15

#define RFM_SPI_SCK_PORT GPIOB
#define RFM_SPI_SCK GPIO13

// IO
#define RFM_RESET_PORT GPIOA
#define RFM_RESET GPIO4

#define RFM_IO_0_PORT GPIOB
#define RFM_IO_0 GPIO10
#define RFM_IO_0_EXTI EXTI10
#define RFM_IO_0_NVIC NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT GPIOB
#define RFM_IO_1 GPIO11

#define RFM_IO_2_PORT GPIOA
#define RFM_IO_2 GPIO8

#define RFM_IO_3_PORT GPIOB
#define RFM_IO_3 GPIO1

#define RFM_IO_4_PORT GPIOB
#define RFM_IO_4 GPIO2

#define RFM_IO_5_PORT GPIOB
#define RFM_IO_5 GPIO0

// USART / SIM
#define SIM_USART_BAUD 		38400
#define SIM_USART_NVIC		NVIC_USART2_IRQ
#define SIM_USART 			USART2
#define SIM_USART_AF 		GPIO_AF4
#define SIM_USART_RCC 		RCC_USART2
#define SIM_USART_RCC_RST 	RST_USART2

#define SIM_USART_TX_PORT GPIOA
#define SIM_USART_TX GPIO2

#define SIM_USART_RX_PORT GPIOA
#define SIM_USART_RX GPIO3

#define SIM_RESET_PORT GPIOA
#define SIM_RESET GPIO4

// W25
// SPI
#define W25_SPI SPI1
#define W25_SPI_AF GPIO_AF0
#define W25_SPI_RCC RCC_SPI1
#define W25_SPI_RST RST_SPI1

#define W25_SPI_NSS_PORT GPIOB
#define W25_SPI_NSS GPIO6

#define W25_SPI_MISO_PORT GPIOB
#define W25_SPI_MISO GPIO4

#define W25_SPI_MOSI_PORT GPIOB
#define W25_SPI_MOSI GPIO5

#define W25_SPI_SCK_PORT GPIOB
#define W25_SPI_SCK GPIO3