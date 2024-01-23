#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_ssymv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
             const int N, const float alpha, const float *A, const int lda,
             const float *X, const int incX, const float beta, float *Y,
             const int incY)
{
#define BASE float
#include <gsl/cblas/source_symv.h>
#undef BASE
}
