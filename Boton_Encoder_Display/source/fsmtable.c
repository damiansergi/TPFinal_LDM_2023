#include <stdio.h>
#include <stdint.h>
#include "fsm.h"
#include "fsmtable.h"
#include "UI/display.h"


//Lo correcto con esto quizás seria llamar a funciones propias de cada libreria
//Esto queda como un concepto de que es lo que hay que hacer, después lo discutimos
uint8_t volumeLevel;
uint8_t eqLevel;
uint8_t songSelected;


/*Foward Declarations*/

extern STATE st_off[];
extern STATE st_rep[];
extern STATE st_vol[];
extern STATE st_eq[];



// prototipos

static void do_nothing(void);
static void goToRepFromOff(void);
static void goToRepFromVol(void);
static void goToRepFromEq(void);
static void playPauseSong(void);
static void changeSongLeft(void);
static void changeSongRight(void);
static void goToVolume(void);
static void changeVolumeRight(void);
static void changeVolumeLeft(void);
static void goToEq(void);
static void changeEqRight(void);
static void changeEqLeft(void);
static void turnOff(void);

/*** tablas de estado ***/

/*** estado apagado ***/

 STATE st_off[]=
{
  	{EncoderClick,st_rep,goToRepFromOff},

  	{FIN_TABLA,st_off,do_nothing}	//FIN_TABLA sirve como el default de un switch(event),
  									//por si llega a venir un evento que no queremos handlear
};


/*** estado reproduccion ***/

STATE st_rep[]=
{
	{EncoderLeft,st_rep,changeSongLeft},
	{EncoderRight,st_rep,changeSongRight},
	{ButtonCross,st_rep,playPauseSong},
	{ButtonPoint,st_rep,goToVolume},
	{ButtonLine,st_rep,goToEq},
	{EncoderClick, st_off, turnOff},
	{FIN_TABLA,st_rep,do_nothing}
};

/*** estado volumen ***/

STATE st_vol[] =
{
	{EncoderLeft,st_vol,changeVolumeLeft},
	{EncoderRight,st_vol,changeVolumeRight},
	{ButtonPoint,st_rep,goToRepFromVol},
	{EncoderClick, st_off, turnOff},
	{FIN_TABLA,st_vol,do_nothing}
};

/*** estado ecualizador ***/

STATE st_eq[] =
{
	{EncoderLeft,st_eq,changeEqLeft},
	{EncoderRight,st_eq,changeEqRight},
	{ButtonLine,st_rep,goToRepFromEq},
	{EncoderClick, st_off, turnOff},
	{FIN_TABLA,st_eq,do_nothing}
};


//========interfaz=================

STATE *FSM_GetInitState(void)
{
 	return (st_off);
}



///=========Rutinas de accion===============


/*Dummy function*/
static void do_nothing(void){


}
static void goToRepFromOff(void){

	char buffer[MAXLETTERS];
	//snprintf(buffer, MAXLETTERS, "song: %d", songSelected); Por alguna razon sprintf no funciona...
	//Me obliga a hardcodear cada letra, o  tendre que crear mi propio sprintf mas sencillo
	DisplayWrite(buffer, 8, 0);


}
static void goToRepFromVol(void){


}
static void goToRepFromEq(void){


}
static void playPauseSong(void){


}
static void changeSongLeft(void){


}
static void changeSongRight(void){


}
static void goToVolume(void){


}
static void changeVolumeRight(void){


}
static void changeVolumeLeft(void){


}
static void goToEq(void){


}
static void changeEqRight(void){


}
static void changeEqLeft(void){


}
static void turnOff(void){


}
