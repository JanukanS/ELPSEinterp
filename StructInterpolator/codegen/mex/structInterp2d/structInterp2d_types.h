/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * structInterp2d_types.h
 *
 * Code generation for function 'structInterp2d'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T maxVal[2];
  real_T minVal[2];
  real_T orderNS[54264];
  real_T indiceNS[54264];
  real_T orderEW[54264];
  real_T indiceEW[54264];
  real_T pointsN[54264];
  real_T pointsE[54264];
  real_T trianglesN[322644];
  real_T trianglesE[322644];
  real_T lastQuery[2];
  real_T indexN;
  real_T indexE;
  real_T properT[107548];
  real_T P[108528];
  real_T T[322644];
  real_T nodeVals[54264];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_emxArray_uint16_T
#define struct_emxArray_uint16_T

struct emxArray_uint16_T
{
  uint16_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint16_T*/

#ifndef typedef_emxArray_uint16_T
#define typedef_emxArray_uint16_T

typedef struct emxArray_uint16_T emxArray_uint16_T;

#endif                                 /*typedef_emxArray_uint16_T*/

#ifndef typedef_structInterp2dStackData
#define typedef_structInterp2dStackData

typedef struct {
  struct {
    real_T obj[322644];
    real_T sumN[107548];
    real_T sumE[107548];
  } f0;

  struct {
    struct0_T obj;
  } f1;
} structInterp2dStackData;

#endif                                 /*typedef_structInterp2dStackData*/

/* End of code generation (structInterp2d_types.h) */
