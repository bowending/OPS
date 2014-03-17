//
// auto-generated by ops.py on 2014-03-17 14:10
//

#ifdef _OPENMP
#include <omp.h>
#endif
//user function
#include "PdV_kernel.h"

// host stub function
void ops_par_loop_PdV_kernel_predict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11) {

  int  offs[12][2];
  ops_arg args[12] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;

  int start[ndim];
  int end[ndim];

  for ( int n=0; n<ndim; n++ ){
    start[n] = sb->istart[n];end[n] = sb->iend[n]+1;
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      end[n] = sb->sizes[n];
    }
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "PdV_kernel_predict");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension
  offs[0][1] = off2D(1, &start[0],
  &end[0],args[0].dat->block_size, args[0].stencil->stride);

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension
  offs[1][1] = off2D(1, &start[0],
  &end[0],args[1].dat->block_size, args[1].stencil->stride);

  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension
  offs[2][1] = off2D(1, &start[0],
  &end[0],args[2].dat->block_size, args[2].stencil->stride);

  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension
  offs[3][1] = off2D(1, &start[0],
  &end[0],args[3].dat->block_size, args[3].stencil->stride);

  offs[4][0] = args[4].stencil->stride[0]*1;  //unit step in x dimension
  offs[4][1] = off2D(1, &start[0],
  &end[0],args[4].dat->block_size, args[4].stencil->stride);

  offs[5][0] = args[5].stencil->stride[0]*1;  //unit step in x dimension
  offs[5][1] = off2D(1, &start[0],
  &end[0],args[5].dat->block_size, args[5].stencil->stride);

  offs[6][0] = args[6].stencil->stride[0]*1;  //unit step in x dimension
  offs[6][1] = off2D(1, &start[0],
  &end[0],args[6].dat->block_size, args[6].stencil->stride);

  offs[7][0] = args[7].stencil->stride[0]*1;  //unit step in x dimension
  offs[7][1] = off2D(1, &start[0],
  &end[0],args[7].dat->block_size, args[7].stencil->stride);

  offs[8][0] = args[8].stencil->stride[0]*1;  //unit step in x dimension
  offs[8][1] = off2D(1, &start[0],
  &end[0],args[8].dat->block_size, args[8].stencil->stride);

  offs[9][0] = args[9].stencil->stride[0]*1;  //unit step in x dimension
  offs[9][1] = off2D(1, &start[0],
  &end[0],args[9].dat->block_size, args[9].stencil->stride);

  offs[10][0] = args[10].stencil->stride[0]*1;  //unit step in x dimension
  offs[10][1] = off2D(1, &start[0],
  &end[0],args[10].dat->block_size, args[10].stencil->stride);

  offs[11][0] = args[11].stencil->stride[0]*1;  //unit step in x dimension
  offs[11][1] = off2D(1, &start[0],
  &end[0],args[11].dat->block_size, args[11].stencil->stride);



  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_1 = offs[2][0];
  int off2_2 = offs[2][1];
  int dat2 = args[2].dat->size;
  int off3_1 = offs[3][0];
  int off3_2 = offs[3][1];
  int dat3 = args[3].dat->size;
  int off4_1 = offs[4][0];
  int off4_2 = offs[4][1];
  int dat4 = args[4].dat->size;
  int off5_1 = offs[5][0];
  int off5_2 = offs[5][1];
  int dat5 = args[5].dat->size;
  int off6_1 = offs[6][0];
  int off6_2 = offs[6][1];
  int dat6 = args[6].dat->size;
  int off7_1 = offs[7][0];
  int off7_2 = offs[7][1];
  int dat7 = args[7].dat->size;
  int off8_1 = offs[8][0];
  int off8_2 = offs[8][1];
  int dat8 = args[8].dat->size;
  int off9_1 = offs[9][0];
  int off9_2 = offs[9][1];
  int dat9 = args[9].dat->size;
  int off10_1 = offs[10][0];
  int off10_2 = offs[10][1];
  int dat10 = args[10].dat->size;
  int off11_1 = offs[11][0];
  int off11_2 = offs[11][1];
  int dat11 = args[11].dat->size;


  #ifdef _OPENMP
  int nthreads = omp_get_max_threads( );
  #else
  int nthreads = 1;
  #endif
  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];
  xdim4 = args[4].dat->block_size[0];
  xdim5 = args[5].dat->block_size[0];
  xdim6 = args[6].dat->block_size[0];
  xdim7 = args[7].dat->block_size[0];
  xdim8 = args[8].dat->block_size[0];
  xdim9 = args[9].dat->block_size[0];
  xdim10 = args[10].dat->block_size[0];
  xdim11 = args[11].dat->block_size[0];

  //Halo Exchanges
  ops_exchange_halo(&args[0],2);
  ops_exchange_halo(&args[1],2);
  ops_exchange_halo(&args[2],2);
  ops_exchange_halo(&args[3],2);
  ops_exchange_halo(&args[5],2);
  ops_exchange_halo(&args[6],2);
  ops_exchange_halo(&args[7],2);
  ops_exchange_halo(&args[9],2);
  ops_exchange_halo(&args[10],2);

  ops_H_D_exchanges(args, 12);


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(5,"PdV_kernel_predict");
  ops_timers_core(&c1,&t1);


  #pragma omp parallel for
  for ( int thr=0; thr<nthreads; thr++ ){

    //start index for each dimension
    int start0;
    int start1;

    int y_size = end[1]-start[1];
    char *p_a[12];

    int start_i = start[1] + ((y_size-1)/nthreads+1)*thr;
    int finish_i = start[1] + MIN(((y_size-1)/nthreads+1)*(thr+1),y_size);

    //get addresss per thread
    start0 = start[0];
    start1 = start[1] + ((y_size-1)/nthreads+1)*thr;

    //set up initial pointers 
    int base0 = dat0 * 1 * 
    (start0 * args[0].stencil->stride[0] - args[0].dat->offset[0]);
    base0 = base0  + dat0 * args[0].dat->block_size[0] * 
    (start1 * args[0].stencil->stride[1] - args[0].dat->offset[1]);
    p_a[0] = (char *)args[0].data + base0;

    //set up initial pointers 
    int base1 = dat1 * 1 * 
    (start0 * args[1].stencil->stride[0] - args[1].dat->offset[0]);
    base1 = base1  + dat1 * args[1].dat->block_size[0] * 
    (start1 * args[1].stencil->stride[1] - args[1].dat->offset[1]);
    p_a[1] = (char *)args[1].data + base1;

    //set up initial pointers 
    int base2 = dat2 * 1 * 
    (start0 * args[2].stencil->stride[0] - args[2].dat->offset[0]);
    base2 = base2  + dat2 * args[2].dat->block_size[0] * 
    (start1 * args[2].stencil->stride[1] - args[2].dat->offset[1]);
    p_a[2] = (char *)args[2].data + base2;

    //set up initial pointers 
    int base3 = dat3 * 1 * 
    (start0 * args[3].stencil->stride[0] - args[3].dat->offset[0]);
    base3 = base3  + dat3 * args[3].dat->block_size[0] * 
    (start1 * args[3].stencil->stride[1] - args[3].dat->offset[1]);
    p_a[3] = (char *)args[3].data + base3;

    //set up initial pointers 
    int base4 = dat4 * 1 * 
    (start0 * args[4].stencil->stride[0] - args[4].dat->offset[0]);
    base4 = base4  + dat4 * args[4].dat->block_size[0] * 
    (start1 * args[4].stencil->stride[1] - args[4].dat->offset[1]);
    p_a[4] = (char *)args[4].data + base4;

    //set up initial pointers 
    int base5 = dat5 * 1 * 
    (start0 * args[5].stencil->stride[0] - args[5].dat->offset[0]);
    base5 = base5  + dat5 * args[5].dat->block_size[0] * 
    (start1 * args[5].stencil->stride[1] - args[5].dat->offset[1]);
    p_a[5] = (char *)args[5].data + base5;

    //set up initial pointers 
    int base6 = dat6 * 1 * 
    (start0 * args[6].stencil->stride[0] - args[6].dat->offset[0]);
    base6 = base6  + dat6 * args[6].dat->block_size[0] * 
    (start1 * args[6].stencil->stride[1] - args[6].dat->offset[1]);
    p_a[6] = (char *)args[6].data + base6;

    //set up initial pointers 
    int base7 = dat7 * 1 * 
    (start0 * args[7].stencil->stride[0] - args[7].dat->offset[0]);
    base7 = base7  + dat7 * args[7].dat->block_size[0] * 
    (start1 * args[7].stencil->stride[1] - args[7].dat->offset[1]);
    p_a[7] = (char *)args[7].data + base7;

    //set up initial pointers 
    int base8 = dat8 * 1 * 
    (start0 * args[8].stencil->stride[0] - args[8].dat->offset[0]);
    base8 = base8  + dat8 * args[8].dat->block_size[0] * 
    (start1 * args[8].stencil->stride[1] - args[8].dat->offset[1]);
    p_a[8] = (char *)args[8].data + base8;

    //set up initial pointers 
    int base9 = dat9 * 1 * 
    (start0 * args[9].stencil->stride[0] - args[9].dat->offset[0]);
    base9 = base9  + dat9 * args[9].dat->block_size[0] * 
    (start1 * args[9].stencil->stride[1] - args[9].dat->offset[1]);
    p_a[9] = (char *)args[9].data + base9;

    //set up initial pointers 
    int base10 = dat10 * 1 * 
    (start0 * args[10].stencil->stride[0] - args[10].dat->offset[0]);
    base10 = base10  + dat10 * args[10].dat->block_size[0] * 
    (start1 * args[10].stencil->stride[1] - args[10].dat->offset[1]);
    p_a[10] = (char *)args[10].data + base10;

    //set up initial pointers 
    int base11 = dat11 * 1 * 
    (start0 * args[11].stencil->stride[0] - args[11].dat->offset[0]);
    base11 = base11  + dat11 * args[11].dat->block_size[0] * 
    (start1 * args[11].stencil->stride[1] - args[11].dat->offset[1]);
    p_a[11] = (char *)args[11].data + base11;


    for ( int n_y=start_i; n_y<finish_i; n_y++ ){
      for ( int n_x=start[0]; n_x<start[0]+(end[0]-start[0])/SIMD_VEC; n_x++ ){
        //call kernel function, passing in pointers to data -vectorised
        #pragma simd
        for ( int i=0; i<SIMD_VEC; i++ ){
          PdV_kernel_predict(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (double *)p_a[2]+ i*1,
           (double *)p_a[3]+ i*1, (double *)p_a[4]+ i*1, (double *)p_a[5]+ i*1, (double *)p_a[6]+ i*1,
           (double *)p_a[7]+ i*1, (double *)p_a[8]+ i*1, (double *)p_a[9]+ i*1, (double *)p_a[10]+ i*1,
           (double *)p_a[11]+ i*1 );

        }

        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1)*SIMD_VEC;
        p_a[1]= p_a[1] + (dat1 * off1_1)*SIMD_VEC;
        p_a[2]= p_a[2] + (dat2 * off2_1)*SIMD_VEC;
        p_a[3]= p_a[3] + (dat3 * off3_1)*SIMD_VEC;
        p_a[4]= p_a[4] + (dat4 * off4_1)*SIMD_VEC;
        p_a[5]= p_a[5] + (dat5 * off5_1)*SIMD_VEC;
        p_a[6]= p_a[6] + (dat6 * off6_1)*SIMD_VEC;
        p_a[7]= p_a[7] + (dat7 * off7_1)*SIMD_VEC;
        p_a[8]= p_a[8] + (dat8 * off8_1)*SIMD_VEC;
        p_a[9]= p_a[9] + (dat9 * off9_1)*SIMD_VEC;
        p_a[10]= p_a[10] + (dat10 * off10_1)*SIMD_VEC;
        p_a[11]= p_a[11] + (dat11 * off11_1)*SIMD_VEC;
      }

      for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        PdV_kernel_predict(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4], (double *)p_a[5], (double *)p_a[6],
           (double *)p_a[7], (double *)p_a[8], (double *)p_a[9], (double *)p_a[10],
           (double *)p_a[11] );


        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1);
        p_a[1]= p_a[1] + (dat1 * off1_1);
        p_a[2]= p_a[2] + (dat2 * off2_1);
        p_a[3]= p_a[3] + (dat3 * off3_1);
        p_a[4]= p_a[4] + (dat4 * off4_1);
        p_a[5]= p_a[5] + (dat5 * off5_1);
        p_a[6]= p_a[6] + (dat6 * off6_1);
        p_a[7]= p_a[7] + (dat7 * off7_1);
        p_a[8]= p_a[8] + (dat8 * off8_1);
        p_a[9]= p_a[9] + (dat9 * off9_1);
        p_a[10]= p_a[10] + (dat10 * off10_1);
        p_a[11]= p_a[11] + (dat11 * off11_1);
      }

      //shift pointers to data y direction
      p_a[0]= p_a[0] + (dat0 * off0_2);
      p_a[1]= p_a[1] + (dat1 * off1_2);
      p_a[2]= p_a[2] + (dat2 * off2_2);
      p_a[3]= p_a[3] + (dat3 * off3_2);
      p_a[4]= p_a[4] + (dat4 * off4_2);
      p_a[5]= p_a[5] + (dat5 * off5_2);
      p_a[6]= p_a[6] + (dat6 * off6_2);
      p_a[7]= p_a[7] + (dat7 * off7_2);
      p_a[8]= p_a[8] + (dat8 * off8_2);
      p_a[9]= p_a[9] + (dat9 * off9_2);
      p_a[10]= p_a[10] + (dat10 * off10_2);
      p_a[11]= p_a[11] + (dat11 * off11_2);
    }
  }
  ops_set_dirtybit_host(args, 12);

  ops_set_halo_dirtybit(&args[4]);
  ops_set_halo_dirtybit(&args[8]);
  ops_set_halo_dirtybit(&args[11]);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[5].count++;
  OPS_kernels[5].time += t2-t1;
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg10);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg11);
}
