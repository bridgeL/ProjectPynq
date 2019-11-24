/*
 * File: anyNonFinite.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "anyNonFinite.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x[36]
 * Return Type  : boolean_T
 */
boolean_T anyNonFinite(const creal_T x[36])
{
  boolean_T p;
  int k;
  p = false;
  for (k = 0; k < 36; k++) {
    if (p || (rtIsInf(x[k].re) || rtIsInf(x[k].im)) || (rtIsNaN(x[k].re) ||
         rtIsNaN(x[k].im))) {
      p = true;
    } else {
      p = false;
    }
  }

  return p;
}

/*
 * File trailer for anyNonFinite.c
 *
 * [EOF]
 */
