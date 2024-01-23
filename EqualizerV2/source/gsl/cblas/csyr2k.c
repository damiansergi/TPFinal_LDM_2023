#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l3.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_csyr2k (const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
              const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
              const void *alpha, const void *A, const int lda, const void *B,
              const int ldb, const void *beta, void *C, const int ldc)
{
#define BASE float
#include <gsl/cblas/source_syr2k_c.h>
#undef BASE
}
