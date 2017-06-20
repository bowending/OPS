//
// auto-generated by ops.py
//
#include "./OpenMP4/advec_mom_kernel_y2_openmp4_kernel_c.c"
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_mom_kernel_y2;
int xdim0_advec_mom_kernel_y2_h = -1;
int xdim1_advec_mom_kernel_y2;
int xdim1_advec_mom_kernel_y2_h = -1;
int xdim2_advec_mom_kernel_y2;
int xdim2_advec_mom_kernel_y2_h = -1;
int xdim3_advec_mom_kernel_y2;
int xdim3_advec_mom_kernel_y2_h = -1;

void ops_par_loop_advec_mom_kernel_y2(char const *name, ops_block block,
                                      int dim, int *range, ops_arg arg0,
                                      ops_arg arg1, ops_arg arg2,
                                      ops_arg arg3) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[4] = {arg0, arg1, arg2, arg3};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 4, range, 18))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(18, "advec_mom_kernel_y2");
    OPS_kernels[18].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute localy allocated range for the sub-block

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

  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];
  if (xdim0 != xdim0_advec_mom_kernel_y2_h ||
      xdim1 != xdim1_advec_mom_kernel_y2_h ||
      xdim2 != xdim2_advec_mom_kernel_y2_h ||
      xdim3 != xdim3_advec_mom_kernel_y2_h) {
    xdim0_advec_mom_kernel_y2 = xdim0;
    xdim0_advec_mom_kernel_y2_h = xdim0;
    xdim1_advec_mom_kernel_y2 = xdim1;
    xdim1_advec_mom_kernel_y2_h = xdim1;
    xdim2_advec_mom_kernel_y2 = xdim2;
    xdim2_advec_mom_kernel_y2_h = xdim2;
    xdim3_advec_mom_kernel_y2 = xdim3;
    xdim3_advec_mom_kernel_y2_h = xdim3;
  }

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              args[0].dat->elem_size * start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          args[0].dat->elem_size * args[0].dat->size[0] * start[1] *
              args[0].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data);
#else
  double *p_a0 = (double *)((char *)args[0].data + base0);
#endif

  int base1 = args[1].dat->base_offset +
              args[1].dat->elem_size * start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          args[1].dat->elem_size * args[1].dat->size[0] * start[1] *
              args[1].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data);
#else
  double *p_a1 = (double *)((char *)args[1].data + base1);
#endif

  int base2 = args[2].dat->base_offset +
              args[2].dat->elem_size * start[0] * args[2].stencil->stride[0];
  base2 = base2 +
          args[2].dat->elem_size * args[2].dat->size[0] * start[1] *
              args[2].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data);
#else
  double *p_a2 = (double *)((char *)args[2].data + base2);
#endif

  int base3 = args[3].dat->base_offset +
              args[3].dat->elem_size * start[0] * args[3].stencil->stride[0];
  base3 = base3 +
          args[3].dat->elem_size * args[3].dat->size[0] * start[1] *
              args[3].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data);
#else
  double *p_a3 = (double *)((char *)args[3].data + base3);
#endif

  int tot0 = 1;
  for (int i = 0; i < args[0].dat->block->dims; i++)
    tot0 = tot0 * args[0].dat->size[i];
  int tot1 = 1;
  for (int i = 0; i < args[1].dat->block->dims; i++)
    tot1 = tot1 * args[1].dat->size[i];
  int tot2 = 1;
  for (int i = 0; i < args[2].dat->block->dims; i++)
    tot2 = tot2 * args[2].dat->size[i];
  int tot3 = 1;
  for (int i = 0; i < args[3].dat->block->dims; i++)
    tot3 = tot3 * args[3].dat->size[i];

#ifdef OPS_GPU
  for (int n = 0; n < 4; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[3].dat->block->dims; i++)
        size += size * args[3].dat->size[i];
      //#pragma omp target update to( args[n].dat->data[0:size])
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 4);
#else
  for (int n = 0; n < 4; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[3].dat->block->dims; i++)
        size += size * args[3].dat->size[i];
      //#pragma omp target update from(args[n].dat->data[0:size])
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 4);
#endif
  ops_halo_exchanges(args, 4, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[18].mpi_time += t2 - t1;
  }

  advec_mom_kernel_y2_c_wrapper(p_a0, base0 / args[0].dat->elem_size, tot0,
                                p_a1, base1 / args[1].dat->elem_size, tot1,
                                p_a2, base2 / args[2].dat->elem_size, tot2,
                                p_a3, base3 / args[3].dat->elem_size, tot3,
                                x_size, y_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[18].time += t1 - t2;
  }
#ifdef OPS_GPU
  for (int n = 0; n < 4; n++) {
    if ((args[n].argtype == OPS_ARG_DAT) &&
        (args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
         args[n].acc == OPS_RW)) {
      args[n].dat->dirty_hd = 2;
    }
  }
// ops_set_dirtybit_device(args, 4);
#else
  for (int n = 0; n < 4; n++) {
    if ((args[n].argtype == OPS_ARG_DAT) &&
        (args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
         args[n].acc == OPS_RW)) {
      args[n].dat->dirty_hd = 1;
    }
  }
// ops_set_dirtybit_host(args, 4);
#endif
  ops_set_halo_dirtybit3(&args[0], range);
  ops_set_halo_dirtybit3(&args[1], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[18].mpi_time += t2 - t1;
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
