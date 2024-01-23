#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_srotmg (float *d1, float *d2, float *b1, const float b2, float *P)
{
#define BASE float
#include <gsl/cblas/source_rotmg.h>
#undef BASE
}
