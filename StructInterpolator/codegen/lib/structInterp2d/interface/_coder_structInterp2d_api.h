/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_structInterp2d_api.h
 *
 * Code generation for function 'structInterp2d'
 *
 */

#ifndef _CODER_STRUCTINTERP2D_API_H
#define _CODER_STRUCTINTERP2D_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T maxVal[2];
  real_T minVal[2];
  emxArray_real_T *orderNS;
  emxArray_real_T *indiceNS;
  emxArray_real_T *orderEW;
  emxArray_real_T *indiceEW;
  emxArray_real_T *pointsN;
  emxArray_real_T *pointsE;
  emxArray_real_T *trianglesN;
  emxArray_real_T *trianglesE;
  real_T lastQuery[2];
  real_T indexN;
  real_T indexE;
  emxArray_real_T *properT;
  emxArray_real_T *P;
  emxArray_real_T *T;
  emxArray_real_T *nodeVals;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  real_T structInterp2d(struct0_T *obj, real_T query[2]);
  void structInterp2d_api(const mxArray * const prhs[2], const mxArray *plhs[1]);
  void structInterp2d_atexit(void);
  void structInterp2d_initialize(void);
  void structInterp2d_terminate(void);
  void structInterp2d_xil_shutdown(void);
  void structInterp2d_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (_coder_structInterp2d_api.h) */
