/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * structInterp2d.c
 *
 * Code generation for function 'structInterp2d'
 *
 */

/* Include files */
#include "structInterp2d.h"
#include "closest_value.h"
#include "structInterp2d_emxutil.h"
#include "structInterp2d_types.h"

/* Function Definitions */
double structInterp2d(struct0_T *obj, const double query[2])
{
  emxArray_boolean_T *x;
  emxArray_int32_T *r;
  emxArray_real_T *b_obj;
  emxArray_real_T *sumE;
  emxArray_real_T *sumN;
  double triCoords_data[6];
  double triVals_data[3];
  double d;
  double d00;
  double d01;
  double d11;
  double d20;
  double d21;
  double denom;
  double v;
  int obj_data[3];
  int ii_data[1];
  unsigned int triInd_data[1];
  int i;
  int j;
  int vstride;
  int xoffset;
  boolean_T exitg1;
  emxInit_int32_T(&r, 2);

  /* obj.resetIndex(query); */
  obj->indexN = closest_value(obj->orderNS, query[0]);
  obj->indexE = closest_value(obj->orderEW, query[1]);

  /* obj.locateIndex(); */
  if (1.0 > obj->indexN - 1.0) {
    xoffset = 0;
  } else {
    xoffset = (int)(obj->indexN - 1.0);
  }

  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = xoffset;
  emxEnsureCapacity_int32_T(r, i);
  for (i = 0; i < xoffset; i++) {
    r->data[i] = (int)obj->indiceNS->data[i];
  }

  xoffset = r->size[0] * r->size[1];
  for (i = 0; i < xoffset; i++) {
    obj->pointsN->data[r->data[i] - 1] = 0.0;
  }

  if (obj->indexN > obj->indiceNS->size[0]) {
    i = 0;
    j = 0;
  } else {
    i = (int)obj->indexN - 1;
    j = obj->indiceNS->size[0];
  }

  vstride = r->size[0] * r->size[1];
  r->size[0] = 1;
  xoffset = j - i;
  r->size[1] = xoffset;
  emxEnsureCapacity_int32_T(r, vstride);
  for (j = 0; j < xoffset; j++) {
    r->data[j] = (int)obj->indiceNS->data[i + j];
  }

  xoffset = r->size[0] * r->size[1];
  for (i = 0; i < xoffset; i++) {
    obj->pointsN->data[r->data[i] - 1] = 1.0;
  }

  if (1.0 > obj->indexE - 1.0) {
    xoffset = 0;
  } else {
    xoffset = (int)(obj->indexE - 1.0);
  }

  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = xoffset;
  emxEnsureCapacity_int32_T(r, i);
  for (i = 0; i < xoffset; i++) {
    r->data[i] = (int)obj->indiceEW->data[i];
  }

  xoffset = r->size[0] * r->size[1];
  for (i = 0; i < xoffset; i++) {
    obj->pointsE->data[r->data[i] - 1] = 0.0;
  }

  if (obj->indexE > obj->indiceEW->size[0]) {
    i = 0;
    j = 0;
  } else {
    i = (int)obj->indexE - 1;
    j = obj->indiceEW->size[0];
  }

  vstride = r->size[0] * r->size[1];
  r->size[0] = 1;
  xoffset = j - i;
  r->size[1] = xoffset;
  emxEnsureCapacity_int32_T(r, vstride);
  for (j = 0; j < xoffset; j++) {
    r->data[j] = (int)obj->indiceEW->data[i + j];
  }

  xoffset = r->size[0] * r->size[1];
  for (i = 0; i < xoffset; i++) {
    obj->pointsE->data[r->data[i] - 1] = 1.0;
  }

  emxFree_int32_T(&r);
  emxInit_real_T(&b_obj, 2);

  /* obj.sortTri(); */
  i = b_obj->size[0] * b_obj->size[1];
  b_obj->size[0] = obj->T->size[0];
  b_obj->size[1] = 3;
  emxEnsureCapacity_real_T(b_obj, i);
  xoffset = obj->T->size[0] * obj->T->size[1];
  for (i = 0; i < xoffset; i++) {
    b_obj->data[i] = obj->pointsN->data[(int)obj->T->data[i] - 1];
  }

  xoffset = b_obj->size[0];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < xoffset; j++) {
      obj->trianglesN->data[j + obj->trianglesN->size[0] * i] = b_obj->data[j +
        b_obj->size[0] * i];
    }
  }

  i = b_obj->size[0] * b_obj->size[1];
  b_obj->size[0] = obj->T->size[0];
  b_obj->size[1] = 3;
  emxEnsureCapacity_real_T(b_obj, i);
  xoffset = obj->T->size[0] * obj->T->size[1];
  for (i = 0; i < xoffset; i++) {
    b_obj->data[i] = obj->pointsE->data[(int)obj->T->data[i] - 1];
  }

  xoffset = b_obj->size[0];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < xoffset; j++) {
      obj->trianglesE->data[j + obj->trianglesE->size[0] * i] = b_obj->data[j +
        b_obj->size[0] * i];
    }
  }

  emxFree_real_T(&b_obj);
  emxInit_real_T(&sumN, 1);
  if (obj->trianglesN->size[0] == 0) {
    i = sumN->size[0];
    sumN->size[0] = obj->trianglesN->size[0];
    emxEnsureCapacity_real_T(sumN, i);
    xoffset = obj->trianglesN->size[0];
    for (i = 0; i < xoffset; i++) {
      sumN->data[i] = 0.0;
    }
  } else {
    vstride = obj->trianglesN->size[0];
    i = sumN->size[0];
    sumN->size[0] = obj->trianglesN->size[0];
    emxEnsureCapacity_real_T(sumN, i);
    xoffset = 2 * obj->trianglesN->size[0];
    for (j = 0; j < vstride; j++) {
      sumN->data[j] = obj->trianglesN->data[j];
      sumN->data[j] += obj->trianglesN->data[vstride + j];
      sumN->data[j] += obj->trianglesN->data[xoffset + j];
    }
  }

  emxInit_real_T(&sumE, 1);
  if (obj->trianglesE->size[0] == 0) {
    i = sumE->size[0];
    sumE->size[0] = obj->trianglesE->size[0];
    emxEnsureCapacity_real_T(sumE, i);
    xoffset = obj->trianglesE->size[0];
    for (i = 0; i < xoffset; i++) {
      sumE->data[i] = 0.0;
    }
  } else {
    vstride = obj->trianglesE->size[0];
    i = sumE->size[0];
    sumE->size[0] = obj->trianglesE->size[0];
    emxEnsureCapacity_real_T(sumE, i);
    xoffset = 2 * obj->trianglesE->size[0];
    for (j = 0; j < vstride; j++) {
      sumE->data[j] = obj->trianglesE->data[j];
      sumE->data[j] += obj->trianglesE->data[vstride + j];
      sumE->data[j] += obj->trianglesE->data[xoffset + j];
    }
  }

  xoffset = sumN->size[0];
  for (i = 0; i < xoffset; i++) {
    obj->properT->data[i] = ((sumN->data[i] > 0.0) && (sumN->data[i] < 3.0) &&
      ((sumE->data[i] > 0.0) && (sumE->data[i] < 3.0)));
  }

  emxFree_real_T(&sumE);
  emxFree_real_T(&sumN);
  emxInit_boolean_T(&x, 1);
  i = x->size[0];
  x->size[0] = obj->properT->size[0];
  emxEnsureCapacity_boolean_T(x, i);
  xoffset = obj->properT->size[0];
  for (i = 0; i < xoffset; i++) {
    x->data[i] = (obj->properT->data[i] == 1.0);
  }

  j = (1 <= x->size[0]);
  xoffset = 0;
  vstride = 0;
  exitg1 = false;
  while ((!exitg1) && (vstride <= x->size[0] - 1)) {
    if (x->data[vstride]) {
      xoffset = 1;
      ii_data[0] = vstride + 1;
      exitg1 = true;
    } else {
      vstride++;
    }
  }

  emxFree_boolean_T(&x);
  if (j == 1) {
    if (xoffset == 0) {
      j = 0;
    }
  } else {
    j = (1 <= xoffset);
  }

  if (0 <= j - 1) {
    triInd_data[0] = (unsigned int)ii_data[0];
  }

  /* value = obj.interpOp(triInd,query); */
  for (i = 0; i < 3; i++) {
    if (0 <= j - 1) {
      obj_data[j * i] = (int)obj->T->data[((int)triInd_data[0] + obj->T->size[0]
        * i) - 1];
    }
  }

  xoffset = j * 3;
  for (i = 0; i < xoffset; i++) {
    triCoords_data[i] = obj->P->data[obj_data[i] - 1];
  }

  denom = triCoords_data[1] - triCoords_data[0];
  v = triCoords_data[2] - triCoords_data[0];
  d = query[0] - triCoords_data[0];
  d00 = denom * denom;
  d01 = denom * v;
  d11 = v * v;
  d20 = d * denom;
  d21 = d * v;
  for (i = 0; i < xoffset; i++) {
    triCoords_data[i + xoffset] = obj->P->data[(obj_data[i] + obj->P->size[0]) -
      1];
  }

  d = triCoords_data[xoffset];
  denom = triCoords_data[xoffset + 1] - d;
  v = triCoords_data[xoffset + 2] - d;
  d = query[1] - d;
  d00 += denom * denom;
  d01 += denom * v;
  d11 += v * v;
  d20 += d * denom;
  d21 += d * v;
  denom = d00 * d11 - d01 * d01;
  v = (d11 * d20 - d01 * d21) / denom;
  denom = (d00 * d21 - d01 * d20) / denom;
  for (i = 0; i < 3; i++) {
    if (0 <= j - 1) {
      triVals_data[j * i] = obj->nodeVals->data[(int)obj->T->data[((int)
        triInd_data[0] + obj->T->size[0] * i) - 1] - 1];
    }
  }

  return (((1.0 - v) - denom) * triVals_data[0] + v * triVals_data[1]) + denom *
    triVals_data[2];
}

/* End of code generation (structInterp2d.c) */
