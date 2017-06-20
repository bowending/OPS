//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_PdV_kernel_nopredict;
extern int xdim1_PdV_kernel_nopredict;
extern int xdim2_PdV_kernel_nopredict;
extern int xdim3_PdV_kernel_nopredict;
extern int xdim4_PdV_kernel_nopredict;
extern int xdim5_PdV_kernel_nopredict;
extern int xdim6_PdV_kernel_nopredict;
extern int xdim7_PdV_kernel_nopredict;
extern int xdim8_PdV_kernel_nopredict;
extern int xdim9_PdV_kernel_nopredict;
extern int xdim10_PdV_kernel_nopredict;
extern int xdim11_PdV_kernel_nopredict;
extern int xdim12_PdV_kernel_nopredict;
extern int xdim13_PdV_kernel_nopredict;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13

#define OPS_ACC0(x, y) (x + xdim0_PdV_kernel_nopredict * (y))
#define OPS_ACC1(x, y) (x + xdim1_PdV_kernel_nopredict * (y))
#define OPS_ACC2(x, y) (x + xdim2_PdV_kernel_nopredict * (y))
#define OPS_ACC3(x, y) (x + xdim3_PdV_kernel_nopredict * (y))
#define OPS_ACC4(x, y) (x + xdim4_PdV_kernel_nopredict * (y))
#define OPS_ACC5(x, y) (x + xdim5_PdV_kernel_nopredict * (y))
#define OPS_ACC6(x, y) (x + xdim6_PdV_kernel_nopredict * (y))
#define OPS_ACC7(x, y) (x + xdim7_PdV_kernel_nopredict * (y))
#define OPS_ACC8(x, y) (x + xdim8_PdV_kernel_nopredict * (y))
#define OPS_ACC9(x, y) (x + xdim9_PdV_kernel_nopredict * (y))
#define OPS_ACC10(x, y) (x + xdim10_PdV_kernel_nopredict * (y))
#define OPS_ACC11(x, y) (x + xdim11_PdV_kernel_nopredict * (y))
#define OPS_ACC12(x, y) (x + xdim12_PdV_kernel_nopredict * (y))
#define OPS_ACC13(x, y) (x + xdim13_PdV_kernel_nopredict * (y))

// user function

void PdV_kernel_nopredict_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, double *p_a7, int base7, int tot7,
    double *p_a8, int base8, int tot8, double *p_a9, int base9, int tot9,
    double *p_a10, int base10, int tot10, double *p_a11, int base11, int tot11,
    double *p_a12, int base12, int tot12, double *p_a13, int base13, int tot13,
    int x_size, int y_size) {
  int num_blocks = OPS_threads;
#pragma omp target enter data map(                                             \
    to : p_a0                                                                  \
    [0 : tot0],                                                                \
     p_a1[0 : tot1],                                                           \
          p_a2[0 : tot2],                                                      \
               p_a3[0 : tot3],                                                 \
                    p_a4[0 : tot4],                                            \
                         p_a5[0 : tot5],                                       \
                              p_a6[0 : tot6],                                  \
                                   p_a7[0 : tot7],                             \
                                        p_a8[0 : tot8],                        \
                                             p_a9[0 : tot9], p_a10             \
                                                  [0 : tot10],                 \
                                                   p_a11                       \
                                                   [0 : tot11],                \
                                                    p_a12                      \
                                                    [0 : tot12],               \
                                                     p_a13                     \
                                                     [0 : tot13],              \
                                                      states                   \
                                                      [0 : number_of_states])
#ifdef OPS_GPU

#pragma omp target teams num_teams(num_blocks)                                 \
    thread_limit(OPS_threads_for_block)
#pragma omp distribute parallel for simd schedule(static, 1)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
#ifdef OPS_GPU
#endif
    int n_x = i % x_size;
    int n_y = i / x_size;
    const double *xarea =
        p_a0 + base0 + n_x * 1 * 1 + n_y * xdim0_PdV_kernel_nopredict * 1 * 1;

    const double *xvel0 =
        p_a1 + base1 + n_x * 1 * 1 + n_y * xdim1_PdV_kernel_nopredict * 1 * 1;
    const double *xvel1 =
        p_a2 + base2 + n_x * 1 * 1 + n_y * xdim2_PdV_kernel_nopredict * 1 * 1;

    const double *yarea =
        p_a3 + base3 + n_x * 1 * 1 + n_y * xdim3_PdV_kernel_nopredict * 1 * 1;
    const double *yvel0 =
        p_a4 + base4 + n_x * 1 * 1 + n_y * xdim4_PdV_kernel_nopredict * 1 * 1;

    const double *yvel1 =
        p_a5 + base5 + n_x * 1 * 1 + n_y * xdim5_PdV_kernel_nopredict * 1 * 1;
    double *volume_change =
        p_a6 + base6 + n_x * 1 * 1 + n_y * xdim6_PdV_kernel_nopredict * 1 * 1;

    const double *volume =
        p_a7 + base7 + n_x * 1 * 1 + n_y * xdim7_PdV_kernel_nopredict * 1 * 1;
    const double *pressure =
        p_a8 + base8 + n_x * 1 * 1 + n_y * xdim8_PdV_kernel_nopredict * 1 * 1;

    const double *density0 =
        p_a9 + base9 + n_x * 1 * 1 + n_y * xdim9_PdV_kernel_nopredict * 1 * 1;
    double *density1 = p_a10 + base10 + n_x * 1 * 1 +
                       n_y * xdim10_PdV_kernel_nopredict * 1 * 1;

    const double *viscosity = p_a11 + base11 + n_x * 1 * 1 +
                              n_y * xdim11_PdV_kernel_nopredict * 1 * 1;
    const double *energy0 = p_a12 + base12 + n_x * 1 * 1 +
                            n_y * xdim12_PdV_kernel_nopredict * 1 * 1;

    double *energy1 = p_a13 + base13 + n_x * 1 * 1 +
                      n_y * xdim13_PdV_kernel_nopredict * 1 * 1;

    double recip_volume, energy_change;
    double right_flux, left_flux, top_flux, bottom_flux, total_flux;

    left_flux = (xarea[OPS_ACC0(0, 0)] *
                 (xvel0[OPS_ACC1(0, 0)] + xvel0[OPS_ACC1(0, 1)] +
                  xvel1[OPS_ACC2(0, 0)] + xvel1[OPS_ACC2(0, 1)])) *
                0.25 * dt;
    right_flux = (xarea[OPS_ACC0(1, 0)] *
                  (xvel0[OPS_ACC1(1, 0)] + xvel0[OPS_ACC1(1, 1)] +
                   xvel1[OPS_ACC2(1, 0)] + xvel1[OPS_ACC2(1, 1)])) *
                 0.25 * dt;

    bottom_flux = (yarea[OPS_ACC3(0, 0)] *
                   (yvel0[OPS_ACC4(0, 0)] + yvel0[OPS_ACC4(1, 0)] +
                    yvel1[OPS_ACC5(0, 0)] + yvel1[OPS_ACC5(1, 0)])) *
                  0.25 * dt;
    top_flux = (yarea[OPS_ACC3(0, 1)] *
                (yvel0[OPS_ACC4(0, 1)] + yvel0[OPS_ACC4(1, 1)] +
                 yvel1[OPS_ACC5(0, 1)] + yvel1[OPS_ACC5(1, 1)])) *
               0.25 * dt;

    total_flux = right_flux - left_flux + top_flux - bottom_flux;

    volume_change[OPS_ACC6(0, 0)] =
        (volume[OPS_ACC7(0, 0)]) / (volume[OPS_ACC7(0, 0)] + total_flux);

    recip_volume = 1.0 / volume[OPS_ACC7(0, 0)];

    energy_change = (pressure[OPS_ACC8(0, 0)] / density0[OPS_ACC9(0, 0)] +
                     viscosity[OPS_ACC11(0, 0)] / density0[OPS_ACC9(0, 0)]) *
                    total_flux * recip_volume;
    energy1[OPS_ACC13(0, 0)] = energy0[OPS_ACC12(0, 0)] - energy_change;
    density1[OPS_ACC10(0, 0)] =
        density0[OPS_ACC9(0, 0)] * volume_change[OPS_ACC6(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13
