/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v13.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 14.0.0
board: FRDM-K64F
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 9496ff68-fbe8-4243-ae2a-46321a563f27
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DMA initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DMA'
- type: 'edma'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'edma_46976c94302ab714c0d335f519487c8a'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DMA'
- config_sets:
  - fsl_edma:
    - common_settings:
      - enableMinorLoopMapping: 'false'
      - enableContinuousLinkMode: 'false'
      - enableHaltOnError: 'true'
      - ERCA: 'fixedPriority'
      - enableDebugMode: 'false'
    - dma_table:
      - 0: []
      - 1: []
    - edma_channels:
      - 0:
        - apiMode: 'trans'
        - edma_channel:
          - channel_prefix_id: 'CH3'
          - uid: '1706581251721'
          - eDMAn: '3'
          - eDMA_source: 'kDmaRequestMux0AlwaysOn58'
          - enableTriggerPIT: 'true'
          - init_channel_priority: 'false'
          - edma_channel_Preemption:
            - enableChannelPreemption: 'false'
            - enablePreemptAbility: 'false'
            - channelPriority: '0'
          - enable_custom_name: 'false'
        - enableChannelRequest: 'false'
        - tcd_pool_enable: 'true'
        - tcd_settings:
          - tcd_size: '2'
          - tcd_memory_custom_id: 'false'
        - transfer_config:
          - 0:
            - uid: '1706581251724'
            - tcdID: 'CH0_PING'
            - ssize: 'kEDMA_TransferSize2Bytes'
            - saddr_expr: 'pingBuffer'
            - saddr_def: 'extern int16_t pingBuffer[1152];'
            - soff: '2'
            - soff_def: ''
            - dsize: 'kEDMA_TransferSize2Bytes'
            - daddr_expr: '&DAC0->DAT[0].DATL'
            - daddr_def: ''
            - doff: '0'
            - doff_def: ''
            - nbytes: '2'
            - transferBytes: '2304'
            - submitTransfer: 'false'
          - 1:
            - uid: '1706581251726'
            - tcdID: 'CH0_PONG'
            - ssize: 'kEDMA_TransferSize2Bytes'
            - saddr_expr: 'pongBuffer'
            - saddr_def: 'extern int16_t pongBuffer[1152];'
            - soff: '2'
            - soff_def: ''
            - dsize: 'kEDMA_TransferSize2Bytes'
            - daddr_expr: '&DAC0->DAT[0].DATL'
            - daddr_def: ''
            - doff: '0'
            - doff_def: ''
            - nbytes: '2'
            - transferBytes: '2304'
            - submitTransfer: 'false'
        - no_init_uid: '1706581251728'
        - init_callback: 'true'
        - callback_function: 'DMA_callback'
        - callback_user_data: ''
        - channel_enabled_interrupts: ''
        - interrupt_channel:
          - IRQn: 'DMA3_IRQn'
          - enable_priority: 'false'
          - priority: '0'
      - 1:
        - apiMode: 'trans'
        - edma_channel:
          - channel_prefix_id: 'CH0'
          - uid: '1706585616750'
          - eDMAn: '0'
          - eDMA_source: 'kDmaRequestMux0FTM0Channel0'
          - enableTriggerPIT: 'false'
          - init_channel_priority: 'false'
          - edma_channel_Preemption:
            - enableChannelPreemption: 'false'
            - enablePreemptAbility: 'false'
            - channelPriority: '0'
          - enable_custom_name: 'false'
        - enableChannelRequest: 'false'
        - tcd_pool_enable: 'false'
        - tcd_settings:
          - tcd_size: '1'
          - tcd_memory_custom_id: 'false'
        - transfer_config:
          - 0:
            - uid: '1706903627527'
            - tcdID: 'CH0_TRANSFER'
            - ssize: 'kEDMA_TransferSize2Bytes'
            - saddr_expr: '(uint32_t *)waveform'
            - saddr_def: 'extern uint16_t *waveform'
            - soff: '2'
            - soff_def: ''
            - dsize: 'kEDMA_TransferSize2Bytes'
            - daddr_expr: '(uint32_t) & (FTM0->CONTROLS[FTM_CH_0].CnV)'
            - daddr_def: ''
            - doff: '0'
            - doff_def: ''
            - nbytes: '2'
            - transferBytes: '2'
            - submitTransfer: 'false'
        - no_init_uid: '1706585616758'
        - init_callback: 'true'
        - callback_function: 'DMA_callback_CH0'
        - callback_user_data: ''
        - channel_enabled_interrupts: ''
        - interrupt_channel:
          - IRQn: 'DMA0_IRQn'
          - enable_priority: 'false'
          - priority: '0'
    - errInterruptConfig:
      - enableErrInterrupt: 'false'
      - errorInterrupt:
        - IRQn: 'DMA_Error_IRQn'
        - enable_interrrupt: 'enabled'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const edma_config_t DMA_config = {
  .enableContinuousLinkMode = false,
  .enableHaltOnError = true,
  .enableRoundRobinArbitration = false,
  .enableDebugMode = false
};
/* Tansactional transfer configuration */
edma_transfer_config_t DMA_CH0_PING_config;
/* Tansactional transfer configuration */
edma_transfer_config_t DMA_CH0_PONG_config;
/* Tansactional transfer configuration */
edma_transfer_config_t DMA_CH0_TRANSFER_config;
edma_handle_t DMA_CH3_Handle;
/* TCD pool initialization */
edma_tcd_t * DMA_CH3_TCD_pool_ptr;
edma_handle_t DMA_CH0_Handle;

static void DMA_init(void) {
  /* DMA minor loop mapping */
  EDMA_EnableMinorLoopMapping(DMA_DMA_BASEADDR, false);

  /* Channel CH3 initialization */
  /* Set the source kDmaRequestMux0AlwaysOn58 request in the DMAMUX */
  DMAMUX_SetSource(DMA_DMAMUX_BASEADDR, DMA_CH3_DMA_CHANNEL, DMA_CH3_DMA_REQUEST);
  /* Set the DMA channel 3 periodic trigger */
  DMAMUX_EnablePeriodTrigger(DMA_DMAMUX_BASEADDR, DMA_CH3_DMA_CHANNEL);
  /* Enable the channel 3 in the DMAMUX */
  DMAMUX_EnableChannel(DMA_DMAMUX_BASEADDR, DMA_CH3_DMA_CHANNEL);
  /* Create the eDMA DMA_CH3_Handle handle */
  EDMA_CreateHandle(&DMA_CH3_Handle, DMA_DMA_BASEADDR, DMA_CH3_DMA_CHANNEL);
  /* Allocate TCD memory pool for scatter-gather mode*/
  DMA_CH3_TCD_pool_ptr = (edma_tcd_t *)malloc(sizeof(edma_tcd_t) * (DMA_CH3_TCD_SIZE + 1));
  if (DMA_CH3_TCD_pool_ptr != NULL) {
    EDMA_InstallTCDMemory(&DMA_CH3_Handle, (edma_tcd_t *)((uint32_t)(DMA_CH3_TCD_pool_ptr + 1) & (~0x1FU)), DMA_CH3_TCD_SIZE);
  }
  /* DMA callback initialization */
  EDMA_SetCallback(&DMA_CH3_Handle, DMA_callback, NULL);
  /* DMA transfer CH0_PING configuration */
  EDMA_PrepareTransferConfig(&DMA_CH0_PING_config, (void *) pingBuffer, 1 << kEDMA_TransferSize2Bytes, 2, (void *) &DAC0->DAT[0].DATL, 1 << kEDMA_TransferSize2Bytes, 0, 2U, 2304U); 
  /* DMA transfer CH0_PONG configuration */
  EDMA_PrepareTransferConfig(&DMA_CH0_PONG_config, (void *) pongBuffer, 1 << kEDMA_TransferSize2Bytes, 2, (void *) &DAC0->DAT[0].DATL, 1 << kEDMA_TransferSize2Bytes, 0, 2U, 2304U); 

  /* Channel CH0 initialization */
  /* Set the source kDmaRequestMux0FTM0Channel0 request in the DMAMUX */
  DMAMUX_SetSource(DMA_DMAMUX_BASEADDR, DMA_CH0_DMA_CHANNEL, DMA_CH0_DMA_REQUEST);
  /* Enable the channel 0 in the DMAMUX */
  DMAMUX_EnableChannel(DMA_DMAMUX_BASEADDR, DMA_CH0_DMA_CHANNEL);
  /* Create the eDMA DMA_CH0_Handle handle */
  EDMA_CreateHandle(&DMA_CH0_Handle, DMA_DMA_BASEADDR, DMA_CH0_DMA_CHANNEL);
  /* DMA callback initialization */
  EDMA_SetCallback(&DMA_CH0_Handle, DMA_callback_CH0, NULL);
  /* DMA transfer CH0_TRANSFER configuration */
  EDMA_PrepareTransferConfig(&DMA_CH0_TRANSFER_config, (void *) (uint32_t *)waveform, 1 << kEDMA_TransferSize2Bytes, 2, (void *) (uint32_t) & (FTM0->CONTROLS[FTM_CH_0].CnV), 1 << kEDMA_TransferSize2Bytes, 0, 2U, 2U); 
}

/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
      - 1: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * DAC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DAC0'
- type: 'dac'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'dac_a54f338a6fa6fd273bc89d61f5a3b85e'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DAC0'
- config_sets:
  - fsl_dac:
    - dac_config:
      - referenceVoltageSource: 'kDAC_ReferenceVoltageSourceVref2'
      - enableLowPowerMode: 'false'
    - dac_enable: 'true'
    - dac_value: '2048'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const dac_config_t DAC0_config = {
  .referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2,
  .enableLowPowerMode = false
};

static void DAC0_init(void) {
  /* Initialize DAC converter */
  DAC_Init(DAC0_PERIPHERAL, &DAC0_config);
  /* Output value of DAC. */
  DAC_SetBufferValue(DAC0_PERIPHERAL, 0U, 2048U);
  /* Make sure the read pointer is set to the start */
  DAC_SetBufferReadPointer(DAC0_PERIPHERAL, 0U);
  /* Enable DAC output */
  DAC_Enable(DAC0_PERIPHERAL, true);
}

/***********************************************************************************************************************
 * PIT initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'PIT'
- type: 'pit'
- mode: 'LPTMR_GENERAL'
- custom_name_enabled: 'false'
- type_id: 'pit_ab54f91356454adb874dafbb69e655fd'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'PIT'
- config_sets:
  - fsl_pit:
    - enableRunInDebug: 'false'
    - timingConfig:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
    - channels:
      - 0:
        - channel_id: 'CHANNEL_3'
        - channelNumber: '3'
        - enableChain: 'false'
        - timerPeriod: '44.1kHz'
        - startTimer: 'false'
        - enableInterrupt: 'false'
        - interrupt:
          - IRQn: 'PIT0_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'false'
          - priority: '0'
          - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const pit_config_t PIT_config = {
  .enableRunInDebug = false
};

static void PIT_init(void) {
  /* Initialize the PIT. */
  PIT_Init(PIT_PERIPHERAL, &PIT_config);
  /* Set channel 3 period to 22.68 µs (1134 ticks). */
  PIT_SetTimerPeriod(PIT_PERIPHERAL, PIT_CHANNEL_3, PIT_CHANNEL_3_TICKS);
}

/***********************************************************************************************************************
 * UART0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'UART0'
- type: 'uart'
- mode: 'polling'
- custom_name_enabled: 'false'
- type_id: 'uart_9b45c456566d03f79ecfe90751c10bb4'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'UART0'
- config_sets:
  - uartConfig_t:
    - uartConfig:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'GetFreq'
      - baudRate_Bps: '115200'
      - parityMode: 'kUART_ParityDisabled'
      - dataBitsCount: 'kUART_EightDataBits'
      - stopBitCount: 'kUART_OneStopBit'
      - enableMatchAddress1: 'false'
      - matchAddress1: '0'
      - enableMatchAddress2: 'false'
      - matchAddress2: '0'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - idleType: 'kUART_IdleTypeStartBit'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const uart_config_t UART0_config = {
  .baudRate_Bps = 115200UL,
  .parityMode = kUART_ParityDisabled,
  .stopBitCount = kUART_OneStopBit,
  .txFifoWatermark = 0U,
  .rxFifoWatermark = 1U,
  .idleType = kUART_IdleTypeStartBit,
  .enableTx = true,
  .enableRx = true
};

static void UART0_init(void) {
  UART_Init(UART0_PERIPHERAL, &UART0_config, UART0_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * FATFS initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FATFS'
- type: 'fatfs'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'fatfs_2f85acf758668258920f70258052a088'
- functional_group: 'BOARD_InitPeripherals'
- config_sets:
  - init_config:
    - initConfig:
      - initPartitionsStr: 'false'
      - multiplePartitions:
        - 0:
          - Volume: '0'
          - Partition: 'autoDetect'
        - 1:
          - Volume: '0'
          - Partition: 'autoDetect'
      - enablePhysicalLayerInit: 'false'
      - diskConfig:
        - initFunctionID: 'FATFS_DiskInit'
      - initResultObject: 'false'
      - resultName: 'FATFS_Result'
      - fatfsObjects: []
      - filObjects: []
      - filInfoObjects: []
      - dirObjects: []
  - ff_config:
    - revisionID: 'rev14_3'
    - MSDKadaptation: 'SD_DISK_ENABLE'
    - functionConfig:
      - FF_FS_READONLY: 'true'
      - FF_FS_MINIMIZE: 'level1'
      - FF_USE_FIND: 'disableDirRead'
      - FF_USE_MKFS: 'false'
      - FF_USE_FASTSEEK: 'true'
      - FF_USE_EXPAND: 'false'
      - FF_USE_CHMOD: 'false'
      - FF_USE_LABEL: 'false'
      - FF_USE_FORWARD: 'false'
      - FF_USE_STRFUNC: 'enableWithoutConversion'
      - FF_PRINT_LLI: 'false'
      - FF_PRINT_FLOAT: 'enableFloatSeparator'
    - namespaceConfig:
      - FF_USE_LFN: 'enableLfnStatic'
      - FF_MAX_LFN: '255'
      - FF_LFN_BUF: 'LFNID'
      - FF_SFN_BUF: 'SFNID'
      - FF_LFN_UNICODE: 'ansiOEM'
      - FF_STRF_ENCODE: 'UTF16LE'
      - FF_CODE_PAGE: 'cpUS'
      - FF_FS_RPATH: 'enableRP2'
    - driveConfig:
      - FF_VOLUMES: '6'
      - FF_STR_VOLUME_ID: 'numericId'
      - volumes:
        - 0:
          - volumeStr: 'RAM'
        - 1:
          - volumeStr: 'NAND'
        - 2:
          - volumeStr: 'CF'
        - 3:
          - volumeStr: 'SD'
        - 4:
          - volumeStr: 'SD2'
        - 5:
          - volumeStr: 'USB'
      - FF_MULTI_PARTITION: 'false'
      - FF_MIN_SS: 'value512'
      - FF_MAX_SS: 'value512'
      - FF_LBA64: 'false'
      - FF_MIN_GPT: '0x10000000'
      - FF_USE_TRIM: 'false'
    - systemConfig:
      - FF_FS_TINY: 'false'
      - FF_FS_EXFAT: 'false'
      - FF_FS_NORTC: 'false'
      - FF_NORTC_MON: '1'
      - FF_NORTC_MDAY: '1'
      - FF_NORTC_YEAR: '2020'
      - FF_FS_NOFSINFO: ''
      - FF_FS_LOCK: '0'
      - FF_FS_REENTRANT: 'false'
      - FF_FS_TIMEOUT: '1000'
      - FF_SYNC_t: 'HANDLE'
      - includeOS: 'false'
      - headerFileName: 'somertos.h'
    - fatfs_codegenerator: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void FATFS_init(void) {
} */

/***********************************************************************************************************************
 * DebugConsole initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DebugConsole'
- type: 'debug_console'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'debug_console_51864e4f3ac859dae7b603e07bc4ae33'
- functional_group: 'BOARD_InitPeripherals'
- config_sets:
  - fsl_debug_console:
    - config:
      - SDK_DEBUGCONSOLE: 'DEBUGCONSOLE_REDIRECT_TO_TOOLCHAIN'
      - SDK_DEBUGCONSOLE_UART: 'semihost'
      - DEBUG_CONSOLE_RX_ENABLE: 'true'
      - DEBUG_CONSOLE_PRINTF_MAX_LOG_LEN: '128'
      - DEBUG_CONSOLE_SCANF_MAX_LOG_LEN: '20'
      - DEBUG_CONSOLE_ENABLE_ECHO: 'false'
      - PRINTF_FLOAT_ENABLE: 'false'
      - SCANF_FLOAT_ENABLE: 'false'
      - PRINTF_ADVANCED_ENABLE: 'false'
      - SCANF_ADVANCED_ENABLE: 'false'
      - DEBUG_CONSOLE_TRANSFER_NON_BLOCKING: 'true'
      - DEBUG_CONSOLE_TRANSMIT_BUFFER_LEN: '512'
      - DEBUG_CONSOLE_RECEIVE_BUFFER_LEN: '1024'
      - DEBUG_CONSOLE_TX_RELIABLE_ENABLE: 'true'
      - DEBUG_CONSOLE_DISABLE_RTOS_SYNCHRONIZATION: 'false'
    - debug_console_codegenerator: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void DebugConsole_init(void) {
} */

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Global initialization */
  DMAMUX_Init(DMA_DMAMUX_BASEADDR);
  EDMA_Init(DMA_DMA_BASEADDR, &DMA_config);

  /* Initialize components */
  DMA_init();
  DAC0_init();
  PIT_init();
  UART0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
