/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * structInterp2d_emxutil.h
 *
 * Code generation for function 'structInterp2d_emxutil'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "structInterp2d_types.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_uint16_T(const emlrtStack *sp, emxArray_uint16_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxFree_uint16_T(emxArray_uint16_T **pEmxArray);
void emxInit_uint16_T(const emlrtStack *sp, emxArray_uint16_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush);

/* End of code generation (structInterp2d_emxutil.h) */
