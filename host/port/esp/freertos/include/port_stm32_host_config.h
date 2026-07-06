#ifndef __PORT_STM32_HOST_CONFIG_H__
#define __PORT_STM32_HOST_CONFIG_H__

#include "stm32f4xx_hal.h"

/*----------------------------------------------------------
 * Slave Target
 *---------------------------------------------------------*/
#define H_SLAVE_TARGET_ESP32C6      1

/*----------------------------------------------------------
 * Transport Selection
 *---------------------------------------------------------*/
#define H_TRANSPORT_SPI             3
#define H_TRANSPORT_IN_USE          H_TRANSPORT_SPI

/*----------------------------------------------------------
 * GPIO Logic
 *---------------------------------------------------------*/
#define H_GPIO_LOW                  GPIO_PIN_RESET
#define H_GPIO_HIGH                 GPIO_PIN_SET

/*----------------------------------------------------------
 * SPI Configuration
 *---------------------------------------------------------*/
#define H_SPI_MODE                  0           // SPI Mode 0
#define H_SPI_FD_CLK_MHZ            10          // Start with 10 MHz

#define H_SPI_TX_Q                  3
#define H_SPI_RX_Q                  3

/*----------------------------------------------------------
 * SPI Peripheral
 *---------------------------------------------------------*/
#define H_SPI_HANDLE                hspi3

extern SPI_HandleTypeDef H_SPI_HANDLE;

/*----------------------------------------------------------
 * SPI Pins
 *---------------------------------------------------------*/

/* SCK */
#define H_GPIO_SCLK_Port            GPIOC
#define H_GPIO_SCLK_Pin             GPIO_PIN_10

/* MISO */
#define H_GPIO_MISO_Port            GPIOC
#define H_GPIO_MISO_Pin             GPIO_PIN_11

/* MOSI */
#define H_GPIO_MOSI_Port            GPIOC
#define H_GPIO_MOSI_Pin             GPIO_PIN_12

/* CS */
#define H_GPIO_CS_Port              GPIOA
#define H_GPIO_CS_Pin               GPIO_PIN_15

/*----------------------------------------------------------
 * ESP Hosted Handshake
 *---------------------------------------------------------*/

/* ESP -> STM32 Data Ready */
#define H_GPIO_DATA_READY_Port      GPIOB
#define H_GPIO_DATA_READY_Pin       GPIO_PIN_0

/* STM32 -> ESP Handshake */
#define H_GPIO_HANDSHAKE_Port       GPIOB
#define H_GPIO_HANDSHAKE_Pin        GPIO_PIN_1

/* ESP Reset */
#define H_GPIO_RESET_Port           GPIOB
#define H_GPIO_PIN_RESET            GPIO_PIN_2

/*----------------------------------------------------------
 * Active Levels
 *---------------------------------------------------------*/

#define H_HANDSHAKE_ACTIVE_HIGH     1
#define H_DATAREADY_ACTIVE_HIGH     1
#define H_RESET_ACTIVE_HIGH         1

#if H_HANDSHAKE_ACTIVE_HIGH
#define H_HS_VAL_ACTIVE             GPIO_PIN_SET
#define H_HS_VAL_INACTIVE           GPIO_PIN_RESET
#else
#define H_HS_VAL_ACTIVE             GPIO_PIN_RESET
#define H_HS_VAL_INACTIVE           GPIO_PIN_SET
#endif

#if H_DATAREADY_ACTIVE_HIGH
#define H_DR_VAL_ACTIVE             GPIO_PIN_SET
#define H_DR_VAL_INACTIVE           GPIO_PIN_RESET
#else
#define H_DR_VAL_ACTIVE             GPIO_PIN_RESET
#define H_DR_VAL_INACTIVE           GPIO_PIN_SET
#endif

#if H_RESET_ACTIVE_HIGH
#define H_RESET_VAL_ACTIVE          GPIO_PIN_SET
#define H_RESET_VAL_INACTIVE        GPIO_PIN_RESET
#else
#define H_RESET_VAL_ACTIVE          GPIO_PIN_RESET
#define H_RESET_VAL_INACTIVE        GPIO_PIN_SET
#endif

/*----------------------------------------------------------
 * Timeouts
 *---------------------------------------------------------*/

#define TIMEOUT_PSERIAL_RESP        30

/*----------------------------------------------------------
 * Features
 *---------------------------------------------------------*/

#define H_USE_MEMPOOL               1
#define H_MEM_MONITOR               0
#define H_HOST_USES_STATIC_NETIF    0

#endif
