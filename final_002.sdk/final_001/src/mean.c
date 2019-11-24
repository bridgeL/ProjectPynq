/*
 * File: mean.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "mean.h"

/* Function Definitions */

/*
 * Arguments    : const double x[49152]
 *                double y[6]
 * Return Type  : void
 */
void mean(const double x[49152], double y[6])
{
  int j;
  double s;
  int k;
  for (j = 0; j < 6; j++) {
    s = x[j];
    for (k = 0; k < 8191; k++) {
      s += x[j + (k + 1) * 6];
    }

    y[j] = s / 8192.0;
  }
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
