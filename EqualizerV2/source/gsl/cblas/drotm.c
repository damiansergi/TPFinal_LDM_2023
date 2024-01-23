#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_drotm (const int N, double *X, const int incX, double *Y,
             const int incY, const double *P)
{
#define BASE double
#include <gsl/cblas/source_rotm.h>
#undef BASE
}
