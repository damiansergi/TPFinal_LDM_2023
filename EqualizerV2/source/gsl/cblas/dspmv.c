#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_dspmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
             const int N, const double alpha, const double *Ap,
             const double *X, const int incX, const double beta, double *Y,
             const int incY)
{
#define BASE double
#include <gsl/cblas/source_spmv.h>
#undef BASE
}
