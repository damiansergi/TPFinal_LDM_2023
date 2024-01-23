#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

CBLAS_INDEX
cblas_izamax (const int N, const void *X, const int incX)
{
#define BASE double
#include <gsl/cblas/source_iamax_c.h>
#undef BASE
}
