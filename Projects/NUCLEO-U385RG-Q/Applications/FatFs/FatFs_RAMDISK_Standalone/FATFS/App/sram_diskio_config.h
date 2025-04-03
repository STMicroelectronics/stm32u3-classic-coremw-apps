/**
  ******************************************************************************
  * @file    sram_diskio_config.h
  * @author  MCD Application Team
  * @brief   Header for the sram_diskio_config.h
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the st_license.txt
  * file in the root directory of this software component.
  * If no st_license.txt file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef __SRAM_DISKIO_CONFIG_H
#define __SRAM_DISKIO_CONFIG_H


#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "stm32u385xx.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Block size */
#define BLOCK_SIZE                512U

/* Base Address */
#define SRAM_DISK_BASE_ADDR       0x20008000U

/* SRAM Disk size in bytes */
#define SRAM_DISK_SIZE            (96U * 1024U)


#ifdef __cplusplus
}
#endif

#endif /* __SRAM_DISKIO_CONFIG_H */