//
// auto-generated by ops.py on 2014-05-28 15:13
//

#include "user_types.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif

#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5

#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;

#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel_min*(y))


//user function

void calc_dt_kernel_min( __global double* dt_min ,
                                  double* dt_min_val,
                                  int xdim0_calc_dt_kernel_min)

  {
  *dt_min_val = MIN(*dt_min_val, dt_min[OPS_ACC0(0,0)]);

}



 #undef OPS_ACC0


 __kernel void ops_calc_dt_kernel_min(
 __global double* arg0,
 __global double* arg1,
 int xdim0_calc_dt_kernel_min,
 const int base0,
 int size0,
 int size1,
 __local double *scratch ){
   
   double arg1_l[1];
   
   for (int d=0; d<1; d++)
       arg1_l[d] = INFINITY_double;

   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     calc_dt_kernel_min(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_calc_dt_kernel_min],
                    arg1_l,                    
                    xdim0_calc_dt_kernel_min);
   }
   reduce_double(arg1_l[0], scratch, arg1, OPS_MIN);
 }
