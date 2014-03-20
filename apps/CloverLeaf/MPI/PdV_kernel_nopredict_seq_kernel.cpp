//
// auto-generated by ops.py on 2014-03-20 16:20
//

//user function
#include "PdV_kernel.h"

// host stub function
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {

  char *p_a[14];
  int  offs[14][2];
  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int* start = (int *)xmalloc(sizeof(int)*2);
  int* end = (int *)xmalloc(sizeof(int)*2);
  for ( int n=0; n<2; n++ ){
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
  ops_register_args(args, "PdV_kernel_nopredict");
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

  offs[12][0] = args[12].stencil->stride[0]*1;  //unit step in x dimension
  offs[12][1] = off2D(1, &start[0],
  &end[0],args[12].dat->block_size, args[12].stencil->stride);

  offs[13][0] = args[13].stencil->stride[0]*1;  //unit step in x dimension
  offs[13][1] = off2D(1, &start[0],
  &end[0],args[13].dat->block_size, args[13].stencil->stride);



  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(46,"PdV_kernel_nopredict");
  ops_timers_core(&c2,&t2);

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
  int off12_1 = offs[12][0];
  int off12_2 = offs[12][1];
  int dat12 = args[12].dat->size;
  int off13_1 = offs[13][0];
  int off13_2 = offs[13][1];
  int dat13 = args[13].dat->size;

  int max0[2]; int min0[2];
  for ( int n=0; n<2; n++ ){
    max0[n] = 0;min0[n] = 0;
  }
  for ( int p=0; p<args[0].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max0[n] = MAX(max0[n],args[0].stencil->stencil[2*p + n]);
      min0[n] = MIN(min0[n],args[0].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base0 = dat0 * 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;
  ops_exchange_halo2(&args[0],max0,min0);

  int max1[2]; int min1[2];
  for ( int n=0; n<2; n++ ){
    max1[n] = 0;min1[n] = 0;
  }
  for ( int p=0; p<args[1].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max1[n] = MAX(max1[n],args[1].stencil->stencil[2*p + n]);
      min1[n] = MIN(min1[n],args[1].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base1 = dat1 * 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;
  ops_exchange_halo2(&args[1],max1,min1);

  int max2[2]; int min2[2];
  for ( int n=0; n<2; n++ ){
    max2[n] = 0;min2[n] = 0;
  }
  for ( int p=0; p<args[2].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max2[n] = MAX(max2[n],args[2].stencil->stencil[2*p + n]);
      min2[n] = MIN(min2[n],args[2].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base2 = dat2 * 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data + base2;
  ops_exchange_halo2(&args[2],max2,min2);

  int max3[2]; int min3[2];
  for ( int n=0; n<2; n++ ){
    max3[n] = 0;min3[n] = 0;
  }
  for ( int p=0; p<args[3].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max3[n] = MAX(max3[n],args[3].stencil->stencil[2*p + n]);
      min3[n] = MIN(min3[n],args[3].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base3 = dat3 * 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start[1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  p_a[3] = (char *)args[3].data + base3;
  ops_exchange_halo2(&args[3],max3,min3);

  int max4[2]; int min4[2];
  for ( int n=0; n<2; n++ ){
    max4[n] = 0;min4[n] = 0;
  }
  for ( int p=0; p<args[4].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max4[n] = MAX(max4[n],args[4].stencil->stencil[2*p + n]);
      min4[n] = MIN(min4[n],args[4].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base4 = dat4 * 1 * 
  (start[0] * args[4].stencil->stride[0] - args[4].dat->offset[0]);
  base4 = base4  + dat4 * args[4].dat->block_size[0] * 
  (start[1] * args[4].stencil->stride[1] - args[4].dat->offset[1]);
  p_a[4] = (char *)args[4].data + base4;
  ops_exchange_halo2(&args[4],max4,min4);

  int max5[2]; int min5[2];
  for ( int n=0; n<2; n++ ){
    max5[n] = 0;min5[n] = 0;
  }
  for ( int p=0; p<args[5].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max5[n] = MAX(max5[n],args[5].stencil->stencil[2*p + n]);
      min5[n] = MIN(min5[n],args[5].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base5 = dat5 * 1 * 
  (start[0] * args[5].stencil->stride[0] - args[5].dat->offset[0]);
  base5 = base5  + dat5 * args[5].dat->block_size[0] * 
  (start[1] * args[5].stencil->stride[1] - args[5].dat->offset[1]);
  p_a[5] = (char *)args[5].data + base5;
  ops_exchange_halo2(&args[5],max5,min5);

  int max6[2]; int min6[2];
  for ( int n=0; n<2; n++ ){
    max6[n] = 0;min6[n] = 0;
  }
  for ( int p=0; p<args[6].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max6[n] = MAX(max6[n],args[6].stencil->stencil[2*p + n]);
      min6[n] = MIN(min6[n],args[6].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base6 = dat6 * 1 * 
  (start[0] * args[6].stencil->stride[0] - args[6].dat->offset[0]);
  base6 = base6  + dat6 * args[6].dat->block_size[0] * 
  (start[1] * args[6].stencil->stride[1] - args[6].dat->offset[1]);
  p_a[6] = (char *)args[6].data + base6;

  int max7[2]; int min7[2];
  for ( int n=0; n<2; n++ ){
    max7[n] = 0;min7[n] = 0;
  }
  for ( int p=0; p<args[7].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max7[n] = MAX(max7[n],args[7].stencil->stencil[2*p + n]);
      min7[n] = MIN(min7[n],args[7].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base7 = dat7 * 1 * 
  (start[0] * args[7].stencil->stride[0] - args[7].dat->offset[0]);
  base7 = base7  + dat7 * args[7].dat->block_size[0] * 
  (start[1] * args[7].stencil->stride[1] - args[7].dat->offset[1]);
  p_a[7] = (char *)args[7].data + base7;
  ops_exchange_halo2(&args[7],max7,min7);

  int max8[2]; int min8[2];
  for ( int n=0; n<2; n++ ){
    max8[n] = 0;min8[n] = 0;
  }
  for ( int p=0; p<args[8].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max8[n] = MAX(max8[n],args[8].stencil->stencil[2*p + n]);
      min8[n] = MIN(min8[n],args[8].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base8 = dat8 * 1 * 
  (start[0] * args[8].stencil->stride[0] - args[8].dat->offset[0]);
  base8 = base8  + dat8 * args[8].dat->block_size[0] * 
  (start[1] * args[8].stencil->stride[1] - args[8].dat->offset[1]);
  p_a[8] = (char *)args[8].data + base8;
  ops_exchange_halo2(&args[8],max8,min8);

  int max9[2]; int min9[2];
  for ( int n=0; n<2; n++ ){
    max9[n] = 0;min9[n] = 0;
  }
  for ( int p=0; p<args[9].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max9[n] = MAX(max9[n],args[9].stencil->stencil[2*p + n]);
      min9[n] = MIN(min9[n],args[9].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base9 = dat9 * 1 * 
  (start[0] * args[9].stencil->stride[0] - args[9].dat->offset[0]);
  base9 = base9  + dat9 * args[9].dat->block_size[0] * 
  (start[1] * args[9].stencil->stride[1] - args[9].dat->offset[1]);
  p_a[9] = (char *)args[9].data + base9;
  ops_exchange_halo2(&args[9],max9,min9);

  int max10[2]; int min10[2];
  for ( int n=0; n<2; n++ ){
    max10[n] = 0;min10[n] = 0;
  }
  for ( int p=0; p<args[10].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max10[n] = MAX(max10[n],args[10].stencil->stencil[2*p + n]);
      min10[n] = MIN(min10[n],args[10].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base10 = dat10 * 1 * 
  (start[0] * args[10].stencil->stride[0] - args[10].dat->offset[0]);
  base10 = base10  + dat10 * args[10].dat->block_size[0] * 
  (start[1] * args[10].stencil->stride[1] - args[10].dat->offset[1]);
  p_a[10] = (char *)args[10].data + base10;

  int max11[2]; int min11[2];
  for ( int n=0; n<2; n++ ){
    max11[n] = 0;min11[n] = 0;
  }
  for ( int p=0; p<args[11].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max11[n] = MAX(max11[n],args[11].stencil->stencil[2*p + n]);
      min11[n] = MIN(min11[n],args[11].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base11 = dat11 * 1 * 
  (start[0] * args[11].stencil->stride[0] - args[11].dat->offset[0]);
  base11 = base11  + dat11 * args[11].dat->block_size[0] * 
  (start[1] * args[11].stencil->stride[1] - args[11].dat->offset[1]);
  p_a[11] = (char *)args[11].data + base11;
  ops_exchange_halo2(&args[11],max11,min11);

  int max12[2]; int min12[2];
  for ( int n=0; n<2; n++ ){
    max12[n] = 0;min12[n] = 0;
  }
  for ( int p=0; p<args[12].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max12[n] = MAX(max12[n],args[12].stencil->stencil[2*p + n]);
      min12[n] = MIN(min12[n],args[12].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base12 = dat12 * 1 * 
  (start[0] * args[12].stencil->stride[0] - args[12].dat->offset[0]);
  base12 = base12  + dat12 * args[12].dat->block_size[0] * 
  (start[1] * args[12].stencil->stride[1] - args[12].dat->offset[1]);
  p_a[12] = (char *)args[12].data + base12;
  ops_exchange_halo2(&args[12],max12,min12);

  int max13[2]; int min13[2];
  for ( int n=0; n<2; n++ ){
    max13[n] = 0;min13[n] = 0;
  }
  for ( int p=0; p<args[13].stencil->points; p++ ){
    for ( int n=0; n<2; n++ ){
      max13[n] = MAX(max13[n],args[13].stencil->stencil[2*p + n]);
      min13[n] = MIN(min13[n],args[13].stencil->stencil[2*p + n]);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base13 = dat13 * 1 * 
  (start[0] * args[13].stencil->stride[0] - args[13].dat->offset[0]);
  base13 = base13  + dat13 * args[13].dat->block_size[0] * 
  (start[1] * args[13].stencil->stride[1] - args[13].dat->offset[1]);
  p_a[13] = (char *)args[13].data + base13;



  ops_timers_core(&c1,&t1);
  OPS_kernels[46].mpi_time += t1-t2;

  xdim0 = args[0].dat->block_size[0]*args[0].dat->dim;
  xdim1 = args[1].dat->block_size[0]*args[1].dat->dim;
  xdim2 = args[2].dat->block_size[0]*args[2].dat->dim;
  xdim3 = args[3].dat->block_size[0]*args[3].dat->dim;
  xdim4 = args[4].dat->block_size[0]*args[4].dat->dim;
  xdim5 = args[5].dat->block_size[0]*args[5].dat->dim;
  xdim6 = args[6].dat->block_size[0]*args[6].dat->dim;
  xdim7 = args[7].dat->block_size[0]*args[7].dat->dim;
  xdim8 = args[8].dat->block_size[0]*args[8].dat->dim;
  xdim9 = args[9].dat->block_size[0]*args[9].dat->dim;
  xdim10 = args[10].dat->block_size[0]*args[10].dat->dim;
  xdim11 = args[11].dat->block_size[0]*args[11].dat->dim;
  xdim12 = args[12].dat->block_size[0]*args[12].dat->dim;
  xdim13 = args[13].dat->block_size[0]*args[13].dat->dim;

  int n_x;
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    for( n_x=start[0]; n_x<start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x+=SIMD_VEC ) {
      //call kernel function, passing in pointers to data -vectorised
      #pragma simd
      for ( int i=0; i<SIMD_VEC; i++ ){
        PdV_kernel_nopredict(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (double *)p_a[2]+ i*1,
           (double *)p_a[3]+ i*1, (double *)p_a[4]+ i*1, (double *)p_a[5]+ i*1, (double *)p_a[6]+ i*1,
           (double *)p_a[7]+ i*1, (double *)p_a[8]+ i*1, (double *)p_a[9]+ i*1, (double *)p_a[10]+ i*1,
           (double *)p_a[11]+ i*1, (double *)p_a[12]+ i*1, (double *)p_a[13]+ i*1 );

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
      p_a[12]= p_a[12] + (dat12 * off12_1)*SIMD_VEC;
      p_a[13]= p_a[13] + (dat13 * off13_1)*SIMD_VEC;
    }

    for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        PdV_kernel_nopredict(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4], (double *)p_a[5], (double *)p_a[6],
           (double *)p_a[7], (double *)p_a[8], (double *)p_a[9], (double *)p_a[10],
           (double *)p_a[11], (double *)p_a[12], (double *)p_a[13] );


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
        p_a[12]= p_a[12] + (dat12 * off12_1);
        p_a[13]= p_a[13] + (dat13 * off13_1);
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
      p_a[12]= p_a[12] + (dat12 * off12_2);
      p_a[13]= p_a[13] + (dat13 * off13_2);
    }
    ops_timers_core(&c2,&t2);
    OPS_kernels[46].time += t2-t1;
    ops_set_halo_dirtybit(&args[6]);
    ops_set_halo_dirtybit(&args[10]);
    ops_set_halo_dirtybit(&args[13]);
    free(start);free(end);

    //Update kernel record
    OPS_kernels[46].count++;
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg0);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg1);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg2);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg3);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg4);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg5);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg6);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg7);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg8);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg9);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg10);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg11);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg12);
    OPS_kernels[46].transfer += ops_compute_transfer(dim, range, &arg13);
  }
