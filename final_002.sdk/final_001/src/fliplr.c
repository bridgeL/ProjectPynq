/*
 * File: fliplr.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "fliplr.h"

/* Function Definitions */

/*
 * Arguments    : creal_T x[36]
 * Return Type  : void
 */
void fliplr(creal_T x[36])
{
  int b_j1;
  int i;
  double xtmp_re;
  double xtmp_im;
  for (b_j1 = 0; b_j1 < 3; b_j1++) {
    for (i = 0; i < 6; i++) {
      xtmp_re = x[i + 6 * b_j1].re;
      xtmp_im = x[i + 6 * b_j1].im;
      x[i + 6 * b_j1] = x[i + 6 * (5 - b_j1)];
      x[i + 6 * (5 - b_j1)].re = xtmp_re;
      x[i + 6 * (5 - b_j1)].im = xtmp_im;
    }
  }
}

/*
 * File trailer for fliplr.c
 *
 * [EOF]
 */
