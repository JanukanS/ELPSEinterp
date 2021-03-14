/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_structInterp2d_mex.c
 *
 * Code generation for function '_coder_structInterp2d_mex'
 *
 */

/* Include files */
#include "_coder_structInterp2d_mex.h"
#include "_coder_structInterp2d_api.h"
#include "rt_nonfinite.h"
#include "structInterp2d_data.h"
#include "structInterp2d_initialize.h"
#include "structInterp2d_terminate.h"
#include "structInterp2d_types.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  structInterp2dStackData *structInterp2dStackDataGlobal = NULL;
  structInterp2dStackDataGlobal = (structInterp2dStackData *)emlrtMxCalloc(1,
    (size_t)1U * sizeof(structInterp2dStackData));
  mexAtExit(&structInterp2d_atexit);

  /* Module initialization. */
  structInterp2d_initialize();

  /* Dispatch the entry-point. */
  structInterp2d_mexFunction(structInterp2dStackDataGlobal, nlhs, plhs, nrhs,
    prhs);

  /* Module termination. */
  structInterp2d_terminate();
  emlrtMxFree(structInterp2dStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

void structInterp2d_mexFunction(structInterp2dStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        14, "structInterp2d");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "structInterp2d");
  }

  /* Call the function. */
  structInterp2d_api(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/* End of code generation (_coder_structInterp2d_mex.c) */
