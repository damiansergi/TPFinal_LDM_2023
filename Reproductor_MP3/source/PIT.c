
#include "MK64F12.h"
#include "hardware.h"
#include "PIT.h"
#include "gpio.h"

#define REFERENCE ((float)(0.02))

typedef struct
{
	uint8_t state;
	void (*callback)(void);
} TIMER_t;

static TIMER_t timer[MAXTIMERS];

void initPIT()
{

	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT->MCR = 0;
	NVIC_EnableIRQ(PIT0_IRQn);
	NVIC_EnableIRQ(PIT1_IRQn);
	NVIC_EnableIRQ(PIT2_IRQn);
	NVIC_EnableIRQ(PIT3_IRQn);

	gpioMode(PORTNUM2PIN(PC, 7), OUTPUT);
	gpioMode(PORTNUM2PIN(PC, 0), OUTPUT);
	// NVIC_SetPriority(PIT0_IRQn, 2); // 0: Max prioridad, 15: Menor prioridad
	// NVIC_SetPriority(PIT1_IRQn, 5);
	// NVIC_SetPriority(PIT2_IRQn, 5);
}

uint8_t createTimer(float time, void (*funcallback)(void))
{

	uint8_t i = 0;
	bool found = false;

	while (i < MAXTIMERS && !found)
	{
		if (timer[i].state == FREE)
		{
			timer[i].state = IDLE;
			timer[i].callback = funcallback;
			PIT->CHANNEL[i].LDVAL = (int)(time / REFERENCE);
			PIT->CHANNEL[i].TCTRL |= PIT_TCTRL_TIE_MASK;
			found = true;
		}
		else
		{
			i++;
		}
	}

	return i;
}

void configTimerTime(uint8_t id, float time)
{
	PIT->CHANNEL[id].TCTRL &= ~PIT_TCTRL_TEN_MASK;
	PIT->CHANNEL[id].LDVAL = (int)(time / REFERENCE);
	PIT->CHANNEL[id].TCTRL |= PIT_TCTRL_TEN_MASK;
}

void destroyTimer(uint8_t id)
{
	PIT->CHANNEL[id].TCTRL &= ~PIT_TCTRL_TEN_MASK;
	timer[id].state = FREE;
}

void startTimer(uint8_t id)
{
	PIT->CHANNEL[id].TCTRL |= PIT_TCTRL_TEN_MASK;
	if (timer[id].state != FREE)
	{
		timer[id].state = RUNNING;
	}
}

void stopTimer(uint8_t id)
{
	PIT->CHANNEL[id].TCTRL &= ~PIT_TCTRL_TEN_MASK;
	if (timer[id].state != FREE)
	{
		timer[id].state = IDLE;
	}
}

uint32_t getTime(uint8_t id)
{
	return PIT->CHANNEL[id].CVAL;
}

uint8_t getTimerState(uint8_t id)
{
	return timer[id].state;
}

void PIT0_IRQHandler(void)
{
	gpioWrite(PORTNUM2PIN(PC, 0), true);
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF(1);
	timer[0].callback();
	NVIC_ClearPendingIRQ(PIT0_IRQn);
	gpioWrite(PORTNUM2PIN(PC, 0), false);
}

void PIT1_IRQHandler(void)
{
	gpioWrite(PORTNUM2PIN(PC, 7), true);
	PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF(1);
	timer[1].callback();
	NVIC_ClearPendingIRQ(PIT1_IRQn);
	gpioWrite(PORTNUM2PIN(PC, 7), false);
}

void PIT2_IRQHandler(void)
{

	PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF(1);
	timer[2].callback();
	NVIC_ClearPendingIRQ(PIT2_IRQn);
}

void PIT3_IRQHandler(void)
{

	PIT->CHANNEL[3].TFLG = PIT_TFLG_TIF(1);
	timer[3].callback();
	NVIC_ClearPendingIRQ(PIT3_IRQn);
}
