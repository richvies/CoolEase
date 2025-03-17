#include "hub/w25qxx.h"

#include <stdint.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/cm3/nvic.h>

#include "config/board_defs.h"
#include "common/log.h"
#include "common/timers.h"

#define W25_DUMMY_BYTE         0xA5

// SPI Comms Functions
#define spi_chip_select()         gpio_clear(W25_SPI_NSS_PORT, W25_SPI_NSS)
#define spi_chip_deselect()       gpio_set(W25_SPI_NSS_PORT, W25_SPI_NSS)

w25_t	w25;

static void spi_setup(void);

bool w25_Init(void)
{
	spi_setup();

	w25.Lock=1;
	timers_delay_microseconds(100);
	spi_chip_deselect();
  	timers_delay_microseconds(100);

	timers_delay_milliseconds(20);

	uint32_t	id;
	serial_printf("w25 Init Begin...\r\n");

	id=w25_ReadID();

	serial_printf("w25 ID:0x%X\r\n",id);
	switch(id&0x0000FFFF)
	{
		case 0x401A:	// 	w25q512
			w25.ID=W25Q512;
			w25.BlockCount=1024;
			serial_printf("w25 Chip: w25q512\r\n");
		break;
		case 0x4019:	// 	w25q256
			w25.ID=W25Q256;
			w25.BlockCount=512;
			serial_printf("w25 Chip: w25q256\r\n");
		break;
		case 0x4018:	// 	w25q128
			w25.ID=W25Q128;
			w25.BlockCount=256;
			serial_printf("w25 Chip: w25q128\r\n");
		break;
		case 0x4017:	//	w25q64
			w25.ID=W25Q64;
			w25.BlockCount=128;
			serial_printf("w25 Chip: w25q64\r\n");
		break;
		case 0x4016:	//	w25q32
			w25.ID=W25Q32;
			w25.BlockCount=64;
			serial_printf("w25 Chip: w25q32\r\n");
		break;
		case 0x4015:	//	w25q16
			w25.ID=W25Q16;
			w25.BlockCount=32;
			serial_printf("w25 Chip: w25q16\r\n");
		break;
		case 0x4014:	//	w25q80
			w25.ID=W25Q80;
			w25.BlockCount=16;
			serial_printf("w25 Chip: w25q80\r\n");
		break;
		case 0x4013:	//	w25q40
			w25.ID=W25Q40;
			w25.BlockCount=8;
			serial_printf("w25 Chip: w25q40\r\n");
		break;
		case 0x4012:	//	w25q20
			w25.ID=W25Q20;
			w25.BlockCount=4;
			serial_printf("w25 Chip: w25q20\r\n");
		break;
		case 0x4011:	//	w25q10
			w25.ID=W25Q10;
			w25.BlockCount=2;
			serial_printf("w25 Chip: w25q10\r\n");
		break;
		default:
				serial_printf("w25 Unknown ID\r\n");
			w25.Lock=0;
			return false;

	}

	w25.PageSize=256;
	w25.SectorSize=0x1000;
	w25.SectorCount=w25.BlockCount*16;
	w25.PageCount=(w25.SectorCount*w25.SectorSize)/w25.PageSize;
	w25.BlockSize=w25.SectorSize*16;
	w25.CapacityInKiloByte=(w25.SectorCount*w25.SectorSize)/1024;

	w25_ReadUniqID();
	w25_ReadStatusRegister(1);
	w25_ReadStatusRegister(2);
	w25_ReadStatusRegister(3);
	serial_printf("w25 Page Size: %d Bytes\r\n",w25.PageSize);
	serial_printf("w25 Sector Size: %d Bytes\r\n",w25.SectorSize);
	serial_printf("w25 Sector Count: %d\r\n",w25.SectorCount);
	serial_printf("w25 Block Size: %d Bytes\r\n",w25.BlockSize);
	serial_printf("w25 Block Count: %d\r\n",w25.BlockCount);
	serial_printf("w25 Capacity: %d KiloBytes\r\n",w25.CapacityInKiloByte);
	serial_printf("w25 Init Done\r\n");

	w25.Lock=0;

	return true;
}

//###################################################################################################################

uint32_t 	w25_ReadID(void)
{
	uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

	spi_chip_select();
	timers_delay_microseconds(1);

	spi_xfer(W25_SPI, 0x9F);
	Temp0 = spi_xfer(W25_SPI, W25_DUMMY_BYTE);
	Temp1 = spi_xfer(W25_SPI, W25_DUMMY_BYTE);
	Temp2 = spi_xfer(W25_SPI, W25_DUMMY_BYTE);

	spi_chip_deselect();
  	timers_delay_microseconds(1);

	Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
  	return Temp;
}

void 		w25_ReadUniqID(void)
{
	spi_chip_select();
	timers_delay_microseconds(1);

	spi_xfer(W25_SPI, 0x4B);

	for(uint8_t	i=0;i<4;i++)
		spi_xfer(W25_SPI, W25_DUMMY_BYTE);

	for(uint8_t	i=0;i<8;i++)
		w25.UniqID[i] = spi_xfer(W25_SPI, W25_DUMMY_BYTE);

    spi_chip_deselect();
  	timers_delay_microseconds(1);
}

//###################################################################################################################

void w25_WriteEnable(void)
{
	spi_chip_select();
	timers_delay_microseconds(1);

	spi_xfer(W25_SPI, 0x06);

	spi_chip_deselect();
  	timers_delay_microseconds(1);
}
void w25_WriteDisable(void)
{
  spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0x04);
    	spi_chip_deselect();
  	timers_delay_microseconds(1);
	timers_delay_microseconds(1);
}
void w25_WaitForWriteEnd(void)
{
	spi_chip_select();
  	timers_delay_microseconds(1);

	spi_xfer(W25_SPI, 0x05);

	do
	{
		w25.StatusRegister1 = spi_xfer(W25_SPI, W25_DUMMY_BYTE);
		timers_delay_microseconds(10);
	}while ((w25.StatusRegister1 & 0x01) == 0x01);

   	spi_chip_deselect();
  	timers_delay_microseconds(1);
}

//###################################################################################################################

uint8_t w25_ReadStatusRegister(uint8_t	SelectStatusRegister_1_2_3)
{
	uint8_t	status=0;

	spi_chip_select();
  	timers_delay_microseconds(1);

	if(SelectStatusRegister_1_2_3==1)
	{
		spi_xfer(W25_SPI, 0x05);
		status=spi_xfer(W25_SPI, W25_DUMMY_BYTE);
		w25.StatusRegister1 = status;
	}
	else if(SelectStatusRegister_1_2_3==2)
	{
		spi_xfer(W25_SPI, 0x35);
		status=spi_xfer(W25_SPI, W25_DUMMY_BYTE);
		w25.StatusRegister2 = status;
	}
	else
	{
		spi_xfer(W25_SPI, 0x15);
		status=spi_xfer(W25_SPI, W25_DUMMY_BYTE);
		w25.StatusRegister3 = status;
	}

	spi_chip_deselect();
  	timers_delay_microseconds(1);

	return status;
}
void 	w25_WriteStatusRegister(uint8_t	SelectStatusRegister_1_2_3, uint8_t Data)
{
	spi_chip_select();
  	timers_delay_microseconds(1);

	if(SelectStatusRegister_1_2_3==1)
	{
		spi_xfer(W25_SPI, 0x01);
		w25.StatusRegister1 = Data;
	}
	else if(SelectStatusRegister_1_2_3==2)
	{
		spi_xfer(W25_SPI, 0x31);
		w25.StatusRegister2 = Data;
	}
	else
	{
		spi_xfer(W25_SPI, 0x11);
		w25.StatusRegister3 = Data;
	}

	spi_xfer(W25_SPI, Data);

    spi_chip_deselect();
  	timers_delay_microseconds(1);
}


//###################################################################################################################

void	w25_EraseChip(void)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;

	// uint32_t	StartTime=HAL_GetTick();
	serial_printf("w25 EraseChip Begin...\r\n");

	w25_WriteEnable();

	spi_chip_select();
  	timers_delay_microseconds(1);

  	spi_xfer(W25_SPI, 0xC7);

    spi_chip_deselect();
  	timers_delay_microseconds(1);

	w25_WaitForWriteEnd();

	// serial_printf("w25 EraseBlock done after %d ms!\r\n",HAL_GetTick()-StartTime);

	timers_delay_microseconds(10);

	w25.Lock=0;
}
void 	w25_EraseSector(uint32_t SectorAddr)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;
	// uint32_t	StartTime=HAL_GetTick();
	serial_printf("w25 EraseSector %d Begin...\r\n",SectorAddr);
	w25_WaitForWriteEnd();
	SectorAddr = SectorAddr * w25.SectorSize;
  w25_WriteEnable();
  spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0x20);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (SectorAddr & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (SectorAddr & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (SectorAddr & 0xFF00) >> 8);
  spi_xfer(W25_SPI, SectorAddr & 0xFF);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);
  w25_WaitForWriteEnd();
	// serial_printf("w25 EraseSector done after %d ms\r\n",HAL_GetTick()-StartTime);
	timers_delay_microseconds(1);
	w25.Lock=0;
}
void 	w25_EraseBlock(uint32_t BlockAddr)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;
	serial_printf("w25 EraseBlock %d Begin...\r\n",BlockAddr);
	// uint32_t	StartTime=HAL_GetTick();
	w25_WaitForWriteEnd();
	BlockAddr = BlockAddr * w25.SectorSize*16;
  w25_WriteEnable();
  spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0xD8);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (BlockAddr & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (BlockAddr & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (BlockAddr & 0xFF00) >> 8);
  spi_xfer(W25_SPI, BlockAddr & 0xFF);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);
  w25_WaitForWriteEnd();
	// serial_printf("w25 EraseBlock done after %d ms\r\n",HAL_GetTick()-StartTime);
	timers_delay_microseconds(1);
	w25.Lock=0;
}

//###################################################################################################################

uint32_t	w25_PageToSector(uint32_t	PageAddress)
{
	return ((PageAddress*w25.PageSize)/w25.SectorSize);
}
uint32_t	w25_PageToBlock(uint32_t	PageAddress)
{
	return ((PageAddress*w25.PageSize)/w25.BlockSize);
}
uint32_t	w25_SectorToBlock(uint32_t	SectorAddress)
{
	return ((SectorAddress*w25.SectorSize)/w25.BlockSize);
}
uint32_t	w25_SectorToPage(uint32_t	SectorAddress)
{
	return (SectorAddress*w25.SectorSize)/w25.PageSize;
}
uint32_t	w25_BlockToPage(uint32_t	BlockAddress)
{
	return (BlockAddress*w25.BlockSize)/w25.PageSize;
}

//###################################################################################################################

bool 	w25_IsEmptyPage(uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_PageSize)
{
	while(w25.Lock==1)
	timers_delay_microseconds(1);
	w25.Lock=1;
	if(((NumByteToCheck_up_to_PageSize+OffsetInByte)>w25.PageSize)||(NumByteToCheck_up_to_PageSize==0))
		NumByteToCheck_up_to_PageSize=w25.PageSize-OffsetInByte;
	serial_printf("w25 CheckPage:%d, Offset:%d, Bytes:%d begin...\r\n",Page_Address,OffsetInByte,NumByteToCheck_up_to_PageSize);
	// uint32_t	StartTime=HAL_GetTick();
	uint8_t	pBuffer[32];
	uint32_t	WorkAddress;
	uint32_t	i;
	for(i=OffsetInByte; i<w25.PageSize; i+=sizeof(pBuffer))
	{
		spi_chip_select();
  	timers_delay_microseconds(1);
		WorkAddress=(i+Page_Address*w25.PageSize);
		spi_xfer(W25_SPI, 0x0B);
		if(w25.ID>=W25Q256)
		{
			spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
		}
		spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
		spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
		spi_xfer(W25_SPI, WorkAddress & 0xFF);
		spi_xfer(W25_SPI, 0);
		// HAL_SPI_Receive(&_W25_SPI,pBuffer,sizeof(pBuffer),100);
		  	spi_chip_deselect();
  	timers_delay_microseconds(1);
		for(uint8_t x=0;x<sizeof(pBuffer);x++)
		{
			if(pBuffer[x]!=0xFF)
			{

			}
				// goto NOT_EMPTY;
		}
	}
	if((w25.PageSize+OffsetInByte)%sizeof(pBuffer)!=0)
	{
		i-=sizeof(pBuffer);
		for( ; i<w25.PageSize; i++)
		{
			spi_chip_select();
  	timers_delay_microseconds(1);
			WorkAddress=(i+Page_Address*w25.PageSize);
			spi_xfer(W25_SPI, 0x0B);
			if(w25.ID>=W25Q256)
				spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
			spi_xfer(W25_SPI, WorkAddress & 0xFF);
			spi_xfer(W25_SPI, 0);
			// HAL_SPI_Receive(&_W25_SPI,pBuffer,1,100);
			  	spi_chip_deselect();
  	timers_delay_microseconds(1);
			if(pBuffer[0]!=0xFF)
			{

			}
				// goto NOT_EMPTY;
		}
	}
	// serial_printf("w25 CheckPage is Empty in %d ms\r\n",HAL_GetTick()-StartTime);
	w25.Lock=0;
	return true;
	// NOT_EMPTY:
	// serial_printf("w25 CheckPage is Not Empty in %d ms\r\n",HAL_GetTick()-StartTime);
	w25.Lock=0;
	return false;
}
bool 	w25_IsEmptySector(uint32_t Sector_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_SectorSize)
{
	while(w25.Lock==1)
	timers_delay_microseconds(1);
	w25.Lock=1;
	if((NumByteToCheck_up_to_SectorSize>w25.SectorSize)||(NumByteToCheck_up_to_SectorSize==0))
		NumByteToCheck_up_to_SectorSize=w25.SectorSize;
	serial_printf("w25 CheckSector:%d, Offset:%d, Bytes:%d begin...\r\n",Sector_Address,OffsetInByte,NumByteToCheck_up_to_SectorSize);
	// uint32_t	StartTime=HAL_GetTick();
	uint8_t	pBuffer[32];
	uint32_t	WorkAddress;
	uint32_t	i;
	for(i=OffsetInByte; i<w25.SectorSize; i+=sizeof(pBuffer))
	{
		spi_chip_select();
  	timers_delay_microseconds(1);
		WorkAddress=(i+Sector_Address*w25.SectorSize);
		spi_xfer(W25_SPI, 0x0B);
		if(w25.ID>=W25Q256)
			spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
		spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
		spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
		spi_xfer(W25_SPI, WorkAddress & 0xFF);
		spi_xfer(W25_SPI, 0);
		// HAL_SPI_Receive(&_W25_SPI,pBuffer,sizeof(pBuffer),100);
		  	spi_chip_deselect();
  	timers_delay_microseconds(1);
		for(uint8_t x=0;x<sizeof(pBuffer);x++)
		{
			if(pBuffer[x]!=0xFF)
			{

			}
				// goto NOT_EMPTY;
		}
	}
	if((w25.SectorSize+OffsetInByte)%sizeof(pBuffer)!=0)
	{
		i-=sizeof(pBuffer);
		for( ; i<w25.SectorSize; i++)
		{
			spi_chip_select();
  	timers_delay_microseconds(1);
			WorkAddress=(i+Sector_Address*w25.SectorSize);
			spi_xfer(W25_SPI, 0x0B);
			if(w25.ID>=W25Q256)
				spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
			spi_xfer(W25_SPI, WorkAddress & 0xFF);
			spi_xfer(W25_SPI, 0);
			// HAL_SPI_Receive(&_W25_SPI,pBuffer,1,100);
			  	spi_chip_deselect();
  	timers_delay_microseconds(1);
			if(pBuffer[0]!=0xFF)
			{

			}
				// goto NOT_EMPTY;
		}
	}
	// serial_printf("w25 CheckSector is Empty in %d ms\r\n",HAL_GetTick()-StartTime);
	w25.Lock=0;
	return true;
	// serial_printf("w25 CheckSector is Not Empty in %d ms\r\n",HAL_GetTick()-StartTime);
	w25.Lock=0;
	return false;
}
bool 	w25_IsEmptyBlock(uint32_t Block_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_BlockSize)
{
	while(w25.Lock==1)
	timers_delay_microseconds(1);
	w25.Lock=1;
	if((NumByteToCheck_up_to_BlockSize>w25.BlockSize)||(NumByteToCheck_up_to_BlockSize==0))
		NumByteToCheck_up_to_BlockSize=w25.BlockSize;
	serial_printf("w25 CheckBlock:%d, Offset:%d, Bytes:%d begin...\r\n",Block_Address,OffsetInByte,NumByteToCheck_up_to_BlockSize);
	// uint32_t	StartTime=HAL_GetTick();
	uint8_t	pBuffer[32];
	uint32_t	WorkAddress;
	uint32_t	i;
	for(i=OffsetInByte; i<w25.BlockSize; i+=sizeof(pBuffer))
	{
		spi_chip_select();
  	timers_delay_microseconds(1);
		WorkAddress=(i+Block_Address*w25.BlockSize);
		spi_xfer(W25_SPI, 0x0B);
		if(w25.ID>=W25Q256)
			spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
		spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
		spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
		spi_xfer(W25_SPI, WorkAddress & 0xFF);
		spi_xfer(W25_SPI, 0);
		// HAL_SPI_Receive(&_W25_SPI,pBuffer,sizeof(pBuffer),100);
		  	spi_chip_deselect();
  	timers_delay_microseconds(1);
		for(uint8_t x=0;x<sizeof(pBuffer);x++)
		{
			if(pBuffer[x]!=0xFF){}
				// goto NOT_EMPTY;
		}
	}
	if((w25.BlockSize+OffsetInByte)%sizeof(pBuffer)!=0)
	{
		i-=sizeof(pBuffer);
		for( ; i<w25.BlockSize; i++)
		{
			spi_chip_select();
  	timers_delay_microseconds(1);
			WorkAddress=(i+Block_Address*w25.BlockSize);
			spi_xfer(W25_SPI, 0x0B);
			if(w25.ID>=W25Q256)
				spi_xfer(W25_SPI, (WorkAddress & 0xFF000000) >> 24);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF0000) >> 16);
			spi_xfer(W25_SPI, (WorkAddress & 0xFF00) >> 8);
			spi_xfer(W25_SPI, WorkAddress & 0xFF);
			spi_xfer(W25_SPI, 0);
			// HAL_SPI_Receive(&_W25_SPI,pBuffer,1,100);
			  	spi_chip_deselect();
  	timers_delay_microseconds(1);
			if(pBuffer[0]!=0xFF){}
				// goto NOT_EMPTY;
		}
	}
	// serial_printf("w25 CheckBlock is Empty in %d ms\r\n",HAL_GetTick()-StartTime);

	w25.Lock=0;
	return true;
	// NOT_EMPTY:
	// serial_printf("w25 CheckBlock is Not Empty in %d ms\r\n",HAL_GetTick()-StartTime);

	w25.Lock=0;
	return false;
}

//###################################################################################################################

void 	w25_WriteByte(uint8_t pBuffer, uint32_t WriteAddr_inBytes)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;

	// uint32_t	StartTime=HAL_GetTick();
	serial_printf("w25 WriteByte 0x%02X at address %d begin...",pBuffer,WriteAddr_inBytes);

	w25_WaitForWriteEnd();
  w25_WriteEnable();
  spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0x02);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (WriteAddr_inBytes & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (WriteAddr_inBytes & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (WriteAddr_inBytes & 0xFF00) >> 8);
  spi_xfer(W25_SPI, WriteAddr_inBytes & 0xFF);
  spi_xfer(W25_SPI, pBuffer);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);
  w25_WaitForWriteEnd();
	// serial_printf("w25 WriteByte done after %d ms\r\n",HAL_GetTick()-StartTime);
	w25.Lock=0;
}
void 	w25_WritePage(uint8_t *pBuffer	,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToWrite_up_to_PageSize)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;
	if(((NumByteToWrite_up_to_PageSize+OffsetInByte)>w25.PageSize)||(NumByteToWrite_up_to_PageSize==0))
		NumByteToWrite_up_to_PageSize=w25.PageSize-OffsetInByte;
	if((OffsetInByte+NumByteToWrite_up_to_PageSize) > w25.PageSize)
		NumByteToWrite_up_to_PageSize = w25.PageSize-OffsetInByte;
	serial_printf("w25 WritePage:%d, Offset:%d ,Writes %d Bytes, begin...\r\n",Page_Address,OffsetInByte,NumByteToWrite_up_to_PageSize);
	// uint32_t	StartTime=HAL_GetTick();
	#
	w25_WaitForWriteEnd();
  w25_WriteEnable();
  spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0x02);
	Page_Address = (Page_Address*w25.PageSize)+OffsetInByte;
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (Page_Address & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (Page_Address & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (Page_Address & 0xFF00) >> 8);
  spi_xfer(W25_SPI, Page_Address&0xFF);
	// HAL_SPI_Transmit(&_W25_SPI,pBuffer,NumByteToWrite_up_to_PageSize,100);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);
  w25_WaitForWriteEnd();

	// StartTime = HAL_GetTick()-StartTime;
	for(uint32_t i=0;i<NumByteToWrite_up_to_PageSize ; i++)
	{
		if((i%8==0)&&(i>2))
		{
			serial_printf("\r\n");
			timers_delay_microseconds(10);
		}
		serial_printf("0x%02X,",pBuffer[i]);
	}
	serial_printf("\r\n");
	// serial_printf("w25 WritePage done after %d ms\r\n",StartTime);
	timers_delay_microseconds(100);
	#
	timers_delay_microseconds(1);
	w25.Lock=0;
}
void 	w25_WriteSector(uint8_t *pBuffer	,uint32_t Sector_Address,uint32_t OffsetInByte	,uint32_t NumByteToWrite_up_to_SectorSize)
{
	if((NumByteToWrite_up_to_SectorSize>w25.SectorSize)||(NumByteToWrite_up_to_SectorSize==0))
		NumByteToWrite_up_to_SectorSize=w25.SectorSize;
	serial_printf("+++w25 WriteSector:%d, Offset:%d ,Write %d Bytes, begin...\r\n",Sector_Address,OffsetInByte,NumByteToWrite_up_to_SectorSize);
	#
	if(OffsetInByte>=w25.SectorSize)
	{
		serial_printf("---w25 WriteSector Faild!\r\n");

		return;
	}
	uint32_t	StartPage;
	int32_t		BytesToWrite;
	uint32_t	LocalOffset;
	if((OffsetInByte+NumByteToWrite_up_to_SectorSize) > w25.SectorSize)
		BytesToWrite = w25.SectorSize-OffsetInByte;
	else
		BytesToWrite = NumByteToWrite_up_to_SectorSize;
	StartPage = w25_SectorToPage(Sector_Address)+(OffsetInByte/w25.PageSize);
	LocalOffset = OffsetInByte%w25.PageSize;
	do
	{
		w25_WritePage(pBuffer,StartPage,LocalOffset,BytesToWrite);
		StartPage++;
		BytesToWrite-=w25.PageSize-LocalOffset;
		pBuffer += w25.PageSize - LocalOffset;
		LocalOffset=0;
	}while(BytesToWrite>0);
	serial_printf("---w25 WriteSector Done\r\n");

}
void 	w25_WriteBlock	(uint8_t* pBuffer ,uint32_t Block_Address	,uint32_t OffsetInByte	,uint32_t	NumByteToWrite_up_to_BlockSize)
{
	if((NumByteToWrite_up_to_BlockSize>w25.BlockSize)||(NumByteToWrite_up_to_BlockSize==0))
		NumByteToWrite_up_to_BlockSize=w25.BlockSize;
	serial_printf("+++w25 WriteBlock:%d, Offset:%d ,Write %d Bytes, begin...\r\n",Block_Address,OffsetInByte,NumByteToWrite_up_to_BlockSize);

	if(OffsetInByte>=w25.BlockSize)
	{
		serial_printf("---w25 WriteBlock Faild!\r\n");

		return;
	}
	uint32_t	StartPage;
	int32_t		BytesToWrite;
	uint32_t	LocalOffset;
	if((OffsetInByte+NumByteToWrite_up_to_BlockSize) > w25.BlockSize)
		BytesToWrite = w25.BlockSize-OffsetInByte;
	else
		BytesToWrite = NumByteToWrite_up_to_BlockSize;
	StartPage = w25_BlockToPage(Block_Address)+(OffsetInByte/w25.PageSize);
	LocalOffset = OffsetInByte%w25.PageSize;
	do
	{
		w25_WritePage(pBuffer,StartPage,LocalOffset,BytesToWrite);
		StartPage++;
		BytesToWrite-=w25.PageSize-LocalOffset;
		pBuffer += w25.PageSize - LocalOffset;
		LocalOffset=0;
	}while(BytesToWrite>0);
	serial_printf("---w25 WriteBlock Done\r\n");

}

//###################################################################################################################

void 	w25_ReadByte(uint8_t *pBuffer,uint32_t Bytes_Address)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;

	// uint32_t	StartTime=HAL_GetTick();
	serial_printf("w25 ReadByte at address %d begin...\r\n",Bytes_Address);

	spi_chip_select();
  	timers_delay_microseconds(1);
  spi_xfer(W25_SPI, 0x0B);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (Bytes_Address & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (Bytes_Address & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (Bytes_Address& 0xFF00) >> 8);
  spi_xfer(W25_SPI, Bytes_Address & 0xFF);
	spi_xfer(W25_SPI, 0);
	*pBuffer = spi_xfer(W25_SPI, W25_DUMMY_BYTE);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);
	// serial_printf("w25 ReadByte 0x%02X done after %d ms\r\n",*pBuffer,HAL_GetTick()-StartTime);
	w25.Lock=0;
}
void 	w25_ReadBytes(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;

	// uint32_t	StartTime=HAL_GetTick();
	serial_printf("w25 ReadBytes at Address:%d, %d Bytes  begin...\r\n",ReadAddr,NumByteToRead);

	spi_chip_select();
  	timers_delay_microseconds(1);
	spi_xfer(W25_SPI, 0x0B);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (ReadAddr & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (ReadAddr & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (ReadAddr& 0xFF00) >> 8);
  spi_xfer(W25_SPI, ReadAddr & 0xFF);
	spi_xfer(W25_SPI, 0);
	// HAL_SPI_Receive(&_W25_SPI,pBuffer,NumByteToRead,2000);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);

	// StartTime = HAL_GetTick()-StartTime;
	for(uint32_t i=0;i<NumByteToRead ; i++)
	{
		if((i%8==0)&&(i>2))
		{
			serial_printf("\r\n");
			timers_delay_microseconds(10);
		}
		serial_printf("0x%02X,",pBuffer[i]);
	}
	serial_printf("\r\n");
	// serial_printf("w25 ReadBytes done after %d ms\r\n",StartTime);
	timers_delay_microseconds(100);

	timers_delay_microseconds(1);
	w25.Lock=0;
}
void 	w25_ReadPage(uint8_t *pBuffer,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_PageSize)
{
	while(w25.Lock==1)
		timers_delay_microseconds(1);
	w25.Lock=1;
	if((NumByteToRead_up_to_PageSize>w25.PageSize)||(NumByteToRead_up_to_PageSize==0))
		NumByteToRead_up_to_PageSize=w25.PageSize;
	if((OffsetInByte+NumByteToRead_up_to_PageSize) > w25.PageSize)
		NumByteToRead_up_to_PageSize = w25.PageSize-OffsetInByte;
	serial_printf("w25 ReadPage:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Page_Address,OffsetInByte,NumByteToRead_up_to_PageSize);
	// uint32_t	StartTime=HAL_GetTick();

	Page_Address = Page_Address*w25.PageSize+OffsetInByte;
	spi_chip_select();
  	timers_delay_microseconds(1);
	spi_xfer(W25_SPI, 0x0B);
	if(w25.ID>=W25Q256)
		spi_xfer(W25_SPI, (Page_Address & 0xFF000000) >> 24);
  spi_xfer(W25_SPI, (Page_Address & 0xFF0000) >> 16);
  spi_xfer(W25_SPI, (Page_Address& 0xFF00) >> 8);
  spi_xfer(W25_SPI, Page_Address & 0xFF);
	spi_xfer(W25_SPI, 0);
	// HAL_SPI_Receive(&_W25_SPI,pBuffer,NumByteToRead_up_to_PageSize,100);
	  	spi_chip_deselect();
  	timers_delay_microseconds(1);

	// StartTime = HAL_GetTick()-StartTime;
	for(uint32_t i=0;i<NumByteToRead_up_to_PageSize ; i++)
	{
		if((i%8==0)&&(i>2))
		{
			serial_printf("\r\n");
			timers_delay_microseconds(10);
		}
		serial_printf("0x%02X,",pBuffer[i]);
	}
	serial_printf("\r\n");
	// serial_printf("w25 ReadPage done after %d ms\r\n",StartTime);
	timers_delay_microseconds(100);

	timers_delay_microseconds(1);
	w25.Lock=0;
}
void 	w25_ReadSector(uint8_t *pBuffer,uint32_t Sector_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_SectorSize)
{
	if((NumByteToRead_up_to_SectorSize>w25.SectorSize)||(NumByteToRead_up_to_SectorSize==0))
		NumByteToRead_up_to_SectorSize=w25.SectorSize;
	serial_printf("+++w25 ReadSector:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Sector_Address,OffsetInByte,NumByteToRead_up_to_SectorSize);

	if(OffsetInByte>=w25.SectorSize)
	{
		serial_printf("---w25 ReadSector Faild!\r\n");

		return;
	}
	uint32_t	StartPage;
	int32_t		BytesToRead;
	uint32_t	LocalOffset;
	if((OffsetInByte+NumByteToRead_up_to_SectorSize) > w25.SectorSize)
		BytesToRead = w25.SectorSize-OffsetInByte;
	else
		BytesToRead = NumByteToRead_up_to_SectorSize;
	StartPage = w25_SectorToPage(Sector_Address)+(OffsetInByte/w25.PageSize);
	LocalOffset = OffsetInByte%w25.PageSize;
	do
	{
		w25_ReadPage(pBuffer,StartPage,LocalOffset,BytesToRead);
		StartPage++;
		BytesToRead-=w25.PageSize-LocalOffset;
		pBuffer += w25.PageSize - LocalOffset;
		LocalOffset=0;
	}while(BytesToRead>0);
	serial_printf("---w25 ReadSector Done\r\n");

}
void 	w25_ReadBlock(uint8_t* pBuffer,uint32_t Block_Address,uint32_t OffsetInByte,uint32_t	NumByteToRead_up_to_BlockSize)
{
	if((NumByteToRead_up_to_BlockSize>w25.BlockSize)||(NumByteToRead_up_to_BlockSize==0))
		NumByteToRead_up_to_BlockSize=w25.BlockSize;
	serial_printf("+++w25 ReadBlock:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Block_Address,OffsetInByte,NumByteToRead_up_to_BlockSize);

	if(OffsetInByte>=w25.BlockSize)
	{
		serial_printf("w25 ReadBlock Faild!\r\n");

		return;
	}
	uint32_t	StartPage;
	int32_t		BytesToRead;
	uint32_t	LocalOffset;
	if((OffsetInByte+NumByteToRead_up_to_BlockSize) > w25.BlockSize)
		BytesToRead = w25.BlockSize-OffsetInByte;
	else
		BytesToRead = NumByteToRead_up_to_BlockSize;
	StartPage = w25_BlockToPage(Block_Address)+(OffsetInByte/w25.PageSize);
	LocalOffset = OffsetInByte%w25.PageSize;
	do
	{
		w25_ReadPage(pBuffer,StartPage,LocalOffset,BytesToRead);
		StartPage++;
		BytesToRead-=w25.PageSize-LocalOffset;
		pBuffer += w25.PageSize - LocalOffset;
		LocalOffset=0;
	}while(BytesToRead>0);
	serial_printf("---w25 ReadBlock Done\r\n");

}

//###################################################################################################################

// Static Function Definitions

static void spi_setup(void)
{
  // Set GPIO Mode
  gpio_mode_setup(W25_SPI_MISO_PORT,  GPIO_MODE_AF,     GPIO_PUPD_NONE,   W25_SPI_MISO);

  gpio_mode_setup(W25_SPI_SCK_PORT,   GPIO_MODE_AF,     GPIO_PUPD_NONE,   W25_SPI_SCK);
  gpio_mode_setup(W25_SPI_MOSI_PORT,  GPIO_MODE_AF,     GPIO_PUPD_NONE,   W25_SPI_MOSI);
  gpio_mode_setup(W25_SPI_NSS_PORT,   GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,   W25_SPI_NSS);

  // Push Pull for outputs
  gpio_set_output_options(W25_SPI_SCK_PORT,   GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, W25_SPI_SCK);
  gpio_set_output_options(W25_SPI_MOSI_PORT,  GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, W25_SPI_MOSI);
  gpio_set_output_options(W25_SPI_NSS_PORT,   GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, W25_SPI_NSS);

  // Set NSS pin high
  gpio_set(W25_SPI_NSS_PORT, W25_SPI_NSS);

  // Set alternate function
  gpio_set_af(W25_SPI_MISO_PORT,  W25_SPI_AF, W25_SPI_MISO);

  gpio_set_af(W25_SPI_SCK_PORT,   W25_SPI_AF, W25_SPI_SCK);
  gpio_set_af(W25_SPI_MOSI_PORT,  W25_SPI_AF, W25_SPI_MOSI);

  // Init SPI
  rcc_periph_clock_enable(W25_SPI_RCC);
  rcc_periph_reset_pulse(W25_SPI_RST);
  spi_disable(W25_SPI);
  spi_init_master(W25_SPI, SPI_CR1_BAUDRATE_FPCLK_DIV_2,
                    SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1,
                    SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
  spi_enable(W25_SPI);
}
