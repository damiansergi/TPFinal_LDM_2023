
#include "LEDMatrix.h"
#include "PWM.h"
#include "FTM.h"
#include "PIT.h"
#include "MK64F12.h"
#include "config.h"

#define TICKSPERPERIOD (63) // 50MHz * 1.25us
#define T0H (20)
#define T1H (40)
#define NUMOFLEDS (64)
#define RGBBITS (24)
#define REFRESHRATE (200000) // 200ms

typedef enum
{
	RED,
	BLUE,
	GREEN,
} states;

static color_t LEDMatrix[NUMOFLEDS] = {0};
static uint16_t PWMLEDMatrix[NUMOFLEDS * RGBBITS] = {0};
static uint8_t refreshTimerID = 0;

static void RGB2PWM();
static void refresh();
static void onRefreshEnded();

void initLEDMatrix()
{
	initPIT();
	PWM_Init();
	PWM_SetTickPerPeriod(TICKSPERPERIOD);
	RGB2PWM();
	FTM_SetInterruptionCallback(onRefreshEnded);
	PWM_GenWaveform(PWMLEDMatrix, NUMOFLEDS * RGBBITS, sizeof(uint16_t));

	refreshTimerID = createTimer(REFRESHRATE, refresh);
	startTimer(refreshTimerID);
}

static void refresh()
{
	FTM_StartClock(FTM0);
}

static void onRefreshEnded()
{
	FTM_StopClock(FTM0);
}

void changeColor(uint8_t row, uint8_t col, color_t color)
{
	LEDMatrix[row * 8 + col] = color;
	RGB2PWM();
}

static void RGB2PWM()
{
	int currBit = 7;
	states currColor = GREEN;
	uint8_t bit = 0;

	for (int i = 0; i < NUMOFLEDS; i++)
	{
		for (int j = 0; j < RGBBITS; j++)
		{
			switch (currColor)
			{
			case GREEN:
				bit = (LEDMatrix[i].g >> currBit) & (0x1);
				if (currBit <= 0)
				{
					currColor = RED;
					currBit = 7;
				}
				else
				{
					currBit--;
				}
				break;

			case RED:
				bit = (LEDMatrix[i].r >> currBit) & (0x1);
				if (currBit <= 0)
				{
					currColor = BLUE;
					currBit = 7;
				}
				else
				{
					currBit--;
				}
				break;

			case BLUE:
				bit = (LEDMatrix[i].g >> currBit) & (0x1);
				if (currBit <= 0)
				{
					currColor = GREEN;
					currBit = 7;
				}
				else
				{
					currBit--;
				}
				break;
			}

			if (bit == 0)
			{
				PWMLEDMatrix[i * RGBBITS + j] = T0H;
			}
			else
			{
				PWMLEDMatrix[i * RGBBITS + j] = T1H;
			}
		}
	}
}
