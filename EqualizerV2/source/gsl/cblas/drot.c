#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_drot (const int N, double *X, const int incX, double *Y, const int incY,
            const double c, const double s)
{
#define BASE double
#include <gsl/cblas/source_rot.h>
#undef BASE
}
