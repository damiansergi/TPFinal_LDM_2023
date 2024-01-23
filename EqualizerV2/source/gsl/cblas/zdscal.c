#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_zdscal (const int N, const double alpha, void *X, const int incX)
{
#define BASE double
#include <gsl/cblas/source_scal_c_s.h>
#undef BASE
}
