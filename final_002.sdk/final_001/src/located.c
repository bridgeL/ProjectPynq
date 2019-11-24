/*
 * File: located.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "fft.h"
#include "exp.h"
#include "cosd.h"
#include "sind.h"
#include "relop.h"
#include "mod.h"
#include "located_emxutil.h"
#include "fliplr.h"
#include "sort1.h"
#include "diag.h"
#include "eig.h"
#include "mean.h"
#include "located_rtwutil.h"

/* Function Definitions */

/*
 * 注意，得到的信号可能没有去掉直流分量
 *
 * estphi 为仰角，est_thi为方向角
 * 1为初始角度0
 * Arguments    : double sig[49152]
 *                emxArray_real_T *show_angle
 * Return Type  : void
 */
void located(double sig[49152], emxArray_real_T *show_angle)
{
  double meansig[6];
  int i;
  int i0;
  static double b_sig[8192];
  static creal_T dcv0[16384];
  static creal_T x_fft[98304];
  creal_T b_x_fft[36];
  creal_T V1[36];
  creal_T EV[36];
  creal_T a3[6];
  int iidx[6];
  double re;
  double im;
  int i1;
  double b_re;
  double x2;
  creal_T Un1[30];
  static creal_T pp2[32400];
  int jj;
  int ixstart;
  double ksi;
  creal_T peak;
  creal_T maxval[360];
  int idx;
  int nn;
  boolean_T exitg1;
  emxArray_int32_T *ii;
  boolean_T x[32400];
  emxArray_int32_T *b_jj;
  creal_T b_a3[6];
  double b_im;
  boolean_T guard1 = false;
  emxArray_int32_T *a;
  emxArray_int32_T *b;
  double x1;
  double w;

  /* 波长 */
  /* 波数 */
  /* 阵列半径 */
  /* 信号个数 */
  /* 阵元数目 */
  /* 阵元夹角 */
  /* 去直流偏置 ,由于C语言不能如此直接操作，故此 */
  /* 行取均值 */
  mean(sig, meansig);
  for (i = 0; i < 6; i++) {
     for (i0 = 0; i0 < 8192; i0++) {
       sig[i + 6 * i0] -= meansig[i];
       b_sig[i0] = sig[i + 6 * i0];
     }
  /* 直流偏置已经去掉 */
  /*   FFT */
  /*  fft six channel */
    fft(b_sig, dcv0);
    for (i0 = 0; i0 < 16384; i0++) {
      x_fft[i + 6 * i0] = dcv0[i0];
    }
  }

  /*  */
  /* music第一步，求协方差矩阵 */
  /* 有噪声的协方差矩阵 */
  /*  music第二步，特征值分解，获得噪声子空间 */
  for (i0 = 0; i0 < 6; i0++) {
    for (i = 0; i < 6; i++) {
      re = 0.0;
      im = 0.0;
      for (i1 = 0; i1 < 8192; i1++) {
        b_re = x_fft[i + 6 * i1].re;
        x2 = -x_fft[i + 6 * i1].im;
        re += x_fft[i0 + 6 * i1].re * b_re - x_fft[i0 + 6 * i1].im * x2;
        im += x_fft[i0 + 6 * i1].re * x2 + x_fft[i0 + 6 * i1].im * b_re;
      }

      if (im == 0.0) {
        b_x_fft[i0 + 6 * i].re = re / 8192.0;
        b_x_fft[i0 + 6 * i].im = 0.0;
      } else if (re == 0.0) {
        b_x_fft[i0 + 6 * i].re = 0.0;
        b_x_fft[i0 + 6 * i].im = im / 8192.0;
      } else {
        b_x_fft[i0 + 6 * i].re = re / 8192.0;
        b_x_fft[i0 + 6 * i].im = im / 8192.0;
      }
    }
  }

  eig(b_x_fft, V1, EV);
  diag(EV, a3);
  sort(a3, iidx);
  for (i0 = 0; i0 < 6; i0++) {
    for (i = 0; i < 6; i++) {
      EV[i + 6 * i0] = V1[i + 6 * (iidx[i0] - 1)];
    }
  }

  fliplr(EV);
  for (i0 = 0; i0 < 6; i0++) {
    for (i = 0; i < 6; i++) {
      b_x_fft[i + 6 * i0] = V1[i + 6 * (iidx[i0] - 1)];
    }
  }

  fliplr(b_x_fft);
  for (i0 = 0; i0 < 5; i0++) {
    memcpy(&Un1[i0 * 6], &b_x_fft[i0 * 6 + 6], 6U * sizeof(creal_T));
  }

  /*  music第三步，谱峰搜索 */
  /* 初始化 */
  memset(&pp2[0], 0, 32400U * sizeof(creal_T));

  /* 初始化结束 */
  /* 确定大概范围 */
  for (jj = 0; jj < 9; jj++) {
    ixstart = jj * 11;
    b_re = 1.0 + (((double)ixstart + 1.0) - 1.0);
    b_sind(&b_re);
    ksi = 3.1415926535897931 * b_re;

    /* sind(x),x为度数 */
    for (idx = 0; idx < 18; idx++) {
      nn = idx * 21;
      peak.re = ksi * 0.0;
      peak.im = ksi;
      for (i0 = 0; i0 < 6; i0++) {
        meansig[i0] = (nn - 60 * i0) + 1;
      }

      b_cosd(meansig);
      for (i = 0; i < 6; i++) {
        a3[i].re = meansig[i] * peak.re;
        a3[i].im = meansig[i] * peak.im;
      }

      b_exp(a3);
      for (i0 = 0; i0 < 6; i0++) {
        for (i = 0; i < 6; i++) {
          b_x_fft[i0 + 6 * i].re = 0.0;
          b_x_fft[i0 + 6 * i].im = 0.0;
          for (i1 = 0; i1 < 5; i1++) {
            x2 = Un1[i + 6 * i1].re;
            b_re = -Un1[i + 6 * i1].im;
            b_x_fft[i0 + 6 * i].re += EV[i0 + 6 * (1 + i1)].re * x2 - EV[i0 + 6 *
              (1 + i1)].im * b_re;
            b_x_fft[i0 + 6 * i].im += EV[i0 + 6 * (1 + i1)].re * b_re + EV[i0 +
              6 * (1 + i1)].im * x2;
          }
        }
      }

      re = 0.0;
      im = 0.0;
      for (i0 = 0; i0 < 6; i0++) {
        b_a3[i0].re = 0.0;
        b_a3[i0].im = 0.0;
        for (i = 0; i < 6; i++) {
          b_a3[i0].re += a3[i].re * b_x_fft[i + 6 * i0].re - -a3[i].im *
            b_x_fft[i + 6 * i0].im;
          b_a3[i0].im += a3[i].re * b_x_fft[i + 6 * i0].im + -a3[i].im *
            b_x_fft[i + 6 * i0].re;
        }

        re += b_a3[i0].re * a3[i0].re - b_a3[i0].im * a3[i0].im;
        im += b_a3[i0].re * a3[i0].im + b_a3[i0].im * a3[i0].re;
      }

      b_re = 0.0;
      b_im = 0.0;
      for (i0 = 0; i0 < 6; i0++) {
        b_re += a3[i0].re * a3[i0].re - -a3[i0].im * a3[i0].im;
        b_im += a3[i0].re * a3[i0].im + -a3[i0].im * a3[i0].re;
      }

      x2 = rt_hypotd_snf(re, im);
      if (b_im == 0.0) {
        pp2[ixstart + 90 * nn].re = b_re / x2;
        pp2[ixstart + 90 * nn].im = 0.0;
      } else if (b_re == 0.0) {
        pp2[ixstart + 90 * nn].re = 0.0;
        pp2[ixstart + 90 * nn].im = b_im / x2;
      } else {
        pp2[ixstart + 90 * nn].re = b_re / x2;
        pp2[ixstart + 90 * nn].im = b_im / x2;
      }
    }
  }

  /* 确定完大概范围 */
  /* 获得第一个峰值 */
  for (i = 0; i < 360; i++) {
    jj = i * 90 + 90;
    ixstart = i * 90;
    peak = pp2[jj - 90];
    if (rtIsNaN(pp2[ixstart].re) || rtIsNaN(pp2[ixstart].im)) {
      idx = ixstart + 1;
      exitg1 = false;
      while ((!exitg1) && (idx + 1 <= jj)) {
        ixstart = idx;
        if (!(rtIsNaN(pp2[idx].re) || rtIsNaN(pp2[idx].im))) {
          peak = pp2[idx];
          exitg1 = true;
        } else {
          idx++;
        }
      }
    }

    if (ixstart + 1 < jj) {
      for (idx = ixstart + 1; idx + 1 <= jj; idx++) {
        if (b_relop(pp2[idx], peak)) {
          peak = pp2[idx];
        }
      }
    }

    maxval[i] = peak;
  }

  ixstart = 1;
  peak = maxval[0];
  if (rtIsNaN(maxval[0].re) || rtIsNaN(maxval[0].im)) {
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj + 1 < 361)) {
      ixstart = jj + 1;
      if (!(rtIsNaN(maxval[jj].re) || rtIsNaN(maxval[jj].im))) {
        peak = maxval[jj];
        exitg1 = true;
      } else {
        jj++;
      }
    }
  }

  if (ixstart < 360) {
    while (ixstart + 1 < 361) {
      if (b_relop(maxval[ixstart], peak)) {
        peak = maxval[ixstart];
      }

      ixstart++;
    }
  }

  for (i0 = 0; i0 < 32400; i0++) {
    x[i0] = ((pp2[i0].re == peak.re) && (pp2[i0].im == peak.im));
  }

  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_jj, 1);
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = 32400;
  emxEnsureCapacity((emxArray__common *)ii, i0, sizeof(int));
  i0 = b_jj->size[0];
  b_jj->size[0] = 32400;
  emxEnsureCapacity((emxArray__common *)b_jj, i0, sizeof(int));
  ixstart = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 360)) {
    guard1 = false;
    if (x[(ixstart + 90 * (jj - 1)) - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      b_jj->data[idx - 1] = jj;
      if (idx >= 32400) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
      if (ixstart > 90) {
        ixstart = 1;
        jj++;
      }
    }
  }

  i0 = ii->size[0];
  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }

  emxEnsureCapacity((emxArray__common *)ii, i0, sizeof(int));
  emxInit_int32_T(&a, 1);
  i0 = b_jj->size[0];
  if (1 > idx) {
    b_jj->size[0] = 0;
  } else {
    b_jj->size[0] = idx;
  }

  emxEnsureCapacity((emxArray__common *)b_jj, i0, sizeof(int));
  i0 = a->size[0];
  a->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)a, i0, sizeof(int));
  ixstart = ii->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    a->data[i0] = ii->data[i0];
  }

  emxFree_int32_T(&ii);
  emxInit_int32_T(&b, 1);
  i0 = b->size[0];
  b->size[0] = b_jj->size[0];
  emxEnsureCapacity((emxArray__common *)b, i0, sizeof(int));
  ixstart = b_jj->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    b->data[i0] = b_jj->data[i0];
  }

  /*  确定位置 */
  /* 防溢出 */
  x1 = (double)b->data[0] - 11.0;
  if ((double)b->data[0] - 11.0 < 0.0) {
    x1 = 1.0;
  }

  x2 = (double)b->data[0] + 10.0;
  if ((double)b->data[0] + 10.0 > 359.0) {
    x2 = 360.0;
  }

  emxFree_int32_T(&b);

  /*  */
  b_re = 1.0 + ((double)a->data[0] - 1.0);
  b_sind(&b_re);
  ksi = 3.1415926535897931 * b_re;
  i0 = (int)(x2 + (1.0 - x1));
  for (ixstart = 0; ixstart < i0; ixstart++) {
    w = b_mod(x1 + (double)ixstart);
    peak.re = ksi * 0.0;
    peak.im = ksi;
    for (i = 0; i < 6; i++) {
      meansig[i] = (1.0 + (w - 1.0)) - 60.0 * (double)i;
    }

    b_cosd(meansig);
    for (i = 0; i < 6; i++) {
      a3[i].re = meansig[i] * peak.re;
      a3[i].im = meansig[i] * peak.im;
    }

    b_exp(a3);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        b_x_fft[i + 6 * i1].re = 0.0;
        b_x_fft[i + 6 * i1].im = 0.0;
        for (jj = 0; jj < 5; jj++) {
          x2 = Un1[i1 + 6 * jj].re;
          b_re = -Un1[i1 + 6 * jj].im;
          b_x_fft[i + 6 * i1].re += EV[i + 6 * (1 + jj)].re * x2 - EV[i + 6 * (1
            + jj)].im * b_re;
          b_x_fft[i + 6 * i1].im += EV[i + 6 * (1 + jj)].re * b_re + EV[i + 6 *
            (1 + jj)].im * x2;
        }
      }
    }

    re = 0.0;
    im = 0.0;
    for (i = 0; i < 6; i++) {
      b_a3[i].re = 0.0;
      b_a3[i].im = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_a3[i].re += a3[i1].re * b_x_fft[i1 + 6 * i].re - -a3[i1].im *
          b_x_fft[i1 + 6 * i].im;
        b_a3[i].im += a3[i1].re * b_x_fft[i1 + 6 * i].im + -a3[i1].im *
          b_x_fft[i1 + 6 * i].re;
      }

      re += b_a3[i].re * a3[i].re - b_a3[i].im * a3[i].im;
      im += b_a3[i].re * a3[i].im + b_a3[i].im * a3[i].re;
    }

    b_re = 0.0;
    b_im = 0.0;
    for (i = 0; i < 6; i++) {
      b_re += a3[i].re * a3[i].re - -a3[i].im * a3[i].im;
      b_im += a3[i].re * a3[i].im + -a3[i].im * a3[i].re;
    }

    x2 = rt_hypotd_snf(re, im);
    if (b_im == 0.0) {
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].re = b_re / x2;
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].im = 0.0;
    } else if (b_re == 0.0) {
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].re = 0.0;
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].im = b_im / x2;
    } else {
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].re = b_re / x2;
      pp2[(a->data[0] + 90 * ((int)w - 1)) - 1].im = b_im / x2;
    }
  }

  emxFree_int32_T(&a);
  for (i = 0; i < 360; i++) {
    jj = i * 90 + 90;
    ixstart = i * 90;
    peak = pp2[jj - 90];
    if (rtIsNaN(pp2[ixstart].re) || rtIsNaN(pp2[ixstart].im)) {
      idx = ixstart + 1;
      exitg1 = false;
      while ((!exitg1) && (idx + 1 <= jj)) {
        ixstart = idx;
        if (!(rtIsNaN(pp2[idx].re) || rtIsNaN(pp2[idx].im))) {
          peak = pp2[idx];
          exitg1 = true;
        } else {
          idx++;
        }
      }
    }

    if (ixstart + 1 < jj) {
      for (idx = ixstart + 1; idx + 1 <= jj; idx++) {
        if (b_relop(pp2[idx], peak)) {
          peak = pp2[idx];
        }
      }
    }

    maxval[i] = peak;
  }

  ixstart = 1;
  peak = maxval[0];
  if (rtIsNaN(maxval[0].re) || rtIsNaN(maxval[0].im)) {
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj + 1 < 361)) {
      ixstart = jj + 1;
      if (!(rtIsNaN(maxval[jj].re) || rtIsNaN(maxval[jj].im))) {
        peak = maxval[jj];
        exitg1 = true;
      } else {
        jj++;
      }
    }
  }

  if (ixstart < 360) {
    while (ixstart + 1 < 361) {
      if (b_relop(maxval[ixstart], peak)) {
        peak = maxval[ixstart];
      }

      ixstart++;
    }
  }

  /* 获得确切方位 */
  for (i0 = 0; i0 < 32400; i0++) {
    x[i0] = ((pp2[i0].re == peak.re) && (pp2[i0].im == peak.im));
  }

  idx = 0;
  i0 = b_jj->size[0];
  b_jj->size[0] = 32400;
  emxEnsureCapacity((emxArray__common *)b_jj, i0, sizeof(int));
  ixstart = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 360)) {
    guard1 = false;
    if (x[(ixstart + 90 * (jj - 1)) - 1]) {
      idx++;
      b_jj->data[idx - 1] = jj;
      if (idx >= 32400) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
      if (ixstart > 90) {
        ixstart = 1;
        jj++;
      }
    }
  }

  i0 = b_jj->size[0];
  if (1 > idx) {
    b_jj->size[0] = 0;
  } else {
    b_jj->size[0] = idx;
  }

  emxEnsureCapacity((emxArray__common *)b_jj, i0, sizeof(int));
  i0 = show_angle->size[0];
  show_angle->size[0] = b_jj->size[0];
  emxEnsureCapacity((emxArray__common *)show_angle, i0, sizeof(double));
  ixstart = b_jj->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    show_angle->data[i0] = b_jj->data[i0];
  }

  emxFree_int32_T(&b_jj);
}

/*
 * File trailer for located.c
 *
 * [EOF]
 */
