/*
 * File: _coder_objectTracker_api.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 17-Jun-2015 12:18:42
 */

/* Include Files */
#include "_coder_objectTracker_api.h"

/* Function Declarations */
static int16_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *init, const
  char_T *identifier);
static int16_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *laneModel,
  const char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *lanePieceLength, const char_T *identifier);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier))[3];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Pk,
  const char_T *identifier))[9];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static void emlrt_marshallOut(const real_T u[3], const mxArray *y);
static void b_emlrt_marshallOut(const real_T u[9], const mxArray *y);
static int16_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxFree_real_T(emxArray_real_T **pEmxArray);

/* Function Definitions */

/*
 * Arguments    : emlrtContext *aContext
 * Return Type  : void
 */
void objectTracker_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void objectTracker_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void objectTracker_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  objectTracker_xil_terminate();
}

/*
 * Arguments    : const mxArray *prhs[10]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void objectTracker_api(const mxArray *prhs[10], const mxArray *plhs[2])
{
  emxArray_real_T *laneModel;
  emxArray_real_T *x_measure;
  emxArray_real_T *y_measure;
  int16_T init;
  real_T lanePieceLength;
  real_T (*r)[3];
  real_T (*Pk)[9];
  real_T Q;
  real_T R;
  real_T delta_x;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &laneModel, 1, true);
  emxInit_real_T(&st, &x_measure, 1, true);
  emxInit_real_T(&st, &y_measure, 1, true);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs[3] = emlrtProtectR2012b(prhs[3], 3, true, -1);
  prhs[4] = emlrtProtectR2012b(prhs[4], 4, true, -1);
  prhs[7] = emlrtProtectR2012b(prhs[7], 7, false, -1);
  prhs[8] = emlrtProtectR2012b(prhs[8], 8, false, -1);

  /* Marshall function inputs */
  init = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "init");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "laneModel", laneModel);
  lanePieceLength = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "lanePieceLength");
  r = g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "r");
  Pk = i_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "Pk");
  Q = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Q");
  R = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "R");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "x_measure", x_measure);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "y_measure", y_measure);
  delta_x = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "delta_x");

  /* Invoke the target function */
  objectTracker(init, laneModel, lanePieceLength, *r, *Pk, Q, R, x_measure,
                y_measure, delta_x);

  /* Marshall function outputs */
  emlrt_marshallOut(*r, prhs[3]);
  plhs[0] = prhs[3];
  b_emlrt_marshallOut(*Pk, prhs[4]);
  plhs[1] = prhs[4];
  y_measure->canFreeData = false;
  emxFree_real_T(&y_measure);
  x_measure->canFreeData = false;
  emxFree_real_T(&x_measure);
  laneModel->canFreeData = false;
  emxFree_real_T(&laneModel);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *init
 *                const char_T *identifier
 * Return Type  : int16_T
 */
static int16_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *init, const
  char_T *identifier)
{
  int16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(init), &thisId);
  emlrtDestroyArray(&init);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int16_T
 */
static int16_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *laneModel
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *laneModel,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(laneModel), &thisId, y);
  emlrtDestroyArray(&laneModel);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *lanePieceLength
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *lanePieceLength, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(lanePieceLength), &thisId);
  emlrtDestroyArray(&lanePieceLength);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *r
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(r), &thisId);
  emlrtDestroyArray(&r);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Pk
 *                const char_T *identifier
 * Return Type  : real_T (*)[9]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Pk,
  const char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = j_emlrt_marshallIn(sp, emlrtAlias(Pk), &thisId);
  emlrtDestroyArray(&Pk);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[9]
 */
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 *                const mxArray *y
 * Return Type  : void
 */
static void emlrt_marshallOut(const real_T u[3], const mxArray *y)
{
  static const int32_T iv0[1] = { 3 };

  mxSetData((mxArray *)y, (void *)u);
  emlrtSetDimensions((mxArray *)y, iv0, 1);
}

/*
 * Arguments    : const real_T u[9]
 *                const mxArray *y
 * Return Type  : void
 */
static void b_emlrt_marshallOut(const real_T u[9], const mxArray *y)
{
  static const int32_T iv1[2] = { 3, 3 };

  mxSetData((mxArray *)y, (void *)u);
  emlrtSetDimensions((mxArray *)y, iv1, 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int16_T
 */
static int16_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 0U, 0);
  ret = *(int16_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv2[1];
  boolean_T bv0[1];
  int32_T iv3[1];
  iv2[0] = -1;
  bv0[0] = true;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv2, bv0, iv3);
  ret->size[0] = iv3[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  int32_T iv4[1];
  iv4[0] = 3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv4);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[9]
 */
  static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  int32_T iv5[2];
  int32_T i;
  for (i = 0; i < 2; i++) {
    iv5[i] = 3;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv5);
  ret = (real_T (*)[9])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * File trailer for _coder_objectTracker_api.c
 *
 * [EOF]
 */
