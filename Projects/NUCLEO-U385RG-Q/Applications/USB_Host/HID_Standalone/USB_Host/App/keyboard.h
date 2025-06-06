/**
  ******************************************************************************
  * @file    : USB_Host/HID_Standalone/USB_Host/App/keyboard.h
  * @author  : MCD Application Team
  * @brief   : This file implements the USB Host
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
#ifndef __KEYBOARD_H
#define __KEYBOARD_H

/* Includes ------------------------------------------------------------------*/
#include "usb_host.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void HID_KEYBRD_App(USBH_HandleTypeDef *phost);

#endif /* __KEYBOARD_H */

