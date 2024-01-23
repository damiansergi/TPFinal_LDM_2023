#include <gsl/cblas/cblas.h>
#include <gsl/cblas/error_cblas_l2.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_sger (const enum CBLAS_ORDER order, const int M, const int N,
            const float alpha, const float *X, const int incX, const float *Y,
            const int incY, float *A, const int lda)
{
#define BASE float
#include <gsl/cblas/source_ger.h>
#undef BASE
}
