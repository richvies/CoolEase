/**
 ******************************************************************************
 * @file    w25qxx.h
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   W25Q Flash Memory Driver Header File
 *
 * @defgroup hub Hub
 * @{
 *   @defgroup flash_api Flash Memory Interface
 *   @brief    W25Q series SPI flash memory driver interface
 * @}
 ******************************************************************************
 */

#ifndef W25_H
#define W25_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup hub
 * @{
 */

/** @addtogroup flash_api
 * @{
 */

/**
 * @brief Flash memory chip identifier enumeration
 */
typedef enum {
    W25Q10 = 1, /**< W25Q10 chip */
    W25Q20,     /**< W25Q20 chip */
    W25Q40,     /**< W25Q40 chip */
    W25Q80,     /**< W25Q80 chip */
    W25Q16,     /**< W25Q16 chip */
    W25Q32,     /**< W25Q32 chip */
    W25Q64,     /**< W25Q64 chip */
    W25Q128,    /**< W25Q128 chip */
    W25Q256,    /**< W25Q256 chip */
    W25Q512,    /**< W25Q512 chip */
} W25_ID_t;

/**
 * @brief Flash memory device structure
 */
typedef struct {
    W25_ID_t ID;                 /**< Chip identifier */
    uint8_t  UniqID[8];          /**< Unique identifier */
    uint16_t PageSize;           /**< Size of a page in bytes */
    uint32_t PageCount;          /**< Number of pages */
    uint32_t SectorSize;         /**< Size of a sector in bytes */
    uint32_t SectorCount;        /**< Number of sectors */
    uint32_t BlockSize;          /**< Size of a block in bytes */
    uint32_t BlockCount;         /**< Number of blocks */
    uint32_t CapacityInKiloByte; /**< Total capacity in kilobytes */
    uint8_t  StatusRegister1;    /**< Status register 1 value */
    uint8_t  StatusRegister2;    /**< Status register 2 value */
    uint8_t  StatusRegister3;    /**< Status register 3 value */
    uint8_t  Lock;               /**< Lock status */
} w25_t;

/**
 * @brief Global flash memory device instance
 */
extern w25_t w25;

/**
 * @brief Initialize flash memory device
 * @note For Page, Sector, and Block read/write functions, use 0 to read maximum
 * bytes
 * @return true if initialization successful, false otherwise
 */
bool w25_Init(void);

/**
 * @brief Read flash memory device ID
 * @return Device ID value
 */
uint32_t w25_ReadID(void);

/**
 * @brief Read unique ID from flash memory
 * @return None
 */
void w25_ReadUniqID(void);

/**
 * @brief Enable write operations
 * @return None
 */
void w25_WriteEnable(void);

/**
 * @brief Disable write operations
 * @return None
 */
void w25_WriteDisable(void);

/**
 * @brief Wait for write operation to complete
 * @return None
 */
void w25_WaitForWriteEnd(void);

/**
 * @brief Read status register
 * @param SelectStatusRegister_1_2_3 Register number (1-3)
 * @return Register value
 */
uint8_t w25_ReadStatusRegister(uint8_t SelectStatusRegister_1_2_3);

/**
 * @brief Write to status register
 * @param SelectStatusRegister_1_2_3 Register number (1-3)
 * @param Data Value to write
 * @return None
 */
void w25_WriteStatusRegister(uint8_t SelectStatusRegister_1_2_3, uint8_t Data);

/**
 * @brief Erase entire chip
 * @return None
 */
void w25_EraseChip(void);

/**
 * @brief Erase a sector
 * @param SectorAddr Sector address
 * @return None
 */
void w25_EraseSector(uint32_t SectorAddr);

/**
 * @brief Erase a block
 * @param BlockAddr Block address
 * @return None
 */
void w25_EraseBlock(uint32_t BlockAddr);

/**
 * @brief Convert page address to sector address
 * @param PageAddress Page address
 * @return Sector address
 */
uint32_t w25_PageToSector(uint32_t PageAddress);

/**
 * @brief Convert page address to block address
 * @param PageAddress Page address
 * @return Block address
 */
uint32_t w25_PageToBlock(uint32_t PageAddress);

/**
 * @brief Convert sector address to block address
 * @param SectorAddress Sector address
 * @return Block address
 */
uint32_t w25_SectorToBlock(uint32_t SectorAddress);

/**
 * @brief Convert sector address to page address
 * @param SectorAddress Sector address
 * @return Page address
 */
uint32_t w25_SectorToPage(uint32_t SectorAddress);

/**
 * @brief Convert block address to page address
 * @param BlockAddress Block address
 * @return Page address
 */
uint32_t w25_BlockToPage(uint32_t BlockAddress);

/**
 * @brief Check if a page is empty
 * @param Page_Address Page address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToCheck_up_to_PageSize Number of bytes to check (up to page
 * size)
 * @return true if empty, false otherwise
 */
bool w25_IsEmptyPage(uint32_t Page_Address, uint32_t OffsetInByte,
                     uint32_t NumByteToCheck_up_to_PageSize);

/**
 * @brief Check if a sector is empty
 * @param Sector_Address Sector address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToCheck_up_to_SectorSize Number of bytes to check (up to sector
 * size)
 * @return true if empty, false otherwise
 */
bool w25_IsEmptySector(uint32_t Sector_Address, uint32_t OffsetInByte,
                       uint32_t NumByteToCheck_up_to_SectorSize);

/**
 * @brief Check if a block is empty
 * @param Block_Address Block address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToCheck_up_to_BlockSize Number of bytes to check (up to block
 * size)
 * @return true if empty, false otherwise
 */
bool w25_IsEmptyBlock(uint32_t Block_Address, uint32_t OffsetInByte,
                      uint32_t NumByteToCheck_up_to_BlockSize);

/**
 * @brief Write a single byte
 * @param pBuffer Byte to write
 * @param Bytes_Address Address to write to
 * @return None
 */
void w25_WriteByte(uint8_t pBuffer, uint32_t Bytes_Address);

/**
 * @brief Write data to a page
 * @param pBuffer Data buffer
 * @param Page_Address Page address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToWrite_up_to_PageSize Number of bytes to write (up to page
 * size)
 * @return None
 */
void w25_WritePage(uint8_t* pBuffer, uint32_t Page_Address,
                   uint32_t OffsetInByte,
                   uint32_t NumByteToWrite_up_to_PageSize);

/**
 * @brief Write data to a sector
 * @param pBuffer Data buffer
 * @param Sector_Address Sector address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToWrite_up_to_SectorSize Number of bytes to write (up to sector
 * size)
 * @return None
 */
void w25_WriteSector(uint8_t* pBuffer, uint32_t Sector_Address,
                     uint32_t OffsetInByte,
                     uint32_t NumByteToWrite_up_to_SectorSize);

/**
 * @brief Write data to a block
 * @param pBuffer Data buffer
 * @param Block_Address Block address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToWrite_up_to_BlockSize Number of bytes to write (up to block
 * size)
 * @return None
 */
void w25_WriteBlock(uint8_t* pBuffer, uint32_t Block_Address,
                    uint32_t OffsetInByte,
                    uint32_t NumByteToWrite_up_to_BlockSize);

/**
 * @brief Read a single byte
 * @param pBuffer Buffer to store read byte
 * @param Bytes_Address Address to read from
 * @return None
 */
void w25_ReadByte(uint8_t* pBuffer, uint32_t Bytes_Address);

/**
 * @brief Read multiple bytes
 * @param pBuffer Buffer to store read bytes
 * @param ReadAddr Address to read from
 * @param NumByteToRead Number of bytes to read
 * @return None
 */
void w25_ReadBytes(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);

/**
 * @brief Read data from a page
 * @param pBuffer Buffer to store read data
 * @param Page_Address Page address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToRead_up_to_PageSize Number of bytes to read (up to page size)
 * @return None
 */
void w25_ReadPage(uint8_t* pBuffer, uint32_t Page_Address,
                  uint32_t OffsetInByte, uint32_t NumByteToRead_up_to_PageSize);

/**
 * @brief Read data from a sector
 * @param pBuffer Buffer to store read data
 * @param Sector_Address Sector address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToRead_up_to_SectorSize Number of bytes to read (up to sector
 * size)
 * @return None
 */
void w25_ReadSector(uint8_t* pBuffer, uint32_t Sector_Address,
                    uint32_t OffsetInByte,
                    uint32_t NumByteToRead_up_to_SectorSize);

/**
 * @brief Read data from a block
 * @param pBuffer Buffer to store read data
 * @param Block_Address Block address
 * @param OffsetInByte Offset in bytes
 * @param NumByteToRead_up_to_BlockSize Number of bytes to read (up to block
 * size)
 * @return None
 */
void w25_ReadBlock(uint8_t* pBuffer, uint32_t Block_Address,
                   uint32_t OffsetInByte,
                   uint32_t NumByteToRead_up_to_BlockSize);

/** @} */ /* End of flash_api group */
/** @} */ /* End of hub group */

#ifdef __cplusplus
}
#endif

#endif // W25_H
