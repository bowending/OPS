//
// auto-generated by ops.py//

// header
#define OPS_2D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// set max number of OMP threads for reductions
#ifndef MAX_REDUCT_THREADS
#define MAX_REDUCT_THREADS 64
#endif
// global constants
extern double dx;
extern double dy;

// user kernel files
#include "poisson_kernel_error_omp_kernel.cpp"
#include "poisson_kernel_initialguess_omp_kernel.cpp"
#include "poisson_kernel_populate_omp_kernel.cpp"
#include "poisson_kernel_stencil_omp_kernel.cpp"
#include "poisson_kernel_update_omp_kernel.cpp"
