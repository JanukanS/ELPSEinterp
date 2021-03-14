/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * closest_value.c
 *
 * Code generation for function 'closest_value'
 *
 */

/* Include files */
#include "closest_value.h"
#include "rt_nonfinite.h"
#include "structInterp2d_data.h"
#include "mwmathutil.h"

/* Function Definitions */
real_T closest_value(const emlrtStack *sp, const real_T A[54264], real_T val)
{
  real_T floorInd;
  real_T ind;
  real_T med;
  int32_T exitg1;

  /* if ~exist('floorInd','var') */
  floorInd = 1.0;

  /* end */
  /* if ~exist('ceilInd','var') */
  ind = 54264.0;

  /* end */
  do {
    exitg1 = 0;
    med = ind - floorInd;
    if (med > 1.0) {
      med = muDoubleScalarFloor((floorInd + ind) / 2.0);
      if (A[(int32_T)med - 1] >= val) {
        ind = med;
      } else {
        floorInd = med;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if ((!(med == 1.0)) || (!(A[(int32_T)floorInd - 1] <= val)) || (!(A[(int32_T)
        ind - 1] > val))) {
    ind = 0.0;
  }

  return ind;
}

/* End of code generation (closest_value.c) */
