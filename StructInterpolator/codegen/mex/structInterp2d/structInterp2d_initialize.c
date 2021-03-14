/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * structInterp2d_initialize.c
 *
 * Code generation for function 'structInterp2d_initialize'
 *
 */

/* Include files */
#include "structInterp2d_initialize.h"
#include "_coder_structInterp2d_mex.h"
#include "rt_nonfinite.h"
#include "structInterp2d_data.h"

/* Function Definitions */
void structInterp2d_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (structInterp2d_initialize.c) */
