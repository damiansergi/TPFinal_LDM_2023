#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_dcopy (const int N, const double *X, const int incX, double *Y,
             const int incY)
{
#define BASE double
#include <gsl/cblas/source_copy_r.h>
#undef BASE
}
