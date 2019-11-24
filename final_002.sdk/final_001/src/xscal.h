/*
 * File: xscal.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

#ifndef XSCAL_H
#define XSCAL_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "located_types.h"

/* Function Declarations */
extern void b_xscal(int n, const creal_T a, creal_T x[36], int ix0);
extern void c_xscal(const creal_T a, creal_T x[36], int ix0);
extern void xscal(int n, const creal_T a, creal_T x[36], int ix0);

#endif

/*
 * File trailer for xscal.h
 *
 * [EOF]
 */
