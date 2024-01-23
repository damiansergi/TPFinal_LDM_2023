#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_drotmg (double *d1, double *d2, double *b1, const double b2, double *P)
{
#define BASE double
#include <gsl/cblas/source_rotmg.h>
#undef BASE
}
