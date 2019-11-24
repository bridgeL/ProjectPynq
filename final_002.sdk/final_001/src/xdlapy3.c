/*
 * File: xdlapy3.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "xdlapy3.h"

/* Function Definitions */

/*
 * Arguments    : double x1
 *                double x2
 *                double x3
 * Return Type  : double
 */
double xdlapy3(double x1, double x2, double x3)
{
  double y;
  double a;
  double b;
  double c;
  a = fabs(x1);
  b = fabs(x2);
  c = fabs(x3);
  if ((a > b) || rtIsNaN(b)) {
    y = a;
  } else {
    y = b;
  }

  if (c > y) {
    y = c;
  }

  if ((y > 0.0) && (!rtIsInf(y))) {
    a /= y;
    b /= y;
    c /= y;
    y *= sqrt((a * a + c * c) + b * b);
  } else {
    y = (a + b) + c;
  }

  return y;
}

/*
 * File trailer for xdlapy3.c
 *
 * [EOF]
 */
