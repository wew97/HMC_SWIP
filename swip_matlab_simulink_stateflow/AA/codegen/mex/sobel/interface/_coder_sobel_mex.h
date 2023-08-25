/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_sobel_mex.h
 *
 * Code generation for function '_coder_sobel_mex'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void sobel_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                       const mxArray *prhs[2]);

/* End of code generation (_coder_sobel_mex.h) */
