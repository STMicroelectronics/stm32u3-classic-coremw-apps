/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         USB_Device/CDC_Standalone/Core/Src/stm32u3xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */
/**
  * @brief ADC MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  if(hadc->Instance==ADC2)
  {
    __HAL_RCC_ADC12_CLK_ENABLE();
    /* USER CODE BEGIN ADC1_MspInit 0 */
    LL_AHB1_GRP2_EnableClock(LL_AHB1_GRP2_PERIPH_PWR);
    LL_PWR_EnableVDDA();
    LL_ADC_DisableDeepPowerDown(ADC1);
    LL_ADC_Enable(ADC1);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_ADC12);
    LL_AHB2_GRP1_EnableClockSleep(LL_AHB2_GRP1_PERIPH_ADC12);
    /* USER CODE END ADC1_MspInit 0 */

    __HAL_RCC_GPIOC_CLK_ENABLE();

    /**ADC1 GPIO Configuration
    PB0     ------> ADC1_IN17
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* USER CODE BEGIN ADC1_MspInit 1 */

    /* USER CODE END ADC1_MspInit 1 */
  }
}

/**
  * @brief ADC MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance==ADC2)
  {
    /* USER CODE BEGIN ADC1_MspDeInit 0 */

    /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC12_CLK_DISABLE();

    /**ADC1 GPIO Configuration
    PB0     ------> ADC1_IN17
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_2);

    /* ADC1 DMA DeInit */

    /* USER CODE BEGIN ADC1_MspDeInit 1 */

    /* USER CODE END ADC1_MspDeInit 1 */
  }
}

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this application:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - NVIC configuration for UART interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef * huart)
{
  static DMA_HandleTypeDef hdma_tx;
  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;

  /* ##-1- Enable peripherals and GPIO Clocks #################################
   */
  /* Enable GPIO clock */
  USARTx_TX_GPIO_CLK_ENABLE();
  USARTx_RX_GPIO_CLK_ENABLE();

  /* Select SysClk as source of USART1 clocks */
  RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  RCC_PeriphClkInit.Usart1ClockSelection  = RCC_USART1CLKSOURCE_PCLK2;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);

  /* Enable USARTx clock */
  USARTx_CLK_ENABLE();

  /* Enable DMAx clock */
  DMAx_CLK_ENABLE();

  /* ##-2- Configure peripheral GPIO ##########################################
   */
  /* UART TX GPIO pin configuration */
  GPIO_InitStruct.Pin = USARTx_TX_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = USARTx_TX_AF;

  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration */
  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Alternate = USARTx_RX_AF;

  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /* ##-4- Configure the DMA streams ##########################################
   */
  /* Configure the DMA handler for Transmission process */
  hdma_tx.Init.Request               = USARTx_TX_GPDMA_REQUEST;
  hdma_tx.Init.BlkHWRequest          = DMA_BREQ_SINGLE_BURST;
  hdma_tx.Init.Direction             = DMA_MEMORY_TO_PERIPH;
  hdma_tx.Init.SrcInc                = DMA_SINC_INCREMENTED;
  hdma_tx.Init.DestInc               = DMA_DINC_FIXED;
  hdma_tx.Init.SrcDataWidth          = DMA_SRC_DATAWIDTH_BYTE;
  hdma_tx.Init.DestDataWidth         = DMA_DEST_DATAWIDTH_BYTE;
  hdma_tx.Init.Mode                  = DMA_NORMAL;
  hdma_tx.Init.Priority              = DMA_LOW_PRIORITY_LOW_WEIGHT;
  hdma_tx.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0 | DMA_DEST_ALLOCATED_PORT0;
  hdma_tx.Init.TransferEventMode     = DMA_TCEM_BLOCK_TRANSFER;

  hdma_tx.Init.SrcBurstLength        = 1;
  hdma_tx.Init.DestBurstLength       = 1;
  hdma_tx.Instance                   = (DMA_Channel_TypeDef*) USARTx_TX_GPDMA_CHANNEL;
  if (HAL_DMA_Init(&hdma_tx) != HAL_OK)
  {
    Error_Handler();
  }

  /* Associate the initialized DMA handle to the UART handle */
  __HAL_LINKDMA(huart, hdmatx, hdma_tx);

  /* ##-5- Configure the NVIC for DMA #########################################
   */
  /* NVIC configuration for DMA transfer complete interrupt (USARTx_TX) */
  HAL_NVIC_SetPriority(USARTx_GPDMA_TX_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USARTx_GPDMA_TX_IRQn);

  /* ##-6- Configure the NVIC for UART ########################################
   */
  HAL_NVIC_SetPriority(USARTx_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(USARTx_IRQn);

  /* ##-7- Enable TIM peripherals Clock #######################################
   */
  TIMx_CLK_ENABLE();

  /* ##-8- Configure the NVIC for TIMx ########################################
   */
  /* Set Interrupt Group Priority */
  HAL_NVIC_SetPriority(TIMx_IRQn, 6, 0);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIMx_IRQn);
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this application:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef * huart)
{
  /* ##-1- Reset peripherals ##################################################
   */
  USARTx_FORCE_RESET();
  USARTx_RELEASE_RESET();

  /* ##-2- Disable peripherals and GPIO Clocks ################################
   */
  /* Configure UART Tx as alternate function */
  HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
  /* Configure UART Rx as alternate function */
  HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);

  /* ##-3- Disable the NVIC for UART ##########################################
   */
  HAL_NVIC_DisableIRQ(USARTx_IRQn);

  /* ##-4- Reset TIM peripheral ###############################################
   */
  TIMx_FORCE_RESET();
  TIMx_RELEASE_RESET();
}
