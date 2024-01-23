#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_srotm (const int N, float *X, const int incX, float *Y, const int incY,
             const float *P)
{
#define BASE float
#include <gsl/cblas/source_rotm.h>
#undef BASE
}
