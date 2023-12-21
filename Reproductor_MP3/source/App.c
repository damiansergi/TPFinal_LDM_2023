/***************************************************************************/ /**
   @file     App.c
   @brief    Application functions
   @author   Nicolás Magliola
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "gpio.h"
#include "board.h"
#include "uart.h"
#include "fsm.h"      /*FSM engine (interprete)*/
#include "fsmtable.h" /*FSM Table*/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void delayLoop(uint32_t veces);

static uart_cfg_t uartConfig = {
    .IRQEnabled = true,
    .oddParity = true,
    .baudrate = 9600,
    .uartMode = TXRX};

STATE *p2state = NULL; /*Used to store FSM state*/

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init(void)
{
    gpioMode(PIN_LED_BLUE, OUTPUT);
    uartInit(0, uartConfig);
}

/* Función que se llama constantemente en un ciclo infinito */
void App_Run(void)
{
    delayLoop(4000000UL);
    gpioToggle(PIN_LED_BLUE);

    /*
    p2state=FSM_GetInitState();// Inicializo la FSM con el estado inicial
    while(is_new_event()){  //Si hay evento
        p2state=fsm(p2state,evento);      //Se lo paso a la maquina de estados
    }
    */
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void delayLoop(uint32_t veces)
{
    while (veces--)
        ;
}

/*******************************************************************************
 ******************************************************************************/
