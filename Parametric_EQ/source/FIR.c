/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   +Nombre del autor (ej: Salvador Allende)+
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "FIR.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

static float fir_impulse_response[FIR_FILTER_LENGTH] = {};

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

void FIRFIlter_Init(FIRFIlter *fir)
{
    //Clear filter buffer
    uint8_t n;
    for(n = 0; n < FIR_FILTER_LENGTH; n++)
    {
        fir->buf[n] = 0.0f;
    }

    //Reset buffer index
    fir->bufIndex = 0;

    //Clear filter output
    fir->out = 0.0f;
}

float FIRFilter_Update(FIRFIlter *fir, float inp)
{
    //Store latest sample in buffer
    fir->buf[fir->bufIndex] = inp;

    //Increment buffer index and wrap if necessary
    fir->bufIndex++;
    if(fir->bufIndex == FIR_FILTER_LENGTH)
    {
        fir->bufIndex = 0;
    }

    //Compute new output sample via convolution
    fir->out = 0.0f;

    uint8_t sumIndex = fir->bufIndex;

    uint8_t n;
    for(n = 0; n < FIR_FILTER_LENGTH; n++)
    {
        //Decrement index and wrap if necessary
        if(sumIndex > 0)
        {
            sumIndex--;
        }
        else 
        {
            sumIndex = FIR_FILTER_LENGTH-1;
        }

    }
}

/*******************************************************************************
 *******************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
