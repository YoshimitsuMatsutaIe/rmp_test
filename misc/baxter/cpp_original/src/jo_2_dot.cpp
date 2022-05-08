/******************************************************************************
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                 This file is part of 'jo_2_dot_BY_SYMPY_'                  *
 ******************************************************************************/
#include "jo_2_dot.h"
#include <math.h>

void jo_2_dot(double L1, double L2, double *dq, double *q, double *out_8748855269084948005) {

   out_8748855269084948005[0] = -1.0/2.0*M_SQRT2*L1*sin(q[0])*dq[0] + (1.0/2.0)*M_SQRT2*L1*cos(q[0])*dq[0] - 1.0/2.0*M_SQRT2*L2*sin(q[0])*sin(q[1])*dq[1] - 1.0/2.0*M_SQRT2*L2*sin(q[0])*cos(q[1])*dq[0] - 1.0/2.0*M_SQRT2*L2*sin(q[1])*cos(q[0])*dq[1] + (1.0/2.0)*M_SQRT2*L2*cos(q[0])*cos(q[1])*dq[0];
   out_8748855269084948005[1] = -1.0/2.0*M_SQRT2*L2*sin(q[0])*sin(q[1])*dq[0] - 1.0/2.0*M_SQRT2*L2*sin(q[0])*cos(q[1])*dq[1] - 1.0/2.0*M_SQRT2*L2*sin(q[1])*cos(q[0])*dq[0] + (1.0/2.0)*M_SQRT2*L2*cos(q[0])*cos(q[1])*dq[1];
   out_8748855269084948005[2] = 0;
   out_8748855269084948005[3] = 0;
   out_8748855269084948005[4] = 0;
   out_8748855269084948005[5] = 0;
   out_8748855269084948005[6] = 0;
   out_8748855269084948005[7] = (1.0/2.0)*M_SQRT2*L1*sin(q[0])*dq[0] + (1.0/2.0)*M_SQRT2*L1*cos(q[0])*dq[0] - 1.0/2.0*M_SQRT2*L2*sin(q[0])*sin(q[1])*dq[1] + (1.0/2.0)*M_SQRT2*L2*sin(q[0])*cos(q[1])*dq[0] + (1.0/2.0)*M_SQRT2*L2*sin(q[1])*cos(q[0])*dq[1] + (1.0/2.0)*M_SQRT2*L2*cos(q[0])*cos(q[1])*dq[0];
   out_8748855269084948005[8] = -1.0/2.0*M_SQRT2*L2*sin(q[0])*sin(q[1])*dq[0] + (1.0/2.0)*M_SQRT2*L2*sin(q[0])*cos(q[1])*dq[1] + (1.0/2.0)*M_SQRT2*L2*sin(q[1])*cos(q[0])*dq[0] + (1.0/2.0)*M_SQRT2*L2*cos(q[0])*cos(q[1])*dq[1];
   out_8748855269084948005[9] = 0;
   out_8748855269084948005[10] = 0;
   out_8748855269084948005[11] = 0;
   out_8748855269084948005[12] = 0;
   out_8748855269084948005[13] = 0;
   out_8748855269084948005[14] = 0;
   out_8748855269084948005[15] = L2*sin(q[1])*dq[1];
   out_8748855269084948005[16] = 0;
   out_8748855269084948005[17] = 0;
   out_8748855269084948005[18] = 0;
   out_8748855269084948005[19] = 0;
   out_8748855269084948005[20] = 0;

}
