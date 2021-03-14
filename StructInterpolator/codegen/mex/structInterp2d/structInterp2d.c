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
#include "dot.h"
#include "rt_nonfinite.h"
#include "structInterp2d_emxutil.h"
#include "structInterp2d_types.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 26,    /* lineNo */
  "structInterp2d",                    /* fcnName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 25,  /* lineNo */
  "structInterp2d",                    /* fcnName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 24,  /* lineNo */
  "structInterp2d",                    /* fcnName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  54264,                               /* iLast */
  11,                                  /* lineNo */
  30,                                  /* colNo */
  "obj.indiceEW",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  10,                                  /* lineNo */
  32,                                  /* colNo */
  "obj.indiceEW",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  9,                                   /* lineNo */
  30,                                  /* colNo */
  "obj.indiceNS",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  8,                                   /* lineNo */
  32,                                  /* colNo */
  "obj.indiceNS",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "obj.pointsN",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 9,   /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  9,                                   /* lineNo */
  17,                                  /* colNo */
  "obj.pointsN",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 10,  /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  10,                                  /* lineNo */
  17,                                  /* colNo */
  "obj.pointsE",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 11,  /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  11,                                  /* lineNo */
  17,                                  /* colNo */
  "obj.pointsE",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  14,                                  /* lineNo */
  38,                                  /* colNo */
  "obj.pointsN",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 14,  /* lineNo */
  38,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  15,                                  /* lineNo */
  38,                                  /* colNo */
  "obj.pointsE",                       /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 15,  /* lineNo */
  38,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 24,  /* lineNo */
  31,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "obj.P",                             /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  25,                                  /* lineNo */
  28,                                  /* colNo */
  "obj.nodeVals",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 25,  /* lineNo */
  28,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  25,                                  /* lineNo */
  58,                                  /* colNo */
  "obj.nodeVals",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 25,  /* lineNo */
  58,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  54264,                               /* iLast */
  25,                                  /* lineNo */
  88,                                  /* colNo */
  "obj.nodeVals",                      /* aName */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 25,  /* lineNo */
  88,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  20,                                  /* colNo */
  "triCoords",                         /* aName */
  "findBary",                          /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  20,                                  /* colNo */
  "triCoords",                         /* aName */
  "findBary",                          /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 8, /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 9, /* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 10,/* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 11,/* lineNo */
  17,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  16,                                  /* colNo */
  "structInterp2d",                    /* fName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pName */
};

static emlrtRSInfo f_emlrtRSI = { 4,   /* lineNo */
  "structInterp2d",                    /* fcnName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 3,   /* lineNo */
  "structInterp2d",                    /* fcnName */
  "/home/janukan/CapstoneWinter/interpolation/ELPSEinterp/StructInterpolator/structInterp2d.m"/* pathName */
};

/* Function Declarations */
static void findBary(const emlrtStack *sp, const real_T triCoords_data[], const
                     int32_T triCoords_size[2], const real_T query[2], real_T
                     bCoord[3]);

/* Function Definitions */
static void findBary(const emlrtStack *sp, const real_T triCoords_data[], const
                     int32_T triCoords_size[2], const real_T query[2], real_T
                     bCoord[3])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T a_data[2];
  real_T b_data[2];
  real_T d00;
  real_T d01;
  real_T d11;
  real_T d20;
  real_T v0_idx_0;
  real_T v0_idx_1;
  real_T v1_idx_0;
  real_T v1_idx_1;
  real_T v2_idx_0;
  real_T v2_idx_1;
  if (2 > triCoords_size[0]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, triCoords_size[0], &o_emlrtBCI, sp);
  }

  v0_idx_0 = triCoords_data[1] - triCoords_data[0];
  v2_idx_1 = triCoords_data[triCoords_size[0]];
  v0_idx_1 = triCoords_data[triCoords_size[0] + 1] - v2_idx_1;
  if (3 > triCoords_size[0]) {
    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &p_emlrtBCI, sp);
  }

  v1_idx_0 = triCoords_data[2] - triCoords_data[0];
  v1_idx_1 = triCoords_data[triCoords_size[0] + 2] - v2_idx_1;
  v2_idx_0 = query[0] - triCoords_data[0];
  a_data[0] = v0_idx_0;
  b_data[0] = v0_idx_0;
  v2_idx_1 = query[1] - v2_idx_1;
  a_data[1] = v0_idx_1;
  b_data[1] = v0_idx_1;
  n_t = (ptrdiff_t)2;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  d00 = ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
  a_data[0] = v0_idx_0;
  b_data[0] = v1_idx_0;
  a_data[1] = v0_idx_1;
  b_data[1] = v1_idx_1;
  n_t = (ptrdiff_t)2;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  d01 = ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
  a_data[0] = v1_idx_0;
  b_data[0] = v1_idx_0;
  a_data[1] = v1_idx_1;
  b_data[1] = v1_idx_1;
  n_t = (ptrdiff_t)2;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  d11 = ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
  a_data[0] = v2_idx_0;
  b_data[0] = v0_idx_0;
  a_data[1] = v2_idx_1;
  b_data[1] = v0_idx_1;
  n_t = (ptrdiff_t)2;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  d20 = ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
  a_data[0] = v2_idx_0;
  b_data[0] = v1_idx_0;
  a_data[1] = v2_idx_1;
  b_data[1] = v1_idx_1;
  n_t = (ptrdiff_t)2;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  v2_idx_1 = ddot(&n_t, &a_data[0], &incx_t, &b_data[0], &incy_t);
  v0_idx_0 = d00 * d11 - d01 * d01;
  v0_idx_1 = (d11 * d20 - d01 * v2_idx_1) / v0_idx_0;
  v2_idx_1 = (d00 * v2_idx_1 - d01 * d20) / v0_idx_0;
  bCoord[0] = (1.0 - v0_idx_1) - v2_idx_1;
  bCoord[1] = v0_idx_1;
  bCoord[2] = v2_idx_1;
}

real_T structInterp2d(structInterp2dStackData *SD, const emlrtStack *sp,
                      struct0_T *obj, const real_T query[2])
{
  emlrtStack st;
  emxArray_uint16_T *r;
  emxArray_uint16_T *r1;
  real_T b_obj_data[6];
  real_T b_varargin_1_data[3];
  real_T baryCoord[3];
  real_T varargin_1_data[1];
  real_T varargin_2_data[1];
  real_T varargin_3_data[1];
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T value;
  int32_T obj_data[3];
  int32_T obj_size[2];
  int32_T varargin_1_size[2];
  int32_T ii_data[1];
  int32_T j;
  int32_T k;
  int32_T xoffset;
  boolean_T x[107548];
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* obj.resetIndex(query); */
  st.site = &g_emlrtRSI;
  obj->indexN = closest_value(&st, obj->orderNS, query[0]);
  st.site = &f_emlrtRSI;
  obj->indexE = closest_value(&st, obj->orderEW, query[1]);

  /* obj.locateIndex(); */
  if (1.0 > obj->indexN - 1.0) {
    xoffset = 0;
  } else {
    if (((int32_T)(obj->indexN - 1.0) < 1) || ((int32_T)(obj->indexN - 1.0) >
         54264)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(obj->indexN - 1.0), 1, 54264,
        &d_emlrtBCI, sp);
    }

    xoffset = (int32_T)(obj->indexN - 1.0);
  }

  emxInit_uint16_T(sp, &r, 2, &f_emlrtRTEI, true);
  k = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = xoffset;
  emxEnsureCapacity_uint16_T(sp, r, k, &b_emlrtRTEI);
  for (k = 0; k < xoffset; k++) {
    d = obj->indiceNS[k];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, sp);
    }

    if (((uint16_T)d < 1) || ((uint16_T)d > 54264)) {
      emlrtDynamicBoundsCheckR2012b((uint16_T)d, 1, 54264, &e_emlrtBCI, sp);
    }

    r->data[k] = (uint16_T)d;
  }

  xoffset = r->size[0] * r->size[1];
  for (k = 0; k < xoffset; k++) {
    obj->pointsN[r->data[k] - 1] = 0.0;
  }

  if (((int32_T)obj->indexN < 1) || ((int32_T)obj->indexN > 54264)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)obj->indexN, 1, 54264, &c_emlrtBCI,
      sp);
  }

  emxInit_uint16_T(sp, &r1, 2, &f_emlrtRTEI, true);
  k = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = 54265 - (int32_T)obj->indexN;
  emxEnsureCapacity_uint16_T(sp, r1, k, &c_emlrtRTEI);
  xoffset = 54265 - (int32_T)obj->indexN;
  for (k = 0; k < xoffset; k++) {
    d = obj->indiceNS[((int32_T)obj->indexN + k) - 1];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, sp);
    }

    if (((uint16_T)d < 1) || ((uint16_T)d > 54264)) {
      emlrtDynamicBoundsCheckR2012b((uint16_T)d, 1, 54264, &f_emlrtBCI, sp);
    }

    r1->data[k] = (uint16_T)d;
  }

  xoffset = r1->size[0] * r1->size[1];
  for (k = 0; k < xoffset; k++) {
    obj->pointsN[r1->data[k] - 1] = 1.0;
  }

  if (1.0 > obj->indexE - 1.0) {
    xoffset = 0;
  } else {
    if (((int32_T)(obj->indexE - 1.0) < 1) || ((int32_T)(obj->indexE - 1.0) >
         54264)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(obj->indexE - 1.0), 1, 54264,
        &b_emlrtBCI, sp);
    }

    xoffset = (int32_T)(obj->indexE - 1.0);
  }

  k = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = xoffset;
  emxEnsureCapacity_uint16_T(sp, r, k, &d_emlrtRTEI);
  for (k = 0; k < xoffset; k++) {
    d = obj->indiceEW[k];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &c_emlrtDCI, sp);
    }

    if (((uint16_T)d < 1) || ((uint16_T)d > 54264)) {
      emlrtDynamicBoundsCheckR2012b((uint16_T)d, 1, 54264, &g_emlrtBCI, sp);
    }

    r->data[k] = (uint16_T)d;
  }

  xoffset = r->size[0] * r->size[1];
  for (k = 0; k < xoffset; k++) {
    obj->pointsE[r->data[k] - 1] = 0.0;
  }

  emxFree_uint16_T(&r);
  if (((int32_T)obj->indexE < 1) || ((int32_T)obj->indexE > 54264)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)obj->indexE, 1, 54264, &emlrtBCI, sp);
  }

  k = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = 54265 - (int32_T)obj->indexE;
  emxEnsureCapacity_uint16_T(sp, r1, k, &e_emlrtRTEI);
  xoffset = 54265 - (int32_T)obj->indexE;
  for (k = 0; k < xoffset; k++) {
    d = obj->indiceEW[((int32_T)obj->indexE + k) - 1];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &d_emlrtDCI, sp);
    }

    if (((uint16_T)d < 1) || ((uint16_T)d > 54264)) {
      emlrtDynamicBoundsCheckR2012b((uint16_T)d, 1, 54264, &h_emlrtBCI, sp);
    }

    r1->data[k] = (uint16_T)d;
  }

  xoffset = r1->size[0] * r1->size[1];
  for (k = 0; k < xoffset; k++) {
    obj->pointsE[r1->data[k] - 1] = 1.0;
  }

  emxFree_uint16_T(&r1);

  /* obj.sortTri(); */
  for (k = 0; k < 322644; k++) {
    if (obj->T[k] != (int32_T)muDoubleScalarFloor(obj->T[k])) {
      emlrtIntegerCheckR2012b(obj->T[k], &e_emlrtDCI, sp);
    }

    xoffset = (int32_T)obj->T[k];
    if ((xoffset < 1) || (xoffset > 54264)) {
      emlrtDynamicBoundsCheckR2012b(xoffset, 1, 54264, &i_emlrtBCI, sp);
    }

    SD->f0.obj[k] = obj->pointsN[xoffset - 1];
  }

  memcpy(&obj->trianglesN[0], &SD->f0.obj[0], 322644U * sizeof(real_T));
  for (k = 0; k < 322644; k++) {
    if (obj->T[k] != (int32_T)muDoubleScalarFloor(obj->T[k])) {
      emlrtIntegerCheckR2012b(obj->T[k], &f_emlrtDCI, sp);
    }

    xoffset = (int32_T)obj->T[k];
    if ((xoffset < 1) || (xoffset > 54264)) {
      emlrtDynamicBoundsCheckR2012b(xoffset, 1, 54264, &j_emlrtBCI, sp);
    }

    SD->f0.obj[k] = obj->pointsE[xoffset - 1];
  }

  memcpy(&obj->trianglesE[0], &SD->f0.obj[0], 322644U * sizeof(real_T));
  memcpy(&SD->f0.sumN[0], &obj->trianglesN[0], 107548U * sizeof(real_T));
  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 107548;
    for (j = 0; j < 107548; j++) {
      SD->f0.sumN[j] += obj->trianglesN[xoffset + j];
    }
  }

  memcpy(&SD->f0.sumE[0], &obj->trianglesE[0], 107548U * sizeof(real_T));
  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 107548;
    for (j = 0; j < 107548; j++) {
      SD->f0.sumE[j] += obj->trianglesE[xoffset + j];
    }
  }

  for (xoffset = 0; xoffset < 107548; xoffset++) {
    d = SD->f0.sumN[xoffset];
    d1 = SD->f0.sumE[xoffset];
    x[xoffset] = ((d > 0.0) && (d < 3.0) && ((d1 > 0.0) && (d1 < 3.0)));
  }

  xoffset = 0;
  j = 1;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 107548)) {
    if (x[k]) {
      xoffset = 1;
      ii_data[0] = k + 1;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (xoffset == 0) {
    j = 0;
  }

  /* value = obj.interpOp(triInd,query); */
  for (k = 0; k < 3; k++) {
    if (0 <= j - 1) {
      d2 = obj->T[(ii_data[0] + 107548 * k) - 1];
      obj_data[j * k] = (int32_T)d2;
    }

    for (xoffset = 0; xoffset < j; xoffset++) {
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &g_emlrtDCI, sp);
      }

      if (((int32_T)d2 < 1) || ((int32_T)d2 > 54264)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, 54264, &k_emlrtBCI, sp);
      }
    }
  }

  xoffset = j * 3;
  obj_size[0] = xoffset;
  obj_size[1] = 2;
  for (k = 0; k < xoffset; k++) {
    b_obj_data[k] = obj->P[obj_data[k] - 1];
  }

  for (k = 0; k < xoffset; k++) {
    b_obj_data[k + xoffset] = obj->P[obj_data[k] + 54263];
  }

  st.site = &c_emlrtRSI;
  findBary(&st, b_obj_data, obj_size, query, baryCoord);
  st.site = &b_emlrtRSI;
  if (0 <= j - 1) {
    d3 = obj->T[ii_data[0] - 1];
    varargin_1_data[0] = obj->nodeVals[(int32_T)d3 - 1];
  }

  for (k = 0; k < j; k++) {
    if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
      emlrtIntegerCheckR2012b(d3, &h_emlrtDCI, &st);
    }

    if (((int32_T)d3 < 1) || ((int32_T)d3 > 54264)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d3, 1, 54264, &l_emlrtBCI, &st);
    }
  }

  if (0 <= j - 1) {
    d4 = obj->T[ii_data[0] - 1];
    varargin_2_data[0] = obj->nodeVals[(int32_T)d4 - 1];
  }

  for (k = 0; k < j; k++) {
    if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
      emlrtIntegerCheckR2012b(d4, &i_emlrtDCI, &st);
    }

    if (((int32_T)d4 < 1) || ((int32_T)d4 > 54264)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d4, 1, 54264, &m_emlrtBCI, &st);
    }
  }

  if (0 <= j - 1) {
    d5 = obj->T[ii_data[0] - 1];
    varargin_3_data[0] = obj->nodeVals[(int32_T)d5 - 1];
  }

  for (k = 0; k < j; k++) {
    if (d5 != (int32_T)muDoubleScalarFloor(d5)) {
      emlrtIntegerCheckR2012b(d5, &j_emlrtDCI, &st);
    }

    if (((int32_T)d5 < 1) || ((int32_T)d5 > 54264)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d5, 1, 54264, &n_emlrtBCI, &st);
    }
  }

  varargin_1_size[0] = j;
  varargin_1_size[1] = 3;
  if (0 <= j - 1) {
    b_varargin_1_data[0] = varargin_1_data[0];
    b_varargin_1_data[j] = varargin_2_data[0];
    b_varargin_1_data[j * 2] = varargin_3_data[0];
  }

  st.site = &emlrtRSI;
  value = dot(&st, baryCoord, b_varargin_1_data, varargin_1_size);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return value;
}

/* End of code generation (structInterp2d.c) */
