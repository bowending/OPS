//
<<<<<<< HEAD
// auto-generated by ops.py on 2014-06-17 17:28
=======
// auto-generated by ops.py on 2014-06-05 13:43
>>>>>>> 56d4657... Testing all other backends
//

__constant__ int xdim0_initialise_chunk_kernel_y;
__constant__ int xdim1_initialise_chunk_kernel_y;
__constant__ int xdim2_initialise_chunk_kernel_y;

#define OPS_ACC0(x,y) (x+xdim0_initialise_chunk_kernel_y*(y))
#define OPS_ACC1(x,y) (x+xdim1_initialise_chunk_kernel_y*(y))
#define OPS_ACC2(x,y) (x+xdim2_initialise_chunk_kernel_y*(y))

//user function
__device__

void initialise_chunk_kernel_y(double *vertexy, const int *yy, double *vertexdy) {

  int x_min=field.x_min-2;
  int x_max=field.x_max-2;
  int y_min=field.y_min-2;
  int y_max=field.y_max-2;

  double min_x, min_y, d_x, d_y;

  d_x = (grid.xmax - grid.xmin)/(double)grid.x_cells;
  d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;

  min_x=grid.xmin+d_x*field.left;
  min_y=grid.ymin+d_y*field.bottom;

  vertexy[OPS_ACC0(0,0)] = min_y + d_y * (yy[OPS_ACC1(0,0)] - y_min);
  vertexdy[OPS_ACC2(0,0)] = (double)d_y;
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


__global__ void ops_initialise_chunk_kernel_y(
double* __restrict arg0,
const int* __restrict arg1,
double* __restrict arg2,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 0 + idx_y * 1 * xdim0_initialise_chunk_kernel_y;
  arg1 += idx_x * 0 + idx_y * 1 * xdim1_initialise_chunk_kernel_y;
  arg2 += idx_x * 0 + idx_y * 1 * xdim2_initialise_chunk_kernel_y;

  if (idx_x < size0 && idx_y < size1) {
    initialise_chunk_kernel_y(arg0, arg1, arg2);
  }

}

// host stub function
void ops_par_loop_initialise_chunk_kernel_y(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  ops_arg args[3] = { arg0, arg1, arg2};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int start_add[2];
  int end_add[2];
  for ( int n=0; n<2; n++ ){
    start_add[n] = sb->istart[n];end_add[n] = sb->iend[n]+1;
    if (start_add[n] >= range[2*n]) {
      start_add[n] = 0;
    }
    else {
      start_add[n] = range[2*n] - start_add[n];
    }
    if (end_add[n] >= range[2*n+1]) {
      end_add[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      end_add[n] = sb->sizes[n];
    }
  }


  int x_size = MAX(0,end_add[0]-start_add[0]);
  int y_size = MAX(0,end_add[1]-start_add[1]);

  int xdim0 = args[0].dat->block_size[0]*args[0].dat->dim;
  int xdim1 = args[1].dat->block_size[0]*args[1].dat->dim;
  int xdim2 = args[2].dat->block_size[0]*args[2].dat->dim;


  //Timing
  double t1,t2,c1,c2;
<<<<<<< HEAD
  ops_timing_realloc(76,"initialise_chunk_kernel_y");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[76].count == 0) {
=======
  ops_timing_realloc(75,"initialise_chunk_kernel_y");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[75].count == 0) {
>>>>>>> 56d4657... Testing all other backends
    cudaMemcpyToSymbol( xdim0_initialise_chunk_kernel_y, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_initialise_chunk_kernel_y, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_initialise_chunk_kernel_y, &xdim2, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;

  char *p_a[3];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0+ dat0 *
    args[0].dat->block_size[0] *
    (start_add[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = dat1 * 1 * 
  (start_add[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1+ dat1 *
    args[1].dat->block_size[0] *
    (start_add[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = dat2 * 1 * 
  (start_add[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2+ dat2 *
    args[2].dat->block_size[0] *
    (start_add[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data_d + base2;


  ops_H_D_exchanges_cuda(args, 3);
  ops_halo_exchanges(args,3,range);

  ops_timers_core(&c1,&t1);
<<<<<<< HEAD
  OPS_kernels[76].mpi_time += t1-t2;
=======
  OPS_kernels[75].mpi_time += t1-t2;
>>>>>>> 56d4657... Testing all other backends


  //call kernel wrapper function, passing in pointers to data
  ops_initialise_chunk_kernel_y<<<grid, block >>> (  (double *)p_a[0], (int *)p_a[1],
           (double *)p_a[2],x_size, y_size);

  if (OPS_diags>1) cutilSafeCall(cudaDeviceSynchronize());
  ops_timers_core(&c2,&t2);
<<<<<<< HEAD
  OPS_kernels[76].time += t2-t1;
=======
  OPS_kernels[75].time += t2-t1;
>>>>>>> 56d4657... Testing all other backends
  ops_set_dirtybit_cuda(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[2],range);

  //Update kernel record
<<<<<<< HEAD
  OPS_kernels[76].count++;
  OPS_kernels[76].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[76].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[76].transfer += ops_compute_transfer(dim, range, &arg2);
=======
  OPS_kernels[75].count++;
  OPS_kernels[75].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[75].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[75].transfer += ops_compute_transfer(dim, range, &arg2);
>>>>>>> 56d4657... Testing all other backends
}
