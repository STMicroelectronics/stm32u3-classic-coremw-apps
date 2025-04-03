### <b>CDC_Standalone Application Description</b>

This application is a part of the USB Host Library package using STM32Cube firmware. It describes how to use
USB host application based on the Communication Class (CDC) on the stm32u3xx devices.

This is a typical application on how to use the stm32u3xx USB DRD Host peripheral to operate with an USB
CDC device application based on the two CDC transfer directions with a dynamic serial configuration:

 - Transmission:
   by pressing the user button a message "USB_STM32_Host_CDC_ACM" will be sent from the host to a device and this message will be displayed in the hyper terminal of the device in hyperterminal
   The data to be transmitted is stored in the CDC_TX_Buffer and can be viewed via the Hyperterminal.

 - Reception:
   The data entered by the user using the Hyperterminal in ASCII format is transferred by the device board
   to the host board and displayed on the hyperterminal on the host side.
   The CDC_RX_Buffer is the buffer used for receiving data.

#### <b>Expected success behavior</b>

When plugged to PC host, the NUCLEO-U385RG-Q must be properly enumerated as an USB Serial device and an STlink COM port.
During the enumeration phase, the device must provide host with the requested descriptors (Device descriptor, configuration descriptor, string descriptors).
Those descriptors are used by host driver to identify the device capabilities. Once NUCLEO-U385RG-Q USB device successfully completed the enumeration phase,
open two hyperterminals (USB com port and UART com port(USB STLink VCP)) to send/receive data to/from host from/to device.

#### <b>Error behaviors</b>

Host PC shows that USB device does not operate as designed (CDC Device enumeration failed, PC and Device can not communicate over VCP ports).

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" specification and CDC class specification.

#### <b>Known limitations</b>

None

#### Notes
 1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

 2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

For more details about the STM32Cube USB Host library, please refer to UM1720
"STM32Cube USB Host library".

### Keywords

Standalone, USBX Host, USB, UART, Full Speed, High Speed, CDC, HyperTerminal, VCP, Com port


### Directory contents

  - USB_Host/CDC_Standalone/Core/Src/main.c                        Main program
  - USB_Host/CDC_Standalone/Core/Src/stm32u3xx_hal_msp.c           HAL MSP Module
  - USB_Host/CDC_Standalone/Core/Src/system_stm32u3xx.c            STM32U3xx system clock configuration file
  - USB_Host/CDC_Standalone/Core/Src/stm32u3xx_it.c                Interrupt handlers
  - USB_Host/CDC_Standalone/Core/Inc/main.h                        Main program header file
  - USB_Host/CDC_Standalone/Core/Inc/stm32u3xx_it.h                Interrupt handlers header file
  - USB_Host/CDC_Standalone/Core/Inc/stm32u3xx_nucleo_conf.h       Nucleo board configuration file 
  - USB_Host/CDC_Standalone/Core/Inc/stm32u3xx_hal_conf.h          HAL configuration file
  - USB_Host/CDC_Standalone/USB_Host/App/usb_host.c                USB Host implement file
  - USB_Host/CDC_Standalone/USB_Host/App/cdc_receive.c             CDC Receive state machine file
  - USB_Host/CDC_Standalone/USB_Host/App/cdc_send.c                CDC Send state machine file
  - USB_Host/CDC_Standalone/USB_Host/App/usb_host.h                USB Host implement Header file
  - USB_Host/CDC_Standalone/USB_Host/App/cdc_receive.h             CDC Receive state machine Header file
  - USB_Host/CDC_Standalone/USB_Host/App/cdc_send.h                CDC Send state machine Header file
  - USB_Host/CDC_Standalone/USB_Host/Target/usbh_conf.c            General low level driver configuration
  - USB_Host/CDC_Standalone/USB_Host/Target/usbh_conf.h            USB Host driver configuration file

### Hardware and Software environment

  - This application runs on STM32U385xx devices.

  - This application has been tested with STMicroelectronics NUCLEO-U385RG-Q boards revision: MB1841-U385RGQ-D01
    and can be easily tailored to any other supported device and development board.

  - NUCLEO-U385RG-Q Set-up
    - Plug the USB CDC device into the NUCLEO-U385RG-Q board through 'USB micro A-Male to A-Female' cable to the connector:
      - CN3 : to use USB High Speed DRD IP
    - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal.

    A virtual COM port will then appear in the HyperTerminal:
     - Hyperterminal configuration
       - Data Length = 8 Bits
       - One Stop Bit
       - No parity
       - BaudRate = 115200 baud
       - Flow control: None

    A second virtual COM port will then appear in the HyperTerminal when plugging the device:
     - Hyperterminal configuration
       - Data Length = 8 Bits
       - One Stop Bit
       - No parity
       - BaudRate = 115200 baud
       - Flow control: None

     - To send data from the USB CDC_Standalone Host use the user push-button and data will be received
       and displayed in the HyperTerminal connected to the CDC Device.

### How to use it ?

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application

#### Notes

The user has to check the list of the COM ports in Device Manager to find out the number of the COM ports that have been assigned (by OS) to the Stlink VCP.
