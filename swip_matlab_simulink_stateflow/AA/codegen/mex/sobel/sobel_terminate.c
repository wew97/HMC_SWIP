/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * sobel_terminate.c
 *
 * Code generation for function 'sobel_terminate'
 *
 */

/* Include files */
#include "sobel_terminate.h"
#include "_coder_sobel_mex.h"
#include "rt_nonfinite.h"
#include "sobel_data.h"

/* Function Definitions */
void sobel_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void sobel_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sobel_terminate.c) */
