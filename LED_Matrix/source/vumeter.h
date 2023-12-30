/***************************************************************************/ /**
   @file     vumeter.h
   @brief    vumeter driver
   @author   Grupo 3
  ******************************************************************************/

#ifndef _VUMETER_H_
#define _VUMETER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <stdint.h>
#include "LEDMatrix.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define MAXLEVEL (ROWS)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

void initVumeter();

void vumeterOn();

void vumeterOff();

void setLevel(uint8_t level);

void selectBand(uint8_t barID);

/*******************************************************************************
 ******************************************************************************/

#endif // _VUMETER_H_
