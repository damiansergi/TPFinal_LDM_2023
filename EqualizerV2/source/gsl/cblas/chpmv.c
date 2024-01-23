#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_chpmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
             const int N, const void *alpha, const void *Ap, const void *X,
             const int incX, const void *beta, void *Y, const int incY)
{
#define BASE float
#include <gsl/cblas/source_hpmv.h>
#undef BASE
}