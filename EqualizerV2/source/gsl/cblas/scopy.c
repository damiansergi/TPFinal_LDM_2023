#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_scopy (const int N, const float *X, const int incX, float *Y,
             const int incY)
{
#define BASE float
#include <gsl/cblas/source_copy_r.h>
#undef BASE
}
