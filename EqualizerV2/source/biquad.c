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

#define EPSILON (1e-6)    // EPSILON value to make float comparisons

#define BANDS (8)
#define FILTERSQ (1.0f) //1.23f
#define FS (44100.0f) // sampling frequency in Hz
#define DB2TIMES(x) (pow(10, (x)/20))
#define GN (10) //normalization gain in dB (depend on gain when A matrix was calculated)

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
static const int8_t constant[BANDS] = {12, 12, 12, 12, 12, 12, 12, 12};
static const int8_t zigzag[BANDS] = {12, -12, -12, 12, -12, -12, -12, 12};
static const int8_t nogain[BANDS] = {0, 0, 0, 0, 0, 0, 0, 0};
static const int8_t attenuate[BANDS] = {-12, -12, -12, -12, -12, -12, -12, -12};

// Filter parameters
static uint16_t centerFreqs[BANDS] = {34, 80, 190, 450, 1100, 2500, 6000, 14200}; // In Hz

static float in[2] = {0, 0}; // store x(n-1) and x(n-2), respectively

// Target amplitud of each filter, equation g = A^-1 . t
static float g[BANDS];          // In dB
static float t[BANDS];          // In dB
static float A[BANDS][BANDS] = {	{1.000000f, 0.092604f, 0.013217f, 0.002267f, 0.000375f, 0.000071f, 0.000011f, 0.000001f},
									{0.092608f, 1.000000f, 0.090445f, 0.013030f, 0.002092f, 0.000396f, 0.000062f, 0.000005f},
									{0.013221f, 0.090465f, 1.000000f, 0.091046f, 0.012229f, 0.002247f, 0.000349f, 0.000028f},
									{0.002271f, 0.013051f, 0.091159f, 1.000000f, 0.083929f, 0.013118f, 0.001971f, 0.000159f},
									{0.000379f, 0.002113f, 0.012349f, 0.084567f, 1.000000f, 0.099836f, 0.012349f, 0.000965f},
									{0.000075f, 0.000417f, 0.002369f, 0.013797f, 0.103613f, 1.000000f, 0.081012f, 0.005370f},
									{0.000015f, 0.000084f, 0.000476f, 0.002686f, 0.016607f, 0.101754f, 1.000000f, 0.048390f},
									{0.000007f, 0.000038f, 0.000212f, 0.001188f, 0.007093f, 0.036486f, 0.206872f, 1.000000f}}; // In dB

static biquad_t filter[BANDS];

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static float getBeta(float G, float B, float Gb);

static void choleskyDecomposition(float A[][BANDS], float L[][BANDS], int n);
static void forwardSubstitution(float L[][BANDS], float B[], float Y[], int n);
static void backwardSubstitution(float L[][BANDS], float Y[], float X[], int n);
static void solveLinear(float A[][BANDS], float b[], float x[], int n);

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
		t[i] = attenuate[i]; //select preset
	}

	solveLinear(A, t, g, BANDS);

	for (int i = 0; i < BANDS; i++)
	{
		filter[i].cosWc = cos(2 * PI * centerFreqs[i]/FS);
		filter[i].B = 2 * PI * centerFreqs[i] / (FILTERSQ * FS);
		filter[i].G = DB2TIMES(g[i]);
		filter[i].Gb = filter[i].G / 2;
		filter[i].beta = sqrt(fabs(pow(filter[i].Gb, 2) - 1) / fabs(pow(filter[i].G, 2) - pow(filter[i].Gb, 2))) * tan(filter[i].B / 2);
	}
}

/*
    Biquad difference equation
    y(n) =  [(1+G.b) * x(n)  - 2cos(wc) x(n-1) +
            (1-G.b) * x(n-2) + 2cos(wc) y(n-1) - (1-b) y(n-2)] /(1+b)
*/

float computeFilters(float x)
{
  float G, beta, cosWc, y, output = 1;

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

void resetFilters(){

	for (int i = 0; i < BANDS; i++)
	{
		filter[i].y[0] = 0;
		filter[i].y[1] = 0;
	}

	in[0] = 0;
	in[1] = 0;
}

void setGain(uint8_t filterID, uint8_t value) // value in dB
{

	t[filterID] = value;

	//Recalculamos el vector g resolviendo A*g = t
	solveLinear(A, g, t, BANDS);

	for (int i = 0; i < BANDS; i++)
	{
		filter[i].G = DB2TIMES(g[i]);
		filter[i].Gb = filter[i].G / 2;
		filter[i].beta = sqrt(fabs(pow(filter[i].Gb, 2) - 1) / fabs(pow(filter[i].G, 2) - pow(filter[i].Gb, 2))) * tan(filter[i].B / 2);
	}
}

/*******************************************************************************
 *******************************************************************************
            LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



static void solveLinear(float A[][BANDS], float b[], float x[], int n) {

    float L[][BANDS] = {{0},{0},{0},{0},{0},{0},{0},{0}};
    float y[BANDS] = {0};

    choleskyDecomposition(A, L, n);

    // Solve Ly = b for Y using forward substitution
    forwardSubstitution(L, b, y, n);

    // Solve L^Tx = y for x using backward substitution
    backwardSubstitution(L, y, x, n);
}

static void forwardSubstitution(float L[][BANDS], float B[], float Y[], int n) {
    for (int i = 0; i < n; i++) {
    	float sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = (B[i] - sum) / L[i][i];
    }
}

static void backwardSubstitution(float L[][BANDS], float Y[], float X[], int n) {
    for (int i = n - 1; i >= 0; i--) {
    	float sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += L[j][i] * X[j];
        }
        X[i] = (Y[i] - sum) / L[i][i];
    }
}

static void choleskyDecomposition(float A[][BANDS], float L[][BANDS], int n) {

	for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
        	float sum = 0.0;

        	//Si estas en la diagonal principal
            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }

                L[j][j] = sqrt(A[j][j] - sum);
            }
            else {
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }

                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}
