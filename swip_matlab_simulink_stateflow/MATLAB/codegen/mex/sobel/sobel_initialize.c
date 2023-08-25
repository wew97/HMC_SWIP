/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * sobel_initialize.c
 *
 * Code generation for function 'sobel_initialize'
 *
 */

/* Include files */
#include "sobel_initialize.h"
#include "_coder_sobel_mex.h"
#include "rt_nonfinite.h"
#include "sobel_data.h"

/* Function Declarations */
static void sobel_once(void);

/* Function Definitions */
static void sobel_once(void)
{
  mex_InitInfAndNan();
}

void sobel_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    sobel_once();
  }
}

/* End of code generation (sobel_initialize.c) */
