/***************************************************************************/ /**
   @file     vumeter.h
   @brief    vumeter driver
   @author   Grupo 3
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include <vumeter.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define ON (true)
#define OFF (false)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void blinkBar(uint8_t barID, float ms);
static void stopBlinkBar(uint8_t barID);
static void turnOnBar(uint8_t barID);

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static const float blinkTime = 500000; // 0.5s

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static bool state = ON;
static uint8_t bandSelected = 0;
static uint8_t bandLevel[COLS] = {0};

/*******************************************************************************
 *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void initVumeter(){
	initLEDMatrix();

	for(int i = 0; i < COLS; i++){
		bandLevel[i] = ROWS/2;
		turnOnBar(i);
	}
}

void vumeterOn(){
	state = ON;
}

void vumeterOff(){
	state = OFF;
}

void setLevel(uint8_t level){

	if(state == ON){
		state = OFF;
	}

	if(level < 0){
		level = 0;
	}
	else if(level > MAXLEVEL){
		level = MAXLEVEL;
	}

	stopBlinkBar(bandSelected);
	bandLevel[bandSelected] = level;
	blinkBar(bandSelected, blinkTime);
}

void selectBand(uint8_t barID){

	if(state == ON){
		state = OFF;
	}

	if(barID < 0){
		barID = 0;
	}
	else if(barID >= ROWS){
		barID = ROWS-1;
	}

	stopBlinkBar(bandSelected);
	turnOnBar(bandSelected);
	bandSelected = barID;
	blinkBar(bandSelected, blinkTime);
}

/*******************************************************************************
 *******************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void turnOnBar(uint8_t barID){
	for(int i = 0; i < bandLevel[barID]; i++){
		turnOn(i, barID);
	}
}

static void stopBlinkBar(uint8_t barID){
	for(int i = 0; i < bandLevel[barID]; i++){
		stopBlink(i, barID);
	}
}

static void blinkBar(uint8_t barID, float ms){
	for(int i = 0; i < bandLevel[barID]; i++){
		blink(i, barID, ms);
	}
}
