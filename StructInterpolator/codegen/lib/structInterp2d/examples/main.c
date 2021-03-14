/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "structInterp2d.h"
#include "structInterp2d_emxAPI.h"
#include "structInterp2d_terminate.h"
#include "structInterp2d_types.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static emxArray_real_T *argInit_Unboundedx2_real_T(void);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void main_structInterp2d(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  static const int iv[1] = { 2 };

  emxArray_real_T *result;
  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx2_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx3_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 3);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 3; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x2_real_T(result->maxVal);
  result_tmp = argInit_real_T();
  result->indexE = result_tmp;
  result->orderNS = argInit_Unboundedx1_real_T();
  result->indiceNS = argInit_Unboundedx1_real_T();
  result->orderEW = argInit_Unboundedx1_real_T();
  result->indiceEW = argInit_Unboundedx1_real_T();
  result->pointsN = argInit_Unboundedx1_real_T();
  result->pointsE = argInit_Unboundedx1_real_T();
  result->trianglesN = argInit_Unboundedx3_real_T();
  result->trianglesE = argInit_Unboundedx3_real_T();
  result->indexN = result_tmp;
  result->properT = argInit_Unboundedx1_real_T();
  result->P = argInit_Unboundedx2_real_T();
  result->T = argInit_Unboundedx3_real_T();
  result->nodeVals = argInit_Unboundedx1_real_T();
  result->minVal[0] = result->maxVal[0];
  result->lastQuery[0] = result->maxVal[0];
  result->minVal[1] = result->maxVal[1];
  result->lastQuery[1] = result->maxVal[1];
}

static void main_structInterp2d(void)
{
  struct0_T b_obj;
  struct0_T obj;
  double dv[2];
  double value;

  /* Initialize function 'structInterp2d' input arguments. */
  /* Initialize function input argument 'obj'. */
  argInit_struct0_T(&obj);

  /* Initialize function input argument 'query'. */
  /* Call the entry-point 'structInterp2d'. */
  argInit_1x2_real_T(dv);
  b_obj = obj;
  value = structInterp2d(&b_obj, dv);
  emxDestroy_struct0_T(obj);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_structInterp2d();

  /* Terminate the application.
     You do not need to do this more than one time. */
  structInterp2d_terminate();
  return 0;
}

/* End of code generation (main.c) */
