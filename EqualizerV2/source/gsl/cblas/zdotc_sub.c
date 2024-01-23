#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_zdotc_sub (const int N, const void *X, const int incX, const void *Y,
             const int incY, void *result)
{
#define BASE double
#define CONJ_SIGN (-1.0)
#include <gsl/cblas/source_dot_c.h>
#undef CONJ_SIGN
#undef BASE
}