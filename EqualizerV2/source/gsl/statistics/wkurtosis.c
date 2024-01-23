#include <config.h>
#include <math.h>
#include <gsl/gsl_statistics.h>

#define BASE_LONG_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/statistics/wkurtosis_source.c>
#include <gsl/templates_off.h>
#undef  BASE_LONG_DOUBLE

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/statistics/wkurtosis_source.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/statistics/wkurtosis_source.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT
