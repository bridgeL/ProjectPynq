/*
 * File: mod.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_mod(double x)
{
  double r;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 360.0);
      if (r == 0.0) {
        r = 0.0;
      }
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
