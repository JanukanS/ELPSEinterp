/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.c
 *
 * Code generation for function 'dot'
 *
 */

/* Include files */
#include "dot.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 12,  /* lineNo */
  23,                                  /* colNo */
  "dot",                               /* fName */
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/specfun/dot.m"/* pName */
};

/* Function Definitions */
real_T dot(const emlrtStack *sp, const real_T a[3], const real_T b_data[], const
           int32_T b_size[2])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T a_data[3];
  int32_T k;
  int8_T varargin_2[2];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  varargin_2[0] = (int8_T)b_size[0];
  varargin_2[1] = (int8_T)b_size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((k << 1) + 1 != varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = (int32_T)p;
  if ((!b_p) && (b_size[0] != 1)) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI, "MATLAB:dot:InputSizeMismatch",
      "MATLAB:dot:InputSizeMismatch", 0);
  }

  a_data[0] = a[0];
  a_data[1] = a[1];
  a_data[2] = a[2];
  n_t = (ptrdiff_t)3;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  return ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
}

/* End of code generation (dot.c) */
