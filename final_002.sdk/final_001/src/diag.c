/*
 * File: diag.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "located.h"
#include "diag.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T v[36]
 *                creal_T d[6]
 * Return Type  : void
 */
void diag(const creal_T v[36], creal_T d[6])
{
  int j;
  for (j = 0; j < 6; j++) {
    d[j] = v[j * 7];
  }
}

/*
 * File trailer for diag.c
 *
 * [EOF]
 */
