/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * sobel.c
 *
 * Code generation for function 'sobel'
 *
 */

/* Include files */
#include "sobel.h"
#include "conv2AXPYSameCMP.h"
#include "rt_nonfinite.h"
#include "sobel_data.h"
#include "sobel_emxutil.h"
#include "sobel_types.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    7,       /* lineNo */
    "sobel", /* fcnName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    8,       /* lineNo */
    "sobel", /* fcnName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    9,       /* lineNo */
    "sobel", /* fcnName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    58,      /* lineNo */
    "conv2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m" /* pathName
                                                                          */
};

static emlrtRSInfo e_emlrtRSI = {
    75,                  /* lineNo */
    "conv2NonSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m" /* pathName
                                                                          */
};

static emlrtRSInfo f_emlrtRSI = {
    105,     /* lineNo */
    "conv2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\conv2.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    32,          /* lineNo */
    "conv2AXPY", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\private\\conv2AXPY.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtECInfo emlrtECI = {
    2,       /* nDims */
    9,       /* lineNo */
    14,      /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    1,       /* nDims */
    9,       /* lineNo */
    14,      /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    10,      /* lineNo */
    5,       /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    7,       /* lineNo */
    5,       /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    8,       /* lineNo */
    5,       /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    9,       /* lineNo */
    14,      /* colNo */
    "sobel", /* fName */
    "C:\\Users\\user\\Desktop\\github\\HMC_SWIP\\swip_matlab_simulink_"
    "stateflow\\AA\\sobel.m" /* pName */
};

/* Function Declarations */
static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, &h_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  if (in2->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2->size[0];
  }
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_in1, i, &h_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in2->size[0];
    if (i1 == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &h_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void sobel(const emlrtStack *sp, const emxArray_real_T *originalImage,
           real_T threshold, emxArray_uint8_T *edgeImage)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *H;
  emxArray_real_T *V;
  real_T *H_data;
  real_T *V_data;
  int32_T i;
  int32_T k;
  int32_T nx;
  uint8_T *edgeImage_data;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  emxInit_real_T(&d_st, &H, &c_emlrtRTEI);
  e_st.site = &g_emlrtRSI;
  conv2AXPYSameCMP(&e_st, originalImage, H);
  H_data = H->data;
  st.site = &b_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  emxInit_real_T(&d_st, &V, &d_emlrtRTEI);
  e_st.site = &g_emlrtRSI;
  b_conv2AXPYSameCMP(&e_st, originalImage, V);
  V_data = V->data;
  nx = H->size[0] * H->size[1];
  for (i = 0; i < nx; i++) {
    H_data[i] *= H_data[i];
  }
  nx = V->size[0] * V->size[1];
  for (i = 0; i < nx; i++) {
    V_data[i] *= V_data[i];
  }
  if ((H->size[0] != V->size[0]) && ((H->size[0] != 1) && (V->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(H->size[0], V->size[0], &b_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((H->size[1] != V->size[1]) && ((H->size[1] != 1) && (V->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(H->size[1], V->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &c_emlrtRSI;
  if ((H->size[0] == V->size[0]) && (H->size[1] == V->size[1])) {
    nx = H->size[0] * H->size[1];
    for (i = 0; i < nx; i++) {
      H_data[i] += V_data[i];
    }
  } else {
    b_st.site = &c_emlrtRSI;
    plus(&b_st, H, V);
    H_data = H->data;
  }
  emxFree_real_T(&st, &V);
  p = false;
  i = H->size[0] * H->size[1];
  for (k = 0; k < i; k++) {
    if (p || (H_data[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    H_data[k] = muDoubleScalarSqrt(H_data[k]);
  }
  i = edgeImage->size[0] * edgeImage->size[1];
  edgeImage->size[0] = H->size[0];
  edgeImage->size[1] = H->size[1];
  emxEnsureCapacity_uint8_T(sp, edgeImage, i, &b_emlrtRTEI);
  edgeImage_data = edgeImage->data;
  nx = H->size[0] * H->size[1];
  for (i = 0; i < nx; i++) {
    edgeImage_data[i] = (uint8_T)((uint32_T)(H_data[i] > threshold) * 255U);
  }
  emxFree_real_T(sp, &H);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sobel.c) */
