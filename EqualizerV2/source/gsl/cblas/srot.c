#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_srot (const int N, float *X, const int incX, float *Y, const int incY,
            const float c, const float s)
{
#define BASE float
#include <gsl/cblas/source_rot.h>
#undef BASE
}
