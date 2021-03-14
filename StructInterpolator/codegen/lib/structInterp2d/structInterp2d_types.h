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

#ifndef STRUCTINTERP2D_TYPES_H
#define STRUCTINTERP2D_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double maxVal[2];
  double minVal[2];
  emxArray_real_T *orderNS;
  emxArray_real_T *indiceNS;
  emxArray_real_T *orderEW;
  emxArray_real_T *indiceEW;
  emxArray_real_T *pointsN;
  emxArray_real_T *pointsE;
  emxArray_real_T *trianglesN;
  emxArray_real_T *trianglesE;
  double lastQuery[2];
  double indexN;
  double indexE;
  emxArray_real_T *properT;
  emxArray_real_T *P;
  emxArray_real_T *T;
  emxArray_real_T *nodeVals;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/
#endif

/* End of code generation (structInterp2d_types.h) */
