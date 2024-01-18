/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   Grupo 3
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "biquad.h"
#include <math.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define PI (3.141592654f) // PI value
#define EPSILON (1e-6)    // EPSILON value to make float comparisons

#define BANDS (8)
#define FILTERSQ (1.23f)
#define FS (44100) // sampling frequency in Hz

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef struct
{
  float G;     // peak gain
  float cosWc; // center frecuency in rad/s
  float B;     // bandwidth
  float Gb;    // gain at bandwith B
  float beta;  // beta value
  float y[2];  // last two computed outputs, store y(n-1) and y(n-2), respectively
} biquad_t;

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// Filter test configuration gains in dB
static const int8_t constant[BANDS] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
static const int8_t zigzag[BANDS] = {12, -12, -12, 12, -12, -12, -12, 12, -12, -12};

// Filter parameters
static uint16_t centerFreqs[BANDS] = {34, 80, 190, 450, 1100, 2500, 6000, 14200}; // In Hz

// Target amplitud of each filter, equation g = A^-1 . t
static int8_t g[BANDS] = {0};          // In dB
static int8_t t[BANDS] = {0};          // In dB
static uint8_t A[BANDS][BANDS] = {10}; // In dB

static biquad_t filter[BANDS];

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static float getBeta(float G, float B, float Gb);

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

void initFilters()
{
  for (int i = 0; i < BANDS; i++)
  {
    filter[i].cosWc = cos(2 * PI * centerFreqs[i]);
    filter[i].B = centerFreqs[i] / FILTERSQ;
    filter[i].G = 1;
    filter[i].Gb = 1 / 2;
    filter[i].beta = getBeta(filter[i].G, filter[i].B, filter[i].Gb);
  }
}

/*
    Biquad difference equation
    y(n) =  [(1+G.b) * x(n)  - 2cos(wc) x(n-1) +
            (1-G.b) * x(n-2) + 2cos(wc) y(n-1) - (1-b) y(n-2)] /(1+b)
*/

float computeFilters(float x)
{
  static float in[2] = {0, 0}; // store x(n-1) and x(n-2), respectively
  float G, beta, cosWc, y, output = 0;

  for (int i = 0; i < BANDS; i++)
  {
    G = filter[i].G;
    cosWc = filter[i].cosWc;
    beta = filter[i].beta;

    y = ((1 + G * beta) * x - 2 * cosWc * in[0] + (1 - G * beta) * in[1] + 2 * cosWc * filter[i].y[0] - (1 - beta) * filter[i].y[1]) / (1 + beta);

    // update filter taps
    filter[i].y[1] = filter[i].y[0];
    filter[i].y[0] = y;

    output += y;
  }

  // update filter taps
  in[1] = in[0];
  in[0] = x;

  return output;
}

void setGain(uint8_t filterID, uint8_t value) // value in dB
{
  t[filterID] = value;
  // Recalculamos el vector g con LS (TODO: FALTA)
}

/*******************************************************************************
 *******************************************************************************
            LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static float getBeta(float G, float B, float Gb)
{
  if (fabs(G - 1) < EPSILON) // Si la ganancia es 1
  {
    return tan(B / 2);
  }
  else
  {
    return sqrt(fabs(pow(Gb, 2) - 1) / fabs(pow(G, 2) - pow(Gb, 2))) * tan(B / 2);
  }
}