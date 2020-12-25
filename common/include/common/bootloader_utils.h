/********************************************************************************
 * @file    bootloader_utils.h
 * @author  Richard Davies
 * @brief   CoolEase Hub Main Function
 *
 * Function for jumping from bootloader code to application code.
 */

#ifndef BOOTLOADER_UTILS_H
#define BOOTLOADER_UTILS_H   

void boot_deinit();
void boot_jump(uint32_t address);

#endif