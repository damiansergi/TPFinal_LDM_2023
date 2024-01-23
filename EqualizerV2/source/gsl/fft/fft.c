#include <config.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_complex.h>

#include <gsl/gsl_fft_complex.h>
#include <gsl/gsl_fft_complex_float.h>

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/fft/bitreverse.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/fft/bitreverse.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT

#include <gsl/fft/factorize.c>

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/fft/c_init.c>
#include <gsl/fft/c_main.c>
#include <gsl/fft/c_pass_2.c>
#include <gsl/fft/c_pass_3.c>
#include <gsl/fft/c_pass_4.c>
#include <gsl/fft/c_pass_5.c>
#include <gsl/fft/c_pass_6.c>
#include <gsl/fft/c_pass_7.c>
#include <gsl/fft/c_pass_n.c>
#include <gsl/fft/c_radix2.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/fft/c_init.c>
#include <gsl/fft/c_main.c>
#include <gsl/fft/c_pass_2.c>
#include <gsl/fft/c_pass_3.c>
#include <gsl/fft/c_pass_4.c>
#include <gsl/fft/c_pass_5.c>
#include <gsl/fft/c_pass_6.c>
#include <gsl/fft/c_pass_7.c>
#include <gsl/fft/c_pass_n.c>
#include <gsl/fft/c_radix2.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT

#include <gsl/gsl_fft_halfcomplex.h>
#include <gsl/gsl_fft_halfcomplex_float.h>

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/fft/hc_init.c>
#include <gsl/fft/hc_main.c>
#include <gsl/fft/hc_pass_2.c>
#include <gsl/fft/hc_pass_3.c>
#include <gsl/fft/hc_pass_4.c>
#include <gsl/fft/hc_pass_5.c>
#include <gsl/fft/hc_pass_n.c>
#include <gsl/fft/hc_radix2.c>
#include <gsl/fft/hc_unpack.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/fft/hc_init.c>
#include <gsl/fft/hc_main.c>
#include <gsl/fft/hc_pass_2.c>
#include <gsl/fft/hc_pass_3.c>
#include <gsl/fft/hc_pass_4.c>
#include <gsl/fft/hc_pass_5.c>
#include <gsl/fft/hc_pass_n.c>
#include <gsl/fft/hc_radix2.c>
#include <gsl/fft/hc_unpack.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT

#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_real_float.h>

#define BASE_DOUBLE
#include <gsl/templates_on.h>
#include <gsl/fft/real_init.c>
#include <gsl/fft/real_main.c>
#include <gsl/fft/real_pass_2.c>
#include <gsl/fft/real_pass_3.c>
#include <gsl/fft/real_pass_4.c>
#include <gsl/fft/real_pass_5.c>
#include <gsl/fft/real_pass_n.c>
#include <gsl/fft/real_radix2.c>
#include <gsl/fft/real_unpack.c>
#include <gsl/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <gsl/templates_on.h>
#include <gsl/fft/real_init.c>
#include <gsl/fft/real_main.c>
#include <gsl/fft/real_pass_2.c>
#include <gsl/fft/real_pass_3.c>
#include <gsl/fft/real_pass_4.c>
#include <gsl/fft/real_pass_5.c>
#include <gsl/fft/real_pass_n.c>
#include <gsl/fft/real_radix2.c>
#include <gsl/fft/real_unpack.c>
#include <gsl/templates_off.h>
#undef  BASE_FLOAT
