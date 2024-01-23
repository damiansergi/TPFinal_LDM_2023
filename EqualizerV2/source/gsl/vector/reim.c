#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_vector.h>

#include <gsl/vector/view.h>

#define BASE_GSL_COMPLEX_LONG
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX_LONG

#define BASE_GSL_COMPLEX
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX

#define BASE_GSL_COMPLEX_FLOAT
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX_FLOAT

#define USE_QUALIFIER
#define QUALIFIER const

#define BASE_GSL_COMPLEX_LONG
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX_LONG

#define BASE_GSL_COMPLEX
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX

#define BASE_GSL_COMPLEX_FLOAT
#include <gsl/templates_on.h>
#include <gsl/vector/reim_source.c>
#include <gsl/templates_off.h>
#undef  BASE_GSL_COMPLEX_FLOAT
