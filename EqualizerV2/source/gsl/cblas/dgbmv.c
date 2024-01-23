#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_dgbmv (const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA,
             const int M, const int N, const int KL, const int KU,
             const double alpha, const double *A, const int lda,
             const double *X, const int incX, const double beta, double *Y,
             const int incY)
{
#define BASE double
#include <gsl/cblas/source_gbmv_r.h>
#undef BASE
}