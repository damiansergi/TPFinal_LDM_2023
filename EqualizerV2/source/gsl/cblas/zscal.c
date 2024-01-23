#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_zscal (const int N, const void *alpha, void *X, const int incX)
{
#define BASE double
#include <gsl/cblas/source_scal_c.h>
#undef BASE
}