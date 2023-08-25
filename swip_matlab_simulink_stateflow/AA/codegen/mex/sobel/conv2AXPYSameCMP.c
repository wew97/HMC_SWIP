/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * conv2AXPYSameCMP.c
 *
 * Code generation for function 'conv2AXPYSameCMP'
 *
 */

/* Include files */
#include "conv2AXPYSameCMP.h"
#include "rt_nonfinite.h"
#include "sobel_emxutil.h"
#include "sobel_types.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = {
    26,                 /* lineNo */
    5,                  /* colNo */
    "conv2AXPYSameCMP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\private\\conv2AXPYSameCMP.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    34,                 /* lineNo */
    20,                 /* colNo */
    "conv2AXPYSameCMP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\private\\conv2AXPYSameCMP.m" /* pName */
};

/* Function Definitions */
void b_conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
                        emxArray_real_T *c)
{
  static const int8_T b[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
  jmp_buf emlrtJBEnviron;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  real_T cj_data[1024];
  const real_T *a_data;
  real_T bij;
  real_T *c_data;
  int32_T b_conv2AXPYSameCMP_numThreads;
  int32_T i;
  int32_T ib;
  int32_T ic0;
  int32_T imax;
  int32_T imin;
  int32_T j;
  int32_T jb;
  int32_T jbmax;
  int32_T jbmin;
  int32_T jcut;
  int32_T ma;
  int32_T na;
  int32_T ub_loop;
  boolean_T bijNotZero;
  boolean_T emlrtHadParallelError = false;
  a_data = a->data;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, i, &f_emlrtRTEI);
    c_data = c->data;
    ub_loop = a->size[0] * a->size[1];
    for (i = 0; i < ub_loop; i++) {
      c_data[i] = 0.0;
    }
  } else {
    jcut = a->size[1] - 1;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, i, &g_emlrtRTEI);
    c_data = c->data;
    ub_loop = a->size[1] - 1;
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    b_conv2AXPYSameCMP_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_conv2AXPYSameCMP_numThreads) private(       \
    imax, imin, ic0, bijNotZero, bij, jbmax, jbmin, cj_data, st,               \
    emlrtJBEnviron, jb, ib, n_t, incx_t, incy_t)                               \
    firstprivate(emlrtHadParallelError)
    {
      if (setjmp(emlrtJBEnviron) == 0) {
        st.prev = sp;
        st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
        st.site = NULL;
        emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }
#pragma omp for nowait
      for (j = 0; j <= ub_loop; j++) {
        if (emlrtHadParallelError) {
          continue;
        }
        if (setjmp(emlrtJBEnviron) == 0) {
          if (ma - 1 >= 0) {
            memset(&cj_data[0], 0, (uint32_T)ma * sizeof(real_T));
          }
          jbmin = (j + 1 <= 1);
          if (j + 1 < jcut) {
            jbmax = 2;
          } else {
            jbmax = na - j;
          }
          for (jb = jbmin; jb <= jbmax; jb++) {
            for (ib = 0; ib < 3; ib++) {
              bij = b[(3 * (2 - jb) - ib) + 2];
              bijNotZero = (bij != 0.0);
              if (bijNotZero) {
                if (ib < 1) {
                  ic0 = 2;
                  imin = ma - 1;
                } else {
                  ic0 = 1;
                  imin = (ma - ib) + 1;
                }
                imax = ((ic0 + ib) + ((jb + j) - 1) * ma) - 1;
                if (imin >= 1) {
                  n_t = (ptrdiff_t)imin;
                  incx_t = (ptrdiff_t)1;
                  incy_t = (ptrdiff_t)1;
                  daxpy(&n_t, &bij, (real_T *)&a_data[imax - 1], &incx_t,
                        &cj_data[ic0 - 1], &incy_t);
                }
              } else {
                if (ib < 1) {
                  imin = 2;
                  imax = ma;
                } else {
                  imin = 1;
                  imax = (ma - ib) + 1;
                }
                for (ic0 = imin; ic0 <= imax; ic0++) {
                  cj_data[ic0 - 1] +=
                      bij *
                      a_data[((ic0 + ib) + a->size[0] * ((j + jb) - 1)) - 2];
                }
              }
            }
          }
          for (imax = 0; imax < ma; imax++) {
            c_data[imax + c->size[0] * j] = cj_data[imax];
          }
        } else {
          emlrtHadParallelError = true;
        }
      }
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
}

void conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
                      emxArray_real_T *c)
{
  static const int8_T b[9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
  jmp_buf emlrtJBEnviron;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  real_T cj_data[1024];
  const real_T *a_data;
  real_T bij;
  real_T *c_data;
  int32_T conv2AXPYSameCMP_numThreads;
  int32_T i;
  int32_T ib;
  int32_T ic0;
  int32_T imax;
  int32_T imin;
  int32_T j;
  int32_T jb;
  int32_T jbmax;
  int32_T jbmin;
  int32_T jcut;
  int32_T ma;
  int32_T na;
  int32_T ub_loop;
  boolean_T bijNotZero;
  boolean_T emlrtHadParallelError = false;
  a_data = a->data;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, i, &f_emlrtRTEI);
    c_data = c->data;
    ub_loop = a->size[0] * a->size[1];
    for (i = 0; i < ub_loop; i++) {
      c_data[i] = 0.0;
    }
  } else {
    jcut = a->size[1] - 1;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, i, &g_emlrtRTEI);
    c_data = c->data;
    ub_loop = a->size[1] - 1;
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    conv2AXPYSameCMP_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(conv2AXPYSameCMP_numThreads) private(         \
    imax, imin, ic0, bijNotZero, bij, jbmax, jbmin, cj_data, st,               \
    emlrtJBEnviron, jb, ib, n_t, incx_t, incy_t)                               \
    firstprivate(emlrtHadParallelError)
    {
      if (setjmp(emlrtJBEnviron) == 0) {
        st.prev = sp;
        st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
        st.site = NULL;
        emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }
#pragma omp for nowait
      for (j = 0; j <= ub_loop; j++) {
        if (emlrtHadParallelError) {
          continue;
        }
        if (setjmp(emlrtJBEnviron) == 0) {
          if (ma - 1 >= 0) {
            memset(&cj_data[0], 0, (uint32_T)ma * sizeof(real_T));
          }
          jbmin = (j + 1 <= 1);
          if (j + 1 < jcut) {
            jbmax = 2;
          } else {
            jbmax = na - j;
          }
          for (jb = jbmin; jb <= jbmax; jb++) {
            for (ib = 0; ib < 3; ib++) {
              bij = b[(3 * (2 - jb) - ib) + 2];
              bijNotZero = (bij != 0.0);
              if (bijNotZero) {
                if (ib < 1) {
                  ic0 = 2;
                  imin = ma - 1;
                } else {
                  ic0 = 1;
                  imin = (ma - ib) + 1;
                }
                imax = ((ic0 + ib) + ((jb + j) - 1) * ma) - 1;
                if (imin >= 1) {
                  n_t = (ptrdiff_t)imin;
                  incx_t = (ptrdiff_t)1;
                  incy_t = (ptrdiff_t)1;
                  daxpy(&n_t, &bij, (real_T *)&a_data[imax - 1], &incx_t,
                        &cj_data[ic0 - 1], &incy_t);
                }
              } else {
                if (ib < 1) {
                  imin = 2;
                  imax = ma;
                } else {
                  imin = 1;
                  imax = (ma - ib) + 1;
                }
                for (ic0 = imin; ic0 <= imax; ic0++) {
                  cj_data[ic0 - 1] +=
                      bij *
                      a_data[((ic0 + ib) + a->size[0] * ((j + jb) - 1)) - 2];
                }
              }
            }
          }
          for (imax = 0; imax < ma; imax++) {
            c_data[imax + c->size[0] * j] = cj_data[imax];
          }
        } else {
          emlrtHadParallelError = true;
        }
      }
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
}

/* End of code generation (conv2AXPYSameCMP.c) */
