#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_dswap (const int N, double *X, const int incX, double *Y,
             const int incY)
{
#define BASE double
#include <gsl/cblas/source_swap_r.h>
#undef BASE
}
