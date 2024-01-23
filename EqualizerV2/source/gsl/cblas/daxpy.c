#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_daxpy (const int N, const double alpha, const double *X, const int incX,
             double *Y, const int incY)
{
#define BASE double
#include <gsl/cblas/source_axpy_r.h>
#undef BASE
}
