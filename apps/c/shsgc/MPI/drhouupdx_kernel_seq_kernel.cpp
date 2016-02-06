//
// auto-generated by ops.py
//

//user function
inline void drhouupdx_kernel(const double *rhou_new, const double* rho_new, const double* rhoE_new, double *rhou_res) {

			double fni = rhou_new[OPS_ACC0(0)] * rhou_new[OPS_ACC0(0)] / rho_new[OPS_ACC1(0)] ;
			double p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * fni);
			fni = fni + p;
			double fnim1 = rhou_new[OPS_ACC0(-1)] * rhou_new[OPS_ACC0(-1)] / rho_new[OPS_ACC1(-1)];
			p = gam1 * (rhoE_new[OPS_ACC2(-1)] - 0.5 * fnim1);
			fnim1 = fnim1 + p;
			double fnim2 = rhou_new[OPS_ACC0(-2)] * rhou_new[OPS_ACC0(-2)] / rho_new[OPS_ACC1(-2)];
			p = gam1 * (rhoE_new[OPS_ACC2(-2)] - 0.5 * fnim2);
			fnim2 = fnim2 + p;
			double fnip1 = rhou_new[OPS_ACC0(1)] * rhou_new[OPS_ACC0(1)] / rho_new[OPS_ACC1(1)];
			p = gam1 * (rhoE_new[OPS_ACC2(1)] - 0.5 * fnip1);
			fnip1 = fnip1 + p;
			double fnip2 = rhou_new[OPS_ACC0(2)] * rhou_new[OPS_ACC0(2)] / rho_new[OPS_ACC1(2)];
			p = gam1 * (rhoE_new[OPS_ACC2(2)] - 0.5 * fnip2);
			fnip2 = fnip2 + p;

			double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
			rhou_res[OPS_ACC3(0)] = deriv;
}





// host stub function
void ops_par_loop_drhouupdx_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  //Timing
  double t1,t2,c1,c2;

  char *p_a[4];
  int  offs[4][1];
  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,4)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(4,"drhouupdx_kernel");
    OPS_kernels[4].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];

  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<1; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI
  #ifdef OPS_DEBUG
  ops_register_args(args, "drhouupdx_kernel");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension

  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension

  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension



  int off0_0 = offs[0][0];
  int dat0 = args[0].dat->elem_size;
  int off1_0 = offs[1][0];
  int dat1 = args[1].dat->elem_size;
  int off2_0 = offs[2][0];
  int dat2 = args[2].dat->elem_size;
  int off3_0 = offs[3][0];
  int dat3 = args[3].dat->elem_size;

  //set up initial pointers and exchange halos if necessary
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 *
    (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  p_a[0] = (char *)args[0].data + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 *
    (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  p_a[1] = (char *)args[1].data + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 *
    (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  p_a[2] = (char *)args[2].data + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = dat3 * 1 *
    (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  p_a[3] = (char *)args[3].data + base3;


  //initialize global variable with the dimension of dats

  //Halo Exchanges
  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args,4,range);
  ops_H_D_exchanges_host(args, 4);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[4].mpi_time += t1-t2;
  }

  int n_x;
  #pragma novector
  for( n_x=start[0]; n_x<start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x+=SIMD_VEC ) {
    //call kernel function, passing in pointers to data -vectorised
    #pragma simd
    for ( int i=0; i<SIMD_VEC; i++ ){
      drhouupdx_kernel(  (double *)p_a[0]+ i*1*1, (double *)p_a[1]+ i*1*1, (double *)p_a[2]+ i*1*1,
           (double *)p_a[3]+ i*1*1 );

    }

    //shift pointers to data x direction
    p_a[0]= p_a[0] + (dat0 * off0_0)*SIMD_VEC;
    p_a[1]= p_a[1] + (dat1 * off1_0)*SIMD_VEC;
    p_a[2]= p_a[2] + (dat2 * off2_0)*SIMD_VEC;
    p_a[3]= p_a[3] + (dat3 * off3_0)*SIMD_VEC;
  }

  for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
    //call kernel function, passing in pointers to data - remainder
    drhouupdx_kernel(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3] );


    //shift pointers to data x direction
    p_a[0]= p_a[0] + (dat0 * off0_0);
    p_a[1]= p_a[1] + (dat1 * off1_0);
    p_a[2]= p_a[2] + (dat2 * off2_0);
    p_a[3]= p_a[3] + (dat3 * off3_0);
  }

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[4].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[3],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[4].mpi_time += t1-t2;
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
