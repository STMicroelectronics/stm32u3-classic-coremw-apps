/**
  ******************************************************************************
  * @file    USB_Device/CDC_Standalone/Core/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u3xx_hal.h"
#include "stm32u3xx_ll_crs.h"
#include "stm32u3xx_ll_bus.h"
#include "stm32u3xx_ll_pwr.h"
#include "stm32u3xx_ll_system.h"
#include "stm32u3xx_ll_utils.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"
#include "stm32u3xx_nucleo.h"
/* Private includes ----------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private defines -----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */