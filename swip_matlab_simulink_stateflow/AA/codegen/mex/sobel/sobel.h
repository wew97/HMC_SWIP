/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * sobel.h
 *
 * Code generation for function 'sobel'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "sobel_types.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void sobel(const emlrtStack *sp, const emxArray_real_T *originalImage,
           real_T threshold, emxArray_uint8_T *edgeImage);

/* End of code generation (sobel.h) */
