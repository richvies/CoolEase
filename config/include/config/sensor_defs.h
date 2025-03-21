// Interrupt Priorities
#define IRQ_PRIORITY_LPTIM 0x00
#define IRQ_PRIORITY_SPF   0x40
#define IRQ_PRIORITY_RFM   0x80
#define IRQ_PRIORITY_BATT  0xC0
#define IRQ_PRIORITY_RTC   0xF0

// Battery Voltage
#define BATT_SENS_PORT GPIOA
#define BATT_SENS      GPIO0

// Status LED
#define LED_PORT GPIOA
#define LED      GPIO14
#define LED_RCC  RCC_GPIOA

// USART / Serial Printf
#define SPF_USART_BAUD    115200
#define SPF_USART         USART2
#define SPF_USART_NVIC    NVIC_USART2_IRQ
#define SPF_USART_AF      GPIO_AF4
#define SPF_USART_RCC     RCC_USART2
#define SPF_USART_RCC_RST RST_USART2
#define SPF_ISR()         void usart2_isr(void)

// GPIOA
#define SPF_USART_TX_PORT GPIOA
#define SPF_USART_TX      GPIO2

#define SPF_USART_RX_PORT GPIOA
#define SPF_USART_RX      GPIO3

// RFM
// SPI
#define RFM_SPI     SPI1
#define RFM_SPI_AF  GPIO_AF0
#define RFM_SPI_RCC RCC_SPI1
#define RFM_SPI_RST RST_SPI1

#define RFM_SPI_NSS_PORT GPIOA
#define RFM_SPI_NSS      GPIO4

#define RFM_SPI_SCK_PORT GPIOA
#define RFM_SPI_SCK      GPIO5

#define RFM_SPI_MISO_PORT GPIOA
#define RFM_SPI_MISO      GPIO6

#define RFM_SPI_MOSI_PORT GPIOA
#define RFM_SPI_MOSI      GPIO7

// IO
#define RFM_RESET_PORT GPIOB
#define RFM_RESET      GPIO0

#define RFM_IO_0_PORT GPIOB
#define RFM_IO_0      GPIO15
#define RFM_IO_0_EXTI EXTI15
#define RFM_IO_0_NVIC NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT GPIOB
#define RFM_IO_1      GPIO12

#define RFM_IO_2_PORT GPIOB
#define RFM_IO_2      GPIO11

#define RFM_IO_3_PORT GPIOB
#define RFM_IO_3      GPIO2

#define RFM_IO_4_PORT GPIOB
#define RFM_IO_4      GPIO10

#define RFM_IO_5_PORT GPIOB
#define RFM_IO_5      GPIO1

// Temp Sensor
// I2C
#define TEMP_I2C         I2C2
#define TEMP_I2C_AF      GPIO_AF5
#define TEMP_I2C_RCC     RCC_I2C2
#define TEMP_I2C_RCC_RST RST_I2C2

#define TEMP_I2C_SCL_PORT GPIOB
#define TEMP_I2C_SCL      GPIO13

#define TEMP_I2C_SDA_PORT GPIOB
#define TEMP_I2C_SDA      GPIO14