#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

float
cblas_snrm2 (const int N, const float *X, const int incX)
{
#define BASE float
#include <gsl/cblas/source_nrm2_r.h>
#undef BASE
}
