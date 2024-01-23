#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_cher (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
            const int N, const float alpha, const void *X, const int incX,
            void *A, const int lda)
{
#define BASE float
#include <gsl/cblas/source_her.h>
#undef BASE
}
