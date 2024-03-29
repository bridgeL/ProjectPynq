/*
 * File: xscal.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "xscal.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const creal_T a
 *                creal_T x[36]
 *                int ix0
 * Return Type  : void
 */
void b_xscal(int n, const creal_T a, creal_T x[36], int ix0)
{
  int i8;
  int k;
  double x_re;
  double x_im;
  i8 = ix0 + 6 * (n - 1);
  for (k = ix0; k <= i8; k += 6) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

/*
 * Arguments    : const creal_T a
 *                creal_T x[36]
 *                int ix0
 * Return Type  : void
 */
void c_xscal(const creal_T a, creal_T x[36], int ix0)
{
  int k;
  double x_re;
  double x_im;
  for (k = ix0; k <= ix0 + 5; k++) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

/*
 * Arguments    : int n
 *                const creal_T a
 *                creal_T x[36]
 *                int ix0
 * Return Type  : void
 */
void xscal(int n, const creal_T a, creal_T x[36], int ix0)
{
  int i4;
  int k;
  double x_re;
  double x_im;
  i4 = (ix0 + n) - 1;
  for (k = ix0; k <= i4; k++) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

/*
 * File trailer for xscal.c
 *
 * [EOF]
 */
