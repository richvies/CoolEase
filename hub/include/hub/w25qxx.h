#ifndef W25_H
#define W25_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    W25Q10 = 1,
    W25Q20,
    W25Q40,
    W25Q80,
    W25Q16,
    W25Q32,
    W25Q64,
    W25Q128,
    W25Q256,
    W25Q512,

} W25_ID_t;

typedef struct {
    W25_ID_t ID;
    uint8_t  UniqID[8];
    uint16_t PageSize;
    uint32_t PageCount;
    uint32_t SectorSize;
    uint32_t SectorCount;
    uint32_t BlockSize;
    uint32_t BlockCount;
    uint32_t CapacityInKiloByte;
    uint8_t  StatusRegister1;
    uint8_t  StatusRegister2;
    uint8_t  StatusRegister3;
    uint8_t  Lock;

} w25_t;

extern w25_t w25;
// ############################################################################
//  in Page,Sector and block read/write functions, can put 0 to read maximum
//  bytes
// ############################################################################
bool w25_Init(void);

// ###################################################################################################################

uint32_t w25_ReadID(void);
void     w25_ReadUniqID(void);
void     w25_WriteEnable(void);
void     w25_WriteDisable(void);
void     w25_WaitForWriteEnd(void);
uint8_t  w25_ReadStatusRegister(uint8_t SelectStatusRegister_1_2_3);
void w25_WriteStatusRegister(uint8_t SelectStatusRegister_1_2_3, uint8_t Data);

void w25_EraseChip(void);
void w25_EraseSector(uint32_t SectorAddr);
void w25_EraseBlock(uint32_t BlockAddr);

uint32_t w25_PageToSector(uint32_t PageAddress);
uint32_t w25_PageToBlock(uint32_t PageAddress);
uint32_t w25_SectorToBlock(uint32_t SectorAddress);
uint32_t w25_SectorToPage(uint32_t SectorAddress);
uint32_t w25_BlockToPage(uint32_t BlockAddress);

bool w25_IsEmptyPage(uint32_t Page_Address, uint32_t OffsetInByte,
                     uint32_t NumByteToCheck_up_to_PageSize);
bool w25_IsEmptySector(uint32_t Sector_Address, uint32_t OffsetInByte,
                       uint32_t NumByteToCheck_up_to_SectorSize);
bool w25_IsEmptyBlock(uint32_t Block_Address, uint32_t OffsetInByte,
                      uint32_t NumByteToCheck_up_to_BlockSize);

void w25_WriteByte(uint8_t pBuffer, uint32_t Bytes_Address);
void w25_WritePage(uint8_t* pBuffer, uint32_t Page_Address,
                   uint32_t OffsetInByte,
                   uint32_t NumByteToWrite_up_to_PageSize);
void w25_WriteSector(uint8_t* pBuffer, uint32_t Sector_Address,
                     uint32_t OffsetInByte,
                     uint32_t NumByteToWrite_up_to_SectorSize);
void w25_WriteBlock(uint8_t* pBuffer, uint32_t Block_Address,
                    uint32_t OffsetInByte,
                    uint32_t NumByteToWrite_up_to_BlockSize);

void w25_ReadByte(uint8_t* pBuffer, uint32_t Bytes_Address);
void w25_ReadBytes(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);
void w25_ReadPage(uint8_t* pBuffer, uint32_t Page_Address,
                  uint32_t OffsetInByte, uint32_t NumByteToRead_up_to_PageSize);
void w25_ReadSector(uint8_t* pBuffer, uint32_t Sector_Address,
                    uint32_t OffsetInByte,
                    uint32_t NumByteToRead_up_to_SectorSize);
void w25_ReadBlock(uint8_t* pBuffer, uint32_t Block_Address,
                   uint32_t OffsetInByte,
                   uint32_t NumByteToRead_up_to_BlockSize);
// ############################################################################

#endif
