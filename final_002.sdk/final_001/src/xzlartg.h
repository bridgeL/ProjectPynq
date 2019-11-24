/*
 * File: xzlartg.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Nov-2018 20:16:57
 */

#ifndef XZLARTG_H
#define XZLARTG_H

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
extern void b_xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn);
extern void xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn,
                    creal_T *r);

#endif

/*
 * File trailer for xzlartg.h
 *
 * [EOF]
 */
