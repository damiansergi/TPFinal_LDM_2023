
#include "LEDMatrix.h"
#include "PWM.h"

#define TICKPERPERIOD (130) // 100MHz * 1.3us = 130, porque es el mas critico

#define RESET (5000)

void initLEDMatrix()
{
    // System clk = 100MHz
    PWM_Init(); // Initializamos el PWM
    PWM_SetTickPerPeriod(TICKPERPERIOD);
    PWM_SetDC();
}