#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_sswap (const int N, float *X, const int incX, float *Y, const int incY)
{
#define BASE float
#include <gsl/cblas/source_swap_r.h>
#undef BASE
}
