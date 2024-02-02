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
#define MAX_POWER_VALUE (32768 / 4)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

static int8_t currentGains[BANDS];

static int8_t *presetSelected;
static int8_t flatConfig[BANDS] = {0, 0, 0, 0, 0, 0, 0, 0};
static int8_t bassConfig[BANDS] = {4, 3, 2, 0, 0, 0, 0, 0};
static int8_t rockConfig[BANDS] = {5, 4, 2, 0, -1, 1, 3, 4};
static int8_t popConfig[BANDS] = {-2, -1, 2, 4, 4, 2, -1, -2};

static const float filterQ[BANDS] = {1.23f, 1.23f, 1.3f, 1.3f, 1.23f, 1.4f, 1.39f, 1.49f};

// Filter parameters
static const uint16_t centerFreqs[BANDS] = {34, 80, 190, 450, 1100, 2500, 6000, 14200}; // In Hz

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

void processEqualizer(float *in, float *out, uint32_t blockSize)
{
	computeFilters(in, out, blockSize);
}

void changePreset(uint8_t preset)
{

	switch (preset)
	{
	case Rock:
		presetSelected = rockConfig;
		break;
	case Pop:
		presetSelected = popConfig;
		break;
	case Flat:
		presetSelected = flatConfig;
		break;
	case Bass:
		presetSelected = bassConfig;
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

	uint32_t j = 0;
	uint32_t binCounter[BANDS] = {0};

	for (size_t i = 0; i < power / 2; i++)
	{
		if (11025.0f / power * (i + 1) > 8158.27f)
		{
			j = 7;
		}
		else if (11025.0f / power * (i + 1) > 3392.86f)
		{
			j = 6;
		}
		else if (11025.0f / power * (i + 1) > 1547.15f)
		{
			j = 5;
		}
		else if (11025.0f / power * (i + 1) > 623.0f)
		{
			j = 4;
		}
		else if (11025.0f / power * (i + 1) > 263.0f)
		{
			j = 3;
		}
		else if (11025.0f / power * (i + 1) > 112.52f)
		{
			j = 2;
		}
		else if (11025.0f / power * (i + 1) > 47.8f)
		{
			j = 1;
		}
		binCounter[j]++;
		bandPower[j] += pOutMod[i];
	}

	for (int i = 0; i < BANDS; i++)
	{
		bandPower[i] = 20 * log10f(bandPower[i] / ((binCounter[i]) * MAX_POWER_VALUE));
	}
}

void analisis2vumeter(uint8_t vumeterDataout[8])
{
	for (int i = 0; i < BANDS; i++)
	{
		vumeterDataout[i] = (uint8_t)((bandPower[i] > -60.0f) ? (bandPower[i] + 60.0f) / 100.0f * 8.0f : 0);
	}
}
/*******************************************************************************
 *******************************************************************************
			LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
