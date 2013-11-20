//
// auto-generated by ops.py on 2013-11-20 12:20
//

__constant__ int xdim0_initialise_chunk_kernel_x;
__constant__ int xdim1_initialise_chunk_kernel_x;
__constant__ int xdim2_initialise_chunk_kernel_x;

#define OPS_ACC0(x,y) (x+xdim0_initialise_chunk_kernel_x*(y))
#define OPS_ACC1(x,y) (x+xdim1_initialise_chunk_kernel_x*(y))
#define OPS_ACC2(x,y) (x+xdim2_initialise_chunk_kernel_x*(y))

//user function
__device__

inline void initialise_chunk_kernel_x(double *vertexx, const int *xx, double *vertexdx) {

  int x_min=field->x_min;
  int x_max=field->x_max;
  int y_min=field->y_min;
  int y_max=field->y_max;

  double min_x, min_y, d_x, d_y;

  d_x = (grid->xmax - grid->xmin)/(double)grid->x_cells;
  d_y = (grid->ymax - grid->ymin)/(double)grid->y_cells;

  min_x=grid->xmin+d_x*field->left;
  min_y=grid->ymin+d_y*field->bottom;

  vertexx[OPS_ACC0(0,0)] = min_x + d_x * (xx[OPS_ACC1(0,0)] - x_min);
  vertexdx[OPS_ACC2(0,0)] = (double)d_x;
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


__global__ void ops_initialise_chunk_kernel_x(
double* __restrict arg0,
const int* __restrict arg1,
double* __restrict arg2,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_initialise_chunk_kernel_x;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_initialise_chunk_kernel_x;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_initialise_chunk_kernel_x;

  if (idx_x < size0 && idx_y < size1) {
    initialise_chunk_kernel_x(arg0, arg1, arg2);
  }

}

// host stub function
void ops_par_loop_initialise_chunk_kernel_x(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  ops_arg args[3] = { arg0, arg1, arg2};


  int x_size = range[1]-range[0];
  int y_size = range[3]-range[2];

  int xdim0 = args[0].dat->block_size[0];
  int xdim1 = args[1].dat->block_size[0];
  int xdim2 = args[2].dat->block_size[0];

  ops_timing_realloc(82);
  if (OPS_kernels[82].count == 0) {
    cudaMemcpyToSymbol( xdim0_initialise_chunk_kernel_x, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_initialise_chunk_kernel_x, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_initialise_chunk_kernel_x, &xdim2, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);




  char *p_a[3];


  //set up initial pointers
  p_a[0] = &args[0].data_d[
  + args[0].dat->size * args[0].dat->block_size[0] * ( range[2] * 1 - args[0].dat->offset[1] )
  + args[0].dat->size * ( range[0] * 1 - args[0].dat->offset[0] ) ];

  p_a[1] = &args[1].data_d[
  + args[1].dat->size * args[1].dat->block_size[0] * ( range[2] * 1 - args[1].dat->offset[1] )
  + args[1].dat->size * ( range[0] * 1 - args[1].dat->offset[0] ) ];

  p_a[2] = &args[2].data_d[
  + args[2].dat->size * args[2].dat->block_size[0] * ( range[2] * 1 - args[2].dat->offset[1] )
  + args[2].dat->size * ( range[0] * 1 - args[2].dat->offset[0] ) ];


  ops_halo_exchanges_cuda(args, 3);


  //call kernel wrapper function, passing in pointers to data
  ops_initialise_chunk_kernel_x<<<grid, block >>> (  (double *)p_a[0], (int *)p_a[1],
           (double *)p_a[2],x_size, y_size);

  ops_set_dirtybit_cuda(args, 3);
  OPS_kernels[82].count++;
}
