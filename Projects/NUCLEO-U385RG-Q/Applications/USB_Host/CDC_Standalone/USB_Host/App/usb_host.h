/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : USB_Host/CDC_Standalone/USB_Host/Target/usb_host.h
  * @author         : MCD Application Team
  * @brief          : Header for usb_host.c file.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HOST__H__
#define __USB_HOST__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32u3xx.h"
#include "stm32u3xx_hal.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/** @addtogroup USBH_DRD_DRIVER
  * @{
  */

/** @defgroup USBH_HOST USBH_HOST
  * @brief Host file for Usb drd low level driver.
  * @{
  */

/** @defgroup USBH_HOST_Exported_Variables USBH_HOST_Exported_Variables
  * @brief Public variables.
  * @{
  */

/**
  * @}
  */

/** Status of the application. */
typedef enum {
  APPLICATION_IDLE = 0,
  APPLICATION_START,
  APPLICATION_READY,
  APPLICATION_DISCONNECT
}ApplicationTypeDef;

/** @defgroup USBH_HOST_Exported_FunctionsPrototype USBH_HOST_Exported_FunctionsPrototype
  * @brief Declaration of public functions for Usb host.
  * @{
  */

/* Exported functions prototypes --------------------------------------------*/

/** @brief USB Host initialization function. */
void MX_USB_HOST_Init(void);

/* USER CODE BEGIN EFP */
void CDC_Process(void);
/* USER CODE END EFP */

void MX_USB_HOST_Process(void);

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __USB_HOST__H__ */

