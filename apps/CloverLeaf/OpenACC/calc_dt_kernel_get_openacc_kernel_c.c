//
// auto-generated by ops.py on 2014-06-18 22:54
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_calc_dt_kernel_get;
int xdim1_calc_dt_kernel_get;

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel_get*(y))
#define OPS_ACC1(x,y) (x+xdim1_calc_dt_kernel_get*(y))

//user function
inline 
void calc_dt_kernel_get(const double* cellx, const double* celly, double* xl_pos, double* yl_pos) {
  *xl_pos = cellx[OPS_ACC0(0,0)];
  *yl_pos = celly[OPS_ACC1(0,0)];
}



#undef OPS_ACC0
#undef OPS_ACC1


void calc_dt_kernel_get_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size) {
  double p_a2_l[1];
  for (int d = 0; d < 1; d++) p_a2_l[d] = p_a2[d];
  double p_a3_l[1];
  for (int d = 0; d < 1; d++) p_a3_l[d] = p_a3[d];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1) reduction(+:p_a2_l) reduction(+:p_a3_l)
  #pragma acc loop reduction(+:p_a2_l) reduction(+:p_a3_l)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a2_l) reduction(+:p_a3_l)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      calc_dt_kernel_get(  p_a0 + n_x*1 + n_y*xdim0_calc_dt_kernel_get*0,
           p_a1 + n_x*0 + n_y*xdim1_calc_dt_kernel_get*1, &p_a2_l,
           &p_a3_l );

    }
  }
  for (int d = 0; d < 1; d++) p_a2[d] = p_a2_l[d];
  for (int d = 0; d < 1; d++) p_a3[d] = p_a3_l[d];
}
