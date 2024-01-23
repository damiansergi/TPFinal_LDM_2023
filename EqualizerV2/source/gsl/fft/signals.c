#include <config.h>
#include <gsl/fft/complex_internal.h>
#include <gsl/fft/urand.c>
#include <math.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_errno.h>

#include <gsl/gsl_dft_complex.h>
#include <gsl/gsl_dft_complex_float.h>


#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/fft/signals_source.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/fft/signals_source.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT

