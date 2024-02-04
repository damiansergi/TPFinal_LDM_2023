/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   Grupo 3
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "deepSleep.h"

#include "MK64F12.h"

#include "config.h"
#include "App.h"

#define WAKEUP_PIN BUTTON_ENCODER_PIN
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
            GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void deepSleep_init(void)
{

    LLWU->PE4 |= LLWU_PE3_WUPE9(1); // Rising edge detection

    // Clear the wake-up flag in the LLWU-write one to clear the flag
    if (LLWU->F2 & LLWU_F2_WUF12_MASK)
    {
        LLWU->F2 |= LLWU_F2_WUF12_MASK;
    }
}

void deepSleep(void)
{
    volatile unsigned int dummyread;

    /* Write to PMPROT to allow LLS power modes this write-once
    bit allows the MCU to enter the LLS low power mode*/
    SMC->PMPROT = SMC_PMPROT_ALLS_MASK;

    /* Set the (for MC1) LPLLSM or (for MC2)STOPM field to 0b011 for LLS mode
    Retains LPWUI and RUNM values */
    SMC->PMCTRL &= ~SMC_PMCTRL_STOPM_MASK;
    SMC->PMCTRL |= SMC_PMCTRL_STOPM(0x3);

    // Wait for write to complete to SMC before stopping core
    dummyread = SMC->PMCTRL;

    // Now execute the stop instruction to go into LLS

    // Set the SLEEPDEEP bit to enable deep sleep mode (STOP)
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    __DSB();

    // Enters sleep mode
    __WFI();

    // wait for write to complete to SMC before stopping core
    dummyread = SMC->PMCTRL;

    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

    // Interrupt can take place here
    __ISB();
}
/*******************************************************************************
 *******************************************************************************
            LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void LLW_IRQHandler(void)
{
    if ((LLWU->F2 & LLWU_F2_WUF12_MASK))
    {
        LLWU->F2 |= LLWU_F2_WUF12_MASK;
    }
    hw_Init();
    hw_DisableInterrupts();
    App_Init(); /* Program-specific setup */
    hw_EnableInterrupts();
}
