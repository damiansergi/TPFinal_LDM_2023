#ifndef _LED_Matrix_
#define _LED_Matrix_

#include <stdint.h>

typedef struct
{
    uint8_t g;
    uint8_t r;
    uint8_t b;
} color_t;

/**
 * @brief Initilze led matrix
 * @return void
 */
void initLEDMatrix();

/**
 * @brief Turn on the specified led. If the led already is turned on, does nothing.
 * @param row The row where the led is
 * @param col The column where the led is
 * @return void
 */
void turnOn(uint8_t row, uint8_t col);

/**
 * @brief Turn off the specified led. If the led already is turned off, does nothing.
 * @param row The row where the led is
 * @param col The column where the led is
 * @return void
 */
void turnOff(uint8_t row, uint8_t col);

/**
 * @brief Change the specified led color
 * @param row The row where the led is
 * @param col The column where the led is
 * @param color color to set
 * @return void
 */
void changeColor(uint8_t row, uint8_t col, color_t color);

/**
 * @brief Start led to blink with a period twice specified by inverval in ms
 * @param row The row where the led is
 * @param col The column where the led is
 * @param interval time interval between led state change
 * @return void
 */
void blink(uint8_t row, uint8_t col, uint16_t interval);

/**
 * @brief Stop led to blink
 * @param row The row where the led is
 * @param col The column where the led is
 * @return void
 */
void stopBlink(uint8_t row, uint8_t col);

#endif // _LED_Matrix_