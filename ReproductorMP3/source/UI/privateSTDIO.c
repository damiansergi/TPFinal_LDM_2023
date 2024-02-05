/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "privateSTDIO.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static void falta_envido (int);+


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


void volNumPrinter (char * buffer, uint8_t numVol){

	if (numVol < 10){
		buffer[7] = '0';
		buffer[8] = '0' + numVol;
	}
	else if(numVol == 100)
	{
		buffer[7] = '1';
		buffer[8] = '0';
		buffer[8] = '0';
	}
	else{
		buffer[7] = '0' + numVol/10;
		buffer[8] = '0' + numVol%10;
	}
}
void eqStringPrinter (char * buffer, char * eqBand){

	int i = 0;
	while(eqBand[i] != '\0'){

		buffer[i+4] = eqBand[i];
		i++;
	}
}
void repDisplayPrinter ( char * buffer, bool pause, uint8_t numVol, char * eqBand){

	if (pause){
		buffer[0] = 'P';
		buffer[1] = 'A';
		buffer[2] = 'U';
		buffer[3] = 'S';
		buffer[4] = 'E';
	}
	else{
		buffer[0] = 'P';
		buffer[1] = 'L';
		buffer[2] = 'A';
		buffer[3] = 'Y';
	}

	if (numVol < 10){
		buffer[6] = '0';
		buffer[7] = '0' + numVol;
	}
	else if (numVol == 100)
	{
		buffer[6] = '1';
		buffer[7] = '0';
		buffer[8] = '0';
	}
	else{
		buffer[6] = '0' + numVol/10;
		buffer[7] = '0' + numVol%10;
	}

	int i = 0;
	while(eqBand[i] != '\0'){

		buffer[i+9] = eqBand[i];
		i++;
	}
}

void bufferClean (char * buffer){

	int i = 0;
	for (i = 0; i<16; i++){
		buffer[i] = ' ';
	}
}
/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



