#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_cswap (const int N, void *X, const int incX, void *Y, const int incY)
{
#define BASE float
#include <gsl/cblas/source_swap_c.h>
#undef BASE
}
