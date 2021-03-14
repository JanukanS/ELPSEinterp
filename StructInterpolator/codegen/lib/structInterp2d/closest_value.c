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
#include "structInterp2d_types.h"
#include <math.h>

/* Function Definitions */
double closest_value(const emxArray_real_T *A, double val)
{
  double ind;
  int ceilInd;
  int exitg1;
  int floorInd;
  int med;

  /* if ~exist('floorInd','var') */
  floorInd = 1;

  /* end */
  /* if ~exist('ceilInd','var') */
  ceilInd = A->size[0];

  /* end */
  do {
    exitg1 = 0;
    med = ceilInd - floorInd;
    if (med > 1) {
      med = (int)floor((double)((unsigned int)floorInd + ceilInd) / 2.0);
      if (A->data[med - 1] >= val) {
        ceilInd = med;
      } else {
        floorInd = med;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if ((med == 1) && (A->data[floorInd - 1] <= val) && (A->data[ceilInd - 1] >
       val)) {
    ind = ceilInd;
  } else {
    ind = 0.0;
  }

  return ind;
}

/* End of code generation (closest_value.c) */
