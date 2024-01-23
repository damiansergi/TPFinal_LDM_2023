#include <gsl/cblas/cblas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

void
cblas_drotg (double *a, double *b, double *c, double *s)
{
#define BASE double
#include <gsl/cblas/source_rotg.h>
#undef BASE
}
