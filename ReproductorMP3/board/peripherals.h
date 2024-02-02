/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_edma.h"
#include "fsl_dmamux.h"
#include "stdlib.h"
#include "fsl_common.h"
#include "fsl_dac.h"
#include "fsl_pit.h"
#include "fsl_uart.h"
#include "fsl_clock.h"
#include "ff.h"
#include "diskio.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Used DMA device. */
#define DMA_DMA_BASEADDR DMA0
/* Associated DMAMUX device that is used for muxing of requests. */
#define DMA_DMAMUX_BASEADDR DMAMUX

  /* Channel CH3 definitions */
/* DMA eDMA source request. */
#define DMA_CH3_DMA_REQUEST kDmaRequestMux0AlwaysOn58
/* Selected eDMA channel number. */
#define DMA_CH3_DMA_CHANNEL 3
/* TCD pool size */
#define DMA_CH3_TCD_SIZE 2
/* DMA interrupt vector ID (number). */
#define DMA_DMA_CH_INT_DONE_3_IRQN DMA3_IRQn

  /* Channel CH0 definitions */
/* DMA eDMA source request. */
#define DMA_CH0_DMA_REQUEST kDmaRequestMux0FTM0Channel0
/* Selected eDMA channel number. */
#define DMA_CH0_DMA_CHANNEL 0
/* DMA interrupt vector ID (number). */
#define DMA_DMA_CH_INT_DONE_0_IRQN DMA0_IRQn
/* Alias for DAC0 peripheral */
#define DAC0_PERIPHERAL DAC0
/* BOARD_InitPeripherals defines for PIT */
/* Definition of peripheral ID. */
#define PIT_PERIPHERAL PIT
/* Definition of clock source. */
#define PIT_CLOCK_SOURCE kCLOCK_BusClk
/* Definition of clock source frequency. */
#define PIT_CLK_FREQ 50000000UL
/* Definition of ticks count for channel 3 - deprecated. */
#define PIT_3_TICKS 1134U
/* Definition of channel number for channel 3. */
#define PIT_CHANNEL_3 kPIT_Chnl_3
/* Definition of ticks count for channel 3. */
#define PIT_CHANNEL_3_TICKS 1134U
/* Definition of peripheral ID */
#define UART0_PERIPHERAL UART0
/* Definition of the clock source frequency */
#define UART0_CLOCK_SOURCE CLOCK_GetFreq(UART0_CLK_SRC)
/* Debug console is initialized in the peripheral tool */
#define BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL 

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const edma_config_t DMA_config;
/* Source address extern definition */
extern int16_t pingBuffer[1152];
/* Source address extern definition */
extern int16_t pongBuffer[1152];
/* Source address extern definition */
extern uint16_t *waveform
extern edma_handle_t DMA_CH3_Handle;
/* Transactional transfer configuration */
extern edma_transfer_config_t DMA_CH0_PING_config;
/* Transactional transfer configuration */
extern edma_transfer_config_t DMA_CH0_PONG_config;
extern edma_handle_t DMA_CH0_Handle;
/* Transactional transfer configuration */
extern edma_transfer_config_t DMA_CH0_TRANSFER_config;
extern const dac_config_t DAC0_config;
extern const pit_config_t PIT_config;
extern const uart_config_t UART0_config;

/***********************************************************************************************************************
 * Callback functions
 **********************************************************************************************************************/
/* eDMA callback function for the 3 channel.*/
extern void DMA_callback(edma_handle_t*, void*, bool, uint32_t);
/* eDMA callback function for the 0 channel.*/
extern void DMA_callback_CH0(edma_handle_t*, void*, bool, uint32_t);

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
