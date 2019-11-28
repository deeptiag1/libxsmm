/******************************************************************************
** Copyright (c) 2016-2019, Intel Corporation                                **
** All rights reserved.                                                      **
**                                                                           **
** Redistribution and use in source and binary forms, with or without        **
** modification, are permitted provided that the following conditions        **
** are met:                                                                  **
** 1. Redistributions of source code must retain the above copyright         **
**    notice, this list of conditions and the following disclaimer.          **
** 2. Redistributions in binary form must reproduce the above copyright      **
**    notice, this list of conditions and the following disclaimer in the    **
**    documentation and/or other materials provided with the distribution.   **
** 3. Neither the name of the copyright holder nor the names of its          **
**    contributors may be used to endorse or promote products derived        **
**    from this software without specific prior written permission.          **
**                                                                           **
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       **
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         **
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR     **
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT      **
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    **
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  **
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR    **
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    **
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      **
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        **
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              **
******************************************************************************/
/* Hans Pabst (Intel Corp.)
******************************************************************************/
#ifndef LIBXSMM_SOURCE_H
#define LIBXSMM_SOURCE_H

#if defined(LIBXSMM_MACROS_H)
# error Please do not include any LIBXSMM header other than libxsmm_source.h!
#endif
#if defined(LIBXSMM_BUILD)
# error LIBXSMM_BUILD cannot be defined for the header-only LIBXSMM!
#endif
#if !defined(LIBXSMM_API)
# define LIBXSMM_API LIBXSMM_EXTERN_C LIBXSMM_INLINE LIBXSMM_RETARGETABLE
#endif

/**
 * This header is intentionally called "libxsmm_source.h" since the followings block
 * includes *internal* files, and thereby exposes LIBXSMM's implementation.
 * The so-called "header-only" usage model gives up the clearly defined binary interface
 * (including support for hot-fixes after deployment), and requires to rebuild client
 * code for every (internal) change of LIBXSMM. Please make sure to only rely on the
 * public interface as the internal implementation may change without notice.
 */
#if defined(LIBXSMM_OFFLOAD_TARGET)
# pragma offload_attribute(push,target(LIBXSMM_OFFLOAD_TARGET))
#endif
#include "../src/generator_common.c"
#include "../src/generator_gemm.c"
#include "../src/generator_gemm_avx2_microkernel.c"
#include "../src/generator_gemm_avx512_fsdbcst.c"
#include "../src/generator_gemm_avx512_microkernel_fsdbcst.c"
#include "../src/generator_gemm_avx512_microkernel_nofsdbcst.c"
#include "../src/generator_gemm_avx_microkernel.c"
#include "../src/generator_gemm_common.c"
#include "../src/generator_gemm_noarch.c"
#include "../src/generator_gemm_sse3_avx_avx2_avx512.c"
#include "../src/generator_gemm_sse3_microkernel.c"
#include "../src/generator_matcopy.c"
#include "../src/generator_matcopy_avx_avx512.c"
#include "../src/generator_packed.c"
#include "../src/generator_packed_gemm_ac_rm_avx_avx2_avx512.c"
#include "../src/generator_packed_gemm_avx_avx512.c"
#include "../src/generator_packed_gemm_bc_rm_avx_avx2_avx512.c"
#include "../src/generator_packed_getrf_avx_avx512.c"
#include "../src/generator_packed_trmm_avx_avx512.c"
#include "../src/generator_packed_trsm_avx_avx512.c"
#include "../src/generator_spgemm.c"
#include "../src/generator_spgemm_csc_asparse.c"
#include "../src/generator_spgemm_csc_bsparse.c"
#include "../src/generator_spgemm_csc_bsparse_soa.c"
#include "../src/generator_spgemm_csc_reader.c"
#include "../src/generator_spgemm_csr_asparse.c"
#include "../src/generator_spgemm_csr_asparse_reg.c"
#include "../src/generator_spgemm_csr_asparse_soa.c"
#include "../src/generator_spgemm_csr_bsparse_soa.c"
#include "../src/generator_spgemm_csr_reader.c"
#include "../src/generator_transpose.c"
#include "../src/generator_transpose_avx_avx512.c"
#include "../src/generator_x86_instructions.c"
#include "../src/libxsmm_blocked_gemm.c"
#include "../src/libxsmm_cpuid_x86.c"
#include "../src/libxsmm_dnn.c"
#include "../src/libxsmm_dnn_convolution.c"
#include "../src/libxsmm_dnn_convolution_backward.c"
#include "../src/libxsmm_dnn_convolution_forward.c"
#include "../src/libxsmm_dnn_convolution_weight_update.c"
#include "../src/libxsmm_dnn_elementwise.c"
#include "../src/libxsmm_dnn_fullyconnected.c"
#include "../src/libxsmm_dnn_fullyconnected_backward.c"
#include "../src/libxsmm_dnn_fullyconnected_forward.c"
#include "../src/libxsmm_dnn_fullyconnected_weight_update.c"
#include "../src/libxsmm_dnn_fusedbatchnorm.c"
#include "../src/libxsmm_dnn_fusedbatchnorm_backward.c"
#include "../src/libxsmm_dnn_fusedbatchnorm_forward.c"
#include "../src/libxsmm_dnn_pooling.c"
#include "../src/libxsmm_dnn_pooling_backward.c"
#include "../src/libxsmm_dnn_pooling_forward.c"
#include "../src/libxsmm_dnn_rnncell.c"
#include "../src/libxsmm_dnn_rnncell_backward_weight_update.c"
#include "../src/libxsmm_dnn_rnncell_forward.c"
#include "../src/libxsmm_dnn_tensor.c"
#include "../src/libxsmm_ext.c"
#include "../src/libxsmm_ext_blocked_gemm.c"
#include "../src/libxsmm_ext_gemm.c"
#include "../src/libxsmm_ext_xcopy.c"
#include "../src/libxsmm_fsspmdm.c"
#include "../src/libxsmm_gemm.c"
#include "../src/libxsmm_generator.c"
#include "../src/libxsmm_hash.c"
#include "../src/libxsmm_main.c"
#include "../src/libxsmm_malloc.c"
#include "../src/libxsmm_math.c"
#include "../src/libxsmm_memory.c"
#include "../src/libxsmm_mhd.c"
#include "../src/libxsmm_perf.c"
#include "../src/libxsmm_python.c"
#include "../src/libxsmm_rng.c"
#include "../src/libxsmm_spmdm.c"
#include "../src/libxsmm_sync.c"
#include "../src/libxsmm_timer.c"
#include "../src/libxsmm_trace.c"
#include "../src/libxsmm_xcopy.c"
#if defined(LIBXSMM_OFFLOAD_TARGET)
# pragma offload_attribute(pop)
#endif

#endif /*LIBXSMM_SOURCE_H*/
