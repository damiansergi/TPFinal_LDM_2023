/* cdf/binomial.c
 * 
 * Copyright (C) 2004 Jason H. Stover.
 * Copyright (C) 2004 Giulio Bottazzi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_sf_gamma.h>

#include <config.h>
#include <gsl/cdf/error.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_cdf.h>

double
gsl_cdf_binomial_P (const unsigned int k, const double p, const unsigned int n)
{
  double P;
  double a;
  double b;

  if (p > 1.0 || p < 0.0)
    {
      CDF_ERROR ("p < 0 or p > 1", GSL_EDOM);
    }

  if (k >= n)
    {
      P = 1.0;
    }
  else
    {
      a = (double) k + 1.0;
      b = (double) n - k;
      P = gsl_cdf_beta_Q (p, a, b);
    }

  return P;
}

double
gsl_cdf_binomial_Q (const unsigned int k, const double p, const unsigned int n)
{
  double Q;
  double a;
  double b;

  if (p > 1.0 || p < 0.0)
    {
      CDF_ERROR ("p < 0 or p > 1", GSL_EDOM);
    }

  if (k >= n)
    {
      Q = 0.0;
    }
  else
    {
      a = (double) k + 1.0;
      b = (double) n - k;
      Q = gsl_cdf_beta_P (p, a, b);
    }

  return Q;
}
