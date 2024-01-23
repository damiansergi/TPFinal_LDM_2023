#include <config.h>
#include <gsl/gsl_statistics.h>

#define BASE_LONG_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_LONG_DOUBLE

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT

#define BASE_ULONG
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_ULONG

#define BASE_LONG
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_LONG

#define BASE_UINT
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_UINT

#define BASE_INT
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_INT

#define BASE_USHORT
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_USHORT

#define BASE_SHORT
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_SHORT

#define BASE_UCHAR
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_UCHAR

#define BASE_CHAR
#include <gsl/templates_on.h>
#include <gsl/statistics/gastwirth_source.c>
#include <gsl/templates_off.h>
#undef  BASE_CHAR



