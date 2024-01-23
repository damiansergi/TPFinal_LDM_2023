#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_csscal (const int N, const float alpha, void *X, const int incX)
{
#define BASE float
#include <gsl/cblas/source_scal_c_s.h>
#undef BASE
}
