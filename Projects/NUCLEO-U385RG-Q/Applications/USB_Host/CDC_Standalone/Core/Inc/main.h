/**
  ******************************************************************************
  * @file    USB_Host/CDC_Standalone/Core/Inc/main.h
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
#include "usbh_core.h"
#include "stm32u3xx_nucleo.h"
/* Private includes ----------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */

#define USARTx                               USART1
#define USARTx_CLK_ENABLE()                  __HAL_RCC_USART1_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()

#define USARTx_FORCE_RESET()                 __HAL_RCC_USART1_FORCE_RESET()
#define USARTx_RELEASE_RESET()               __HAL_RCC_USART1_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                        GPIO_PIN_9
#define USARTx_TX_GPIO_PORT                  GPIOA
#define USARTx_TX_AF                         GPIO_AF7_USART1
#define USARTx_RX_PIN                        GPIO_PIN_10
#define USARTx_RX_GPIO_PORT                  GPIOA
#define USARTx_RX_AF                         GPIO_AF7_USART1

/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);


/* Private defines -----------------------------------------------------------*/
#define BUTTON_KEY                      BUTTON_USER
#define BUTTON_KEY_PIN                  BUTTON_USER_PIN

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */