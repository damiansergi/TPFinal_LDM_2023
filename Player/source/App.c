/***************************************************************************//**
 @file     main.c
 @brief    FW main
 @author   Grupo 3
 ******************************************************************************/

#include <board.h>
#include <clock_config.h>
#include <diskio.h>
#include <ff.h>
#include <fsl_debug_console.h>
#include <fsl_sd.h>
#include <fsl_sysmpu.h>
#include <hardware.h>
#include <MK64F12.h>
#include <pin_mux.h>
#include <stdbool.h>
#include <stdint.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void delayLoop(uint32_t veces);

static FATFS g_fileSystem; /* File system object */
static FIL g_fileObject; /* File object */
const TCHAR driverNumberBuffer[3U] = { SDDISK + '0', ':', '/' };
static sd_card_t SD;
void App_Init(void);
void App_Run(void);

int main(void) {

	hw_Init();
	hw_DisableInterrupts();
	App_Init(); /* Program-specific setup */
	hw_EnableInterrupts();

	__FOREVER__
		App_Run(); /* Program-specific loop  */
}

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init(void) {
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	SYSMPU_Enable(SYSMPU, false);

}

/* Función que se llama constantemente en un ciclo infinito */
void App_Run(void) {
	static bool cardIn = false;
	static DIR dir;
	while (SD_IsCardPresent(&SD)) {
		/* code */
	}

	if (!cardIn) {
		if (SD_IsCardPresent(&SD)) {
			cardIn = true;
			f_mount(&g_fileSystem, driverNumberBuffer, 0U);
			FRESULT res = f_opendir(&dir, "2:");
			PRINTF(res + '0');
		}
	} else {
		if (!(SDHC->PRSSTAT && (1 << 16))) {
			cardIn = false;
		}
	}
	delayLoop(40000000L);
}

/*******************************************************************************
 *******************************************************************************
 LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void delayLoop(uint32_t veces) {
	while (veces--)
		;
}

/*******************************************************************************
 ******************************************************************************/
