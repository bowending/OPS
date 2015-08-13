/*
* Open source copyright declaration based on BSD open source template:
* http://www.opensource.org/licenses/bsd-license.php
*
* This file is part of the OPS distribution.
*
* Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
* the main source directory for a full list of copyright holders.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * The name of Mike Giles may not be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @brief ops mpi run-time support routines
  * @author Gihan Mudalige, Istvan Reguly
  * @details Implements the runtime support routines for the OPS mpi backend
  */


#include <ops_lib_core.h>

#include <mpi.h>
#include <ops_mpi_core.h>

#ifndef __XDIMS__ //perhaps put this into a separate headder file
#define __XDIMS__
  int xdim0;
  int ydim0;
  int xdim1;
  int ydim1;
  int xdim2;
  int ydim2;
  int xdim3;
  int ydim3;
  int xdim4;
  int ydim4;
  int xdim5;
  int ydim5;
  int xdim6;
  int ydim6;
  int xdim7;
  int ydim7;
  int xdim8;
  int ydim8;
  int xdim9;
  int ydim9;
  int xdim10;
  int ydim10;
  int xdim11;
  int ydim11;
  int xdim12;
  int ydim12;
  int xdim13;
  int ydim13;
  int xdim14;
  int ydim14;
  int xdim15;
  int ydim15;
  int xdim16;
  int ydim16;
  int xdim17;
  int ydim17;
#endif /* __XDIMS__ */

#ifndef __MULTIDIMS__
#define __MULTIDIMS__
int multi_d0;
int multi_d1;
int multi_d2;
int multi_d3;
int multi_d4;
int multi_d5;
int multi_d6;
int multi_d7;
int multi_d8;
int multi_d9;
int multi_d10;
int multi_d11;
int multi_d12;
int multi_d13;
int multi_d14;
int multi_d15;
int multi_d16;
int multi_d17;
#endif /*__MULTIDIMS__*/

void ops_timers(double * cpu, double * et)
{
    MPI_Barrier(MPI_COMM_WORLD);
    ops_timers_core(cpu,et);
}

void ops_printf(const char* format, ...)
{
  if(ops_my_global_rank==MPI_ROOT) {
    va_list argptr;
    va_start(argptr, format);
    vprintf(format, argptr);
    va_end(argptr);
  }
}

void ops_fprintf(FILE *stream, const char *format, ...)
{
  if(ops_my_global_rank==MPI_ROOT) {
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stream, format, argptr);
    va_end(argptr);
  }
}

void ops_compute_moment(double t, double *first, double *second) {
  double times[2] = {0.0};
  double times_reduced[2] = {0.0};
  int comm_size;
  times[0] = t;
  times[1] = t*t;
  MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  MPI_Reduce(times, times_reduced, 2, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  *first = times_reduced[0]/(double)comm_size;
  *second = times_reduced[1]/(double)comm_size;
}

int ops_is_root()
{
  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  return (my_rank==MPI_ROOT);
}

void ops_set_dirtybit_host(ops_arg *args, int nargs)
{
  for (int n=0; n<nargs; n++) {
    if((args[n].argtype == OPS_ARG_DAT) &&
       (args[n].acc == OPS_INC || args[n].acc == OPS_WRITE || args[n].acc == OPS_RW) ) {
      args[n].dat->dirty_hd = 1;
    }
  }
}

ops_arg ops_arg_dat( ops_dat dat, int dim, ops_stencil stencil, char const * type, ops_access acc )
{
  ops_arg temp = ops_arg_dat_core( dat, stencil, acc );
  (&temp)->dim = dim;
  return temp;
}

ops_arg ops_arg_dat_opt( ops_dat dat, int dim, ops_stencil stencil, char const * type, ops_access acc, int flag )
{
  ops_arg temp = ops_arg_dat_core( dat, stencil, acc );
  (&temp)->dim = dim;
  (&temp)->opt = flag;
  return temp;
}

ops_arg ops_arg_gbl_char( char * data, int dim, int size, ops_access acc )
{
  return ops_arg_gbl_core( data, dim, size, acc );
}

ops_arg ops_arg_reduce ( ops_reduction handle, int dim, const char *type, ops_access acc) {
  int was_initialized = handle->initialized;
  ops_arg temp = ops_arg_reduce_core(handle, dim, type, acc);
  if (!was_initialized) {
    for (int i = 1; i < OPS_block_index; i++) {
      memcpy(handle->data + i*handle->size, handle->data, handle->size);
    }
  }
  return temp;
}

ops_reduction ops_decl_reduction_handle(int size, const char *type, const char *name) {

  if( strcmp(type,"double")  == 0 ||
        strcmp(type,"real(8)") == 0||
        strcmp(type,"double precision" ) == 0) type = "double\0";
  else if( strcmp(type,"float")  == 0 ||
        strcmp(type,"real") == 0) type = "float";
  else if( strcmp(type,"int")     == 0 ||
           strcmp(type,"integer") == 0 ||
           strcmp(type,"integer(4)") == 0 ||
           strcmp(type,"int(4)")  == 0) type = "int";

  ops_reduction red = ops_decl_reduction_handle_core(size, type, name);
  red->data = (char *)realloc(red->data, red->size*OPS_block_index*sizeof(char));
  return red;
}

bool ops_checkpointing_filename(const char *file_name, char *filename_out, char *filename_out2) {
  sprintf(filename_out, "%s.%d", file_name, ops_my_global_rank);
  sprintf(filename_out2, "%s.%d.dup", file_name, (ops_my_global_rank + OPS_ranks_per_node)%ops_comm_global_size );
  return (OPS_enable_checkpointing>1);
}

void ops_checkpointing_calc_range(ops_dat dat, const int *range, int *discarded_range) {
  for (int d = 0; d < OPS_MAX_DIM; d++) {
    discarded_range[2*d] = 0;
    discarded_range[2*d+1] = 0;
  }
  sub_block *sb = OPS_sub_block_list[dat->block->index];
  sub_dat *sd = OPS_sub_dat_list[dat->index];
  if (!sb->owned) return;

  for (int d = 0; d < dat->block->dims; d++) {
    if (sd->decomp_size[d] - sd->d_im[d] + sd->d_ip[d] != dat->size[d]) printf("Problem 1\n");

    discarded_range[2*d] = MAX(0,range[2*d] - (sd->decomp_disp[d] - sd->d_im[d]));
    discarded_range[2*d+1] = MAX(0, MIN(dat->size[d], range[2*d+1] - (sd->decomp_disp[d] - sd->d_im[d])));
    // if (range[2*d+1] >= (sd->decomp_disp[d]+sd->decomp_size[d]))
    //   discarded_range[2*d+1] = dat->size[d]; //Never save intra-block halo
    // else if (range[2*d+1] <= sd->decomp_disp[d])
    //   discarded_range[2*d+1] = 0;
    // else
    //   discarded_range[2*d+1] = (range[2*d+1] - (sd->decomp_disp[d] - sd->d_im[d]));
  }
}

char *OPS_checkpoiting_dup_buffer = NULL;
int OPS_checkpoiting_dup_buffer_size = 0;
int recv_stats[2+2*OPS_MAX_DIM];

void ops_checkpointing_duplicate_data(ops_dat dat, int my_type, int my_nelems, char *my_data, int *my_range,
                                               int *rm_type, int *rm_elems, char **rm_data, int **rm_range) {

  MPI_Status statuses[2];
  MPI_Request requests[2];
  int send_stats[2+2*OPS_MAX_DIM];
  send_stats[0] = my_type;
  send_stats[1] = my_nelems;
  memcpy(&send_stats[2], my_range, 2*OPS_MAX_DIM*sizeof(int));
  MPI_Isend(send_stats, 2+2*OPS_MAX_DIM, MPI_INT, (ops_my_global_rank + OPS_ranks_per_node)%ops_comm_global_size, 1000+OPS_dat_index+dat->index, OPS_MPI_GLOBAL, &requests[0]);
  int bytesize = dat->elem_size/dat->dim;
  MPI_Isend(my_data, my_nelems*bytesize, MPI_CHAR, (ops_my_global_rank + OPS_ranks_per_node)%ops_comm_global_size, 1000+dat->index, OPS_MPI_GLOBAL, &requests[1]);


  MPI_Recv(recv_stats, 2+2*OPS_MAX_DIM, MPI_INT, (ops_my_global_rank - OPS_ranks_per_node)%ops_comm_global_size, 1000+OPS_dat_index+dat->index, OPS_MPI_GLOBAL, &statuses[0]);
  if (recv_stats[1]*bytesize > OPS_checkpoiting_dup_buffer_size) {
    OPS_checkpoiting_dup_buffer = (char *)realloc(OPS_checkpoiting_dup_buffer, recv_stats[1]*bytesize*2*sizeof(char));
    OPS_checkpoiting_dup_buffer_size = recv_stats[1]*bytesize*2;
  }
  *rm_data = OPS_checkpoiting_dup_buffer;
  MPI_Recv(*rm_data, recv_stats[1]*bytesize, MPI_CHAR, (ops_my_global_rank - OPS_ranks_per_node)%ops_comm_global_size, 1000+dat->index, OPS_MPI_GLOBAL, &statuses[1]);
  *rm_type = recv_stats[0];
  *rm_elems = recv_stats[1];
  *rm_range = &recv_stats[2];
  MPI_Waitall(2, requests, statuses);
}

void ops_get_dat_full_range(ops_dat dat, int **full_range) {
  *full_range = OPS_sub_dat_list[dat->index]->gbl_size;
}
