/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * structInterp2d_emxAPI.h
 *
 * Code generation for function 'structInterp2d_emxAPI'
 *
 */

#ifndef STRUCTINTERP2D_EMXAPI_H
#define STRUCTINTERP2D_EMXAPI_H

/* Include files */
#include "rtwtypes.h"
#include "structInterp2d_types.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);
  extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
    numDimensions, const int *size);
  extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int
    cols);
  extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
  extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
  extern void emxDestroy_struct0_T(struct0_T emxArray);
  extern void emxInit_struct0_T(struct0_T *pStruct);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (structInterp2d_emxAPI.h) */
