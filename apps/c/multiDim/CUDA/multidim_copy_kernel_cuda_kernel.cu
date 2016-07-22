//
// auto-generated by ops.py
//
__constant__ int xdim0_multidim_copy_kernel;
int xdim0_multidim_copy_kernel_h = -1;
int ydim0_multidim_copy_kernel_h = -1;
__constant__ int xdim1_multidim_copy_kernel;
int xdim1_multidim_copy_kernel_h = -1;
int ydim1_multidim_copy_kernel_h = -1;

#undef OPS_ACC_MD0
#undef OPS_ACC_MD1

#define OPS_ACC_MD0(d, x, y)                                                   \
  ((x)*2 + (d) + (xdim0_multidim_copy_kernel * (y)*2))
#define OPS_ACC_MD1(d, x, y)                                                   \
  ((x)*2 + (d) + (xdim1_multidim_copy_kernel * (y)*2))
// user function
__device__

    void
    multidim_copy_kernel(const double *src, double *dest) {
  dest[OPS_ACC_MD1(0, 0, 0)] = src[OPS_ACC_MD0(0, 0, 0)];
  dest[OPS_ACC_MD1(1, 0, 0)] = src[OPS_ACC_MD0(1, 0, 0)];
}

#undef OPS_ACC_MD0
#undef OPS_ACC_MD1

__global__ void ops_multidim_copy_kernel(const double *__restrict arg0,
                                         double *__restrict arg1, int size0,
                                         int size1) {

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 2 + idx_y * 1 * 2 * xdim0_multidim_copy_kernel;
  arg1 += idx_x * 1 * 2 + idx_y * 1 * 2 * xdim1_multidim_copy_kernel;

  if (idx_x < size0 && idx_y < size1) {
    multidim_copy_kernel(arg0, arg1);
  }
}

// host stub function
void ops_par_loop_multidim_copy_kernel(char const *name, ops_block block,
                                       int dim, int *range, ops_arg arg0,
                                       ops_arg arg1) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[2] = {arg0, arg1};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 2, range, 1))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(1, "multidim_copy_kernel");
    OPS_kernels[1].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];

  if (xdim0 != xdim0_multidim_copy_kernel_h ||
      xdim1 != xdim1_multidim_copy_kernel_h) {
    cudaMemcpyToSymbol(xdim0_multidim_copy_kernel, &xdim0, sizeof(int));
    xdim0_multidim_copy_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_multidim_copy_kernel, &xdim1, sizeof(int));
    xdim1_multidim_copy_kernel_h = xdim1;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;

  char *p_a[2];

  // set up initial pointers
  int d_m[OPS_MAX_DIM];
#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[0].dat->d_m[d];
#endif
  int base0 = dat0 * 1 * (start[0] * args[0].stencil->stride[0] -
                          args[0].dat->base[0] - d_m[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1] -
                                         args[0].dat->base[1] - d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[1].dat->d_m[d];
#endif
  int base1 = dat1 * 1 * (start[0] * args[1].stencil->stride[0] -
                          args[1].dat->base[0] - d_m[0]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * (start[1] * args[1].stencil->stride[1] -
                                         args[1].dat->base[1] - d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args, 2, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[1].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  ops_multidim_copy_kernel<<<grid, tblock>>>((double *)p_a[0], (double *)p_a[1],
                                             x_size, y_size);

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[1].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[1], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[1].mpi_time += t2 - t1;
    OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}
