/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   Grupo 3
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <arm_math.h>
#include "equalizer.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define PEAKGAIN (12)	// in dB
#define NOTCHGAIN (-12) // in dB
#define GAINSTEP (3)	// in dB
// TODO: ajustar valor de MAX_POWER_VALUE
#define MAX_POWER_VALUE (1000)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

static int8_t currentGains[BANDS];

static int8_t *presetSelected;
static int8_t rockConfig[BANDS] = {5, 4, 2, 0, -1, 1, 3, 4};
static int8_t popConfig[BANDS] = {-2, -1, 2, 4, 4, 2, -1, -2};

static float bandPower[BANDS] = {0};
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
static arm_rfft_fast_instance_f32 S;
/*******************************************************************************
 *******************************************************************************
			GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void initEqualizer()
{
	initFilters();
}

void changeGain(uint8_t filterID, bool direction)
{

	int currGain = (int)getGain(filterID);

	if (direction == INCREASE && currGain + GAINSTEP <= PEAKGAIN)
	{
		changeGain(filterID, currGain + GAINSTEP);
	}
	else if (direction == DECREASE && currGain - GAINSTEP >= NOTCHGAIN)
	{
		changeGain(filterID, currGain - GAINSTEP);
	}
}

float processEqualizer(float sample)
{
	return computeFilters(sample);
}

void changePreset(uint8_t preset)
{

	switch (preset)
	{
	case rock:
		presetSelected = rockConfig;
		break;
	case pop:
		presetSelected = popConfig;
		break;
	}

	for (int i = 0; i < BANDS; i++)
	{
		currentGains[i] = presetSelected[i];
	}

	setGain(currentGains);
}

void analizeBlock(float *data, uint32_t datalen)
{
	// get the power of two that fits the data size
	static float pOut[2048];
	static float pOutMod[1024];
	uint32_t power = 0x80000000U >> __builtin_clz(datalen);
	if (power < 32)
	{
		return;
	}
	arm_rfft_fast_init_f32(&S, power);
	arm_rfft_fast_f32(&S, data, pOut, 0);
	arm_cmplx_mag_f32(pOut, pOutMod, power / 2);

	memset(bandPower, 0, sizeof(bandPower));

	for (int i = 0; i < power / 2; i++)
	{
		bandPower[i / (power / 16)] += pOutMod[i];
	}
	for (int i = 0; i < BANDS; i++)
	{
		bandPower[i] /= (power / 16) * MAX_POWER_VALUE;
	}
}

void analisis2vumeter(uint8_t vumeterDataout[8])
{
	for (int i = 0; i < BANDS; i++)
	{
		vumeterDataout[i] = (uint8_t)(bandPower[i] * 9);
	}
}
/*******************************************************************************
 *******************************************************************************
			LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
