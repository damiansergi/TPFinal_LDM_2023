#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

CBLAS_INDEX
cblas_isamax (const int N, const float *X, const int incX)
{
#define BASE float
#include <gsl/cblas/source_iamax_r.h>
#undef BASE
}
