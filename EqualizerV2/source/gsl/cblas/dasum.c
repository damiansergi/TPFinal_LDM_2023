#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

double
cblas_dasum (const int N, const double *X, const int incX)
{
#define BASE double
#include <gsl/cblas/source_asum_r.h>
#undef BASE
}
