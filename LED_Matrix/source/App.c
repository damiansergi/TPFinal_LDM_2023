/***************************************************************************/ /**
   @file     App.c
   @brief    Application functions
   @author   Grupo 3
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "gpio.h"
#include "board.h"
#include "vumeter.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void hearth();
static void delay();

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init(void)
{
	initVumeter();
}

/* Función que se llama constantemente en un ciclo infinito */
void App_Run(void)
{

	uint8_t level = 0;

	for(int i = 5; i < 8; i++){
		selectBand(i);
		delay();
		setLevel(MAXLEVEL);
		delay();
	}


}

static void delay(){
	uint32_t time = 20000000;
	while(time--);
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 ******************************************************************************/

//static void hearth(){
//
//	color_t rojoBorde = {.r = 199, .g = 7, .b= 47};
//	color_t rojo = {.r = 255, .g = 0, .b= 54};
//	color_t blanco = {.r = 255, .g = 255, .b= 255};
//	color_t negro = {.r = 0, .g = 0, .b= 0};
//
//	changeColor(0, 1, rojoBorde);
//	changeColor(0, 2, rojoBorde);
//	changeColor(0, 4, rojoBorde);
//	changeColor(0, 5, rojoBorde);
//
//	changeColor(1, 0, rojoBorde);
//	changeColor(1, 1, rojo);
//	changeColor(1, 2, rojo);
//	changeColor(1, 3, rojoBorde);
//	changeColor(1, 4, blanco);
//	changeColor(1, 5, blanco);
//	changeColor(1, 6, rojoBorde);
//
//	changeColor(2, 0, rojoBorde);
//	changeColor(2, 1, rojo);
//	changeColor(2, 2, rojo);
//	changeColor(2, 3, rojo);
//	changeColor(2, 4, rojo);
//	changeColor(2, 5, blanco);
//	changeColor(2, 6, rojoBorde);
//
//	changeColor(3, 0, rojoBorde);
//	changeColor(3, 1, rojo);
//	changeColor(3, 2, rojo);
//	changeColor(3, 3, rojo);
//	changeColor(3, 4, rojo);
//	changeColor(3, 5, rojo);
//	changeColor(3, 6, rojoBorde);
//
//	changeColor(4, 1, rojoBorde);
//	changeColor(4, 2, rojo);
//	changeColor(4, 3, rojo);
//	changeColor(4, 4, rojo);
//	changeColor(4, 5, rojoBorde);
//
//	changeColor(5, 2, rojoBorde);
//	changeColor(5, 3, rojo);
//	changeColor(5, 4, rojoBorde);
//
//	changeColor(6, 3, rojoBorde);
//}
