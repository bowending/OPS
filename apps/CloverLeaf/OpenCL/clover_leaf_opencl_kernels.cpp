//
// auto-generated by op2.py on 2014-05-28 15:13
//

//header
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_cpp.h"
#include "ops_opencl_rt_support.h"
#include "user_types.h"
//global constants
extern double g_small;
extern double g_big;
extern double dtc_safe;
extern double dtu_safe;
extern double dtv_safe;
extern double dtdiv_safe;
extern field_type field;
extern grid_type grid;
extern state_type *states;
extern int number_of_states;
extern int g_circ;
extern int g_point;
extern int g_rect;
extern double dt;


  extern ops_opencl_core OPS_opencl_core;

  #define MAX_SOURCE_SIZE (32*0x1000000)
  
  void buildOpenCLKernels() {
    static bool isbuilt = false;
  
    if(!isbuilt) {
      clSafeCall( clUnloadCompiler() );
  
      OPS_opencl_core.n_kernels = 32;
      OPS_opencl_core.kernel = (cl_kernel*) malloc(32*sizeof(cl_kernel));  
      
      cl_int ret;
      char* source_filename[32] = {
          "./OpenCL/viscosity_kernel.cl",
          "./OpenCL/accelerate_kernel.cl",
          "./OpenCL/revert_kernel.cl",
          "./OpenCL/reset_field_kernel1.cl",
          "./OpenCL/reset_field_kernel2.cl",
          "./OpenCL/PdV_kernel_predict.cl",
          "./OpenCL/PdV_kernel_nopredict.cl",
          "./OpenCL/ideal_gas_kernel.cl",
          "./OpenCL/flux_calc_kernelx.cl",
          "./OpenCL/flux_calc_kernely.cl",
          "./OpenCL/advec_mom_kernel_x1.cl",
          "./OpenCL/advec_mom_kernel_y1.cl",
          "./OpenCL/advec_mom_kernel_x2.cl",
          "./OpenCL/advec_mom_kernel_y2.cl",
          "./OpenCL/advec_mom_kernel_mass_flux_x.cl",
          "./OpenCL/advec_mom_kernel_post_pre_advec_x.cl",
          "./OpenCL/advec_mom_kernel1_x_nonvector.cl",
          "./OpenCL/advec_mom_kernel2_x.cl",
          "./OpenCL/advec_mom_kernel_mass_flux_y.cl",
          "./OpenCL/advec_mom_kernel_post_pre_advec_y.cl",
          "./OpenCL/advec_mom_kernel1_y_nonvector.cl",
          "./OpenCL/advec_mom_kernel2_y.cl",
          "./OpenCL/advec_cell_kernel1_xdir.cl",
          "./OpenCL/advec_cell_kernel2_xdir.cl",
          "./OpenCL/advec_cell_kernel3_xdir.cl",
          "./OpenCL/advec_cell_kernel4_xdir.cl",
          "./OpenCL/advec_cell_kernel1_ydir.cl",
          "./OpenCL/advec_cell_kernel2_ydir.cl",
          "./OpenCL/advec_cell_kernel3_ydir.cl",
          "./OpenCL/advec_cell_kernel4_ydir.cl",
          "./OpenCL/calc_dt_kernel.cl",
          "./OpenCL/calc_dt_kernel_min.cl"
          //"./OpenCL/calc_dt_kernel_get.cl"
          //"./OpenCL/calc_dt_kernel_print.cl"
      };
  
      // Load the kernel source code into the array source_str
      FILE *fid;
      char *source_str[32];
      size_t source_size[32];
  
      for(int i=0; i<32; i++) {
        fid = fopen(source_filename[i], "r");
        if (!fid) {
          fprintf(stderr, "Can't open the kernel source file!\n");
          exit(1);
        }
        
        source_str[i] = (char*)malloc(MAX_SOURCE_SIZE);
        source_size[i] = fread(source_str[i], 1, MAX_SOURCE_SIZE, fid);
        if(source_size[i] != MAX_SOURCE_SIZE) {
          if (ferror(fid)) {
            printf ("Error while reading kernel source file %s\n", source_filename[i]);
            exit(-1);
          }
          if (feof(fid))
            printf ("Kernel source file %s succesfuly read.\n", source_filename[i]);
            //printf("%s\n",source_str[i]);
        }
        fclose(fid);
      }
      
      printf(" compiling sources \n");
  
        // Create a program from the source
        OPS_opencl_core.program = clCreateProgramWithSource(OPS_opencl_core.context, 32, (const char **) &source_str, (const size_t *) &source_size, &ret);
        clSafeCall( ret );
  
        // Build the program
        char buildOpts[255];
        char* pPath = NULL;
        pPath = getenv ("OPS_INSTALL_PATH");
        if (pPath!=NULL)
          sprintf(buildOpts,"-cl-mad-enable -I%s/include -DOPS_WARPSIZE=%d", pPath, 32);
        else {
          //printf("Path = %s\n",pPath);
          sprintf(buildOpts,"-cl-mad-enable -I/home/mudalige/Cloverleaf/OPS/ops/include -DOPS_WARPSIZE=%d", 32);
        }
        
        ret = clBuildProgram(OPS_opencl_core.program, 1, &OPS_opencl_core.device_id, buildOpts, NULL, NULL);
  
        if(ret != CL_SUCCESS) {
          char* build_log;
          size_t log_size;
          clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
          build_log = (char*) malloc(log_size+1);
          clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
          build_log[log_size] = '\0';
          fprintf(stderr, "=============== OpenCL Program Build Info ================\n\n%s", build_log);
          fprintf(stderr, "\n========================================================= \n");
          free(build_log);
          exit(EXIT_FAILURE);
        }
        printf(" compiling done\n");
  
      // Create the OpenCL kernel
      OPS_opencl_core.kernel[0] = clCreateKernel(OPS_opencl_core.program, "ops_viscosity_kernel", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[1] = clCreateKernel(OPS_opencl_core.program, "ops_accelerate_kernel", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[2] = clCreateKernel(OPS_opencl_core.program, "ops_revert_kernel", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[3] = clCreateKernel(OPS_opencl_core.program, "ops_reset_field_kernel1", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[4] = clCreateKernel(OPS_opencl_core.program, "ops_reset_field_kernel2", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[5] = clCreateKernel(OPS_opencl_core.program, "ops_PdV_kernel_predict", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[6] = clCreateKernel(OPS_opencl_core.program, "ops_PdV_kernel_nopredict", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[7] = clCreateKernel(OPS_opencl_core.program, "ops_ideal_gas_kernel", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[8] = clCreateKernel(OPS_opencl_core.program, "ops_flux_calc_kernelx", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[9] = clCreateKernel(OPS_opencl_core.program, "ops_flux_calc_kernely", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[10] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_x1", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[11] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_y1", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[12] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_x2", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[13] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_y2", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[14] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_mass_flux_x", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[15] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_post_pre_advec_x", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[16] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel1_x_nonvector", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[17] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel2_x", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[18] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_mass_flux_y", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[19] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_post_pre_advec_y", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[20] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel1_y_nonvector", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[21] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel2_y", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[22] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel1_xdir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[23] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel2_xdir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[24] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel3_xdir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[25] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel4_xdir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[26] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel1_ydir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[27] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel2_ydir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[28] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel3_ydir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[29] = clCreateKernel(OPS_opencl_core.program, "ops_advec_cell_kernel4_ydir", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[30] = clCreateKernel(OPS_opencl_core.program, "ops_calc_dt_kernel", &ret);
      clSafeCall( ret );
      OPS_opencl_core.kernel[31] = clCreateKernel(OPS_opencl_core.program, "ops_calc_dt_kernel_min", &ret);
      clSafeCall( ret );
      //OPS_opencl_core.kernel[32] = clCreateKernel(OPS_opencl_core.program, "ops_calc_dt_kernel_get", &ret);
      //clSafeCall( ret );
      //OPS_opencl_core.kernel[33] = clCreateKernel(OPS_opencl_core.program, "ops_calc_dt_kernel_print", &ret);
      //clSafeCall( ret );
            
      isbuilt = true;
    }
    
  }
  
//this needs to be a platform specific copy symbol to device function
/*void ops_decl_const_char( int dim, char const * type, int typeSize, char * data, char const * name )
{
  (void)dim;
  (void)type;
  (void)typeSize;
  (void)data;
  (void)name;
}*/

  
//user kernel files
#include "viscosity_kernel_opencl_kernel.cpp"
#include "accelerate_kernel_opencl_kernel.cpp"
#include "revert_kernel_opencl_kernel.cpp"
#include "reset_field_kernel1_opencl_kernel.cpp"
#include "reset_field_kernel2_opencl_kernel.cpp"
#include "PdV_kernel_predict_opencl_kernel.cpp"
#include "PdV_kernel_nopredict_opencl_kernel.cpp"
#include "ideal_gas_kernel_opencl_kernel.cpp"
#include "flux_calc_kernelx_opencl_kernel.cpp"
#include "flux_calc_kernely_opencl_kernel.cpp"
#include "advec_mom_kernel_x1_opencl_kernel.cpp"
#include "advec_mom_kernel_y1_opencl_kernel.cpp"
#include "advec_mom_kernel_x2_opencl_kernel.cpp"
#include "advec_mom_kernel_y2_opencl_kernel.cpp"
#include "advec_mom_kernel_mass_flux_x_opencl_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_x_opencl_kernel.cpp"
#include "advec_mom_kernel1_x_nonvector_opencl_kernel.cpp"
#include "advec_mom_kernel2_x_opencl_kernel.cpp"
#include "advec_mom_kernel_mass_flux_y_opencl_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_y_opencl_kernel.cpp"
#include "advec_mom_kernel1_y_nonvector_opencl_kernel.cpp"
#include "advec_mom_kernel2_y_opencl_kernel.cpp"
#include "advec_cell_kernel1_xdir_opencl_kernel.cpp"
#include "advec_cell_kernel2_xdir_opencl_kernel.cpp"
#include "advec_cell_kernel3_xdir_opencl_kernel.cpp"
#include "advec_cell_kernel4_xdir_opencl_kernel.cpp"
#include "advec_cell_kernel1_ydir_opencl_kernel.cpp"
#include "advec_cell_kernel2_ydir_opencl_kernel.cpp"
#include "advec_cell_kernel3_ydir_opencl_kernel.cpp"
#include "advec_cell_kernel4_ydir_opencl_kernel.cpp"
#include "calc_dt_kernel_opencl_kernel.cpp"
#include "calc_dt_kernel_min_opencl_kernel.cpp"
//#include "calc_dt_kernel_get_opencl_kernel.cpp"
//#include "calc_dt_kernel_print_opencl_kernel.cpp"
