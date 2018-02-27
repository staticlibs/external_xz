# Copyright 2016, alex at staticlibs.net
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required ( VERSION 2.8.12 )

project ( lzma C )

if ( NOT DEFINED ${PROJECT_NAME}_LOOKASIDE_DIR )
    set ( ${PROJECT_NAME}_LOOKASIDE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../lookaside_xz CACHE INTERNAL "" )
endif ( )

# check deplibs cache
if ( STATICLIB_USE_DEPLIBS_CACHE )
    set ( ${PROJECT_NAME}_CACHED_LIB_PATH ${STATICLIB_DEPLIBS_CACHE_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_STATIC_LIBRARY_SUFFIX} )
    if ( EXISTS ${${PROJECT_NAME}_CACHED_LIB_PATH} )
        add_library( ${PROJECT_NAME} STATIC IMPORTED GLOBAL )
        set_target_properties( ${PROJECT_NAME} PROPERTIES IMPORTED_LOCATION ${${PROJECT_NAME}_CACHED_LIB_PATH} )
        message ( STATUS "Using cached library: [${${PROJECT_NAME}_CACHED_LIB_PATH}]" )
        return ( )
    endif ( )
endif ( )

add_library ( ${PROJECT_NAME} STATIC 
        # common
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_cpucores.c
#        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_exit.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_mbstr_fw.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_mbstr_width.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_open_stdxxx.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_physmem.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common/tuklib_progname.c
        # liblzma/common
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/alone_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/alone_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/auto_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_buffer_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_buffer_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_header_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_header_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/block_util.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/common.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/easy_buffer_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/easy_decoder_memusage.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/easy_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/easy_encoder_memusage.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/easy_preset.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_buffer_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_buffer_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_common.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_flags_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/filter_flags_encoder.c
        # ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/hardware_cputhreads.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/hardware_physmem.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/index.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/index_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/index_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/index_hash.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/outqueue.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_buffer_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_buffer_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_encoder.c
#        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_encoder_mt.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_flags_common.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_flags_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/stream_flags_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/vli_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/vli_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common/vli_size.c
        # liblzma/check
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/check.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc32_fast.c
#        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc32_small.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc32_table.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc32_tablegen.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc64_fast.c
#        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc64_small.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc64_table.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/crc64_tablegen.c
#        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check/sha256.c
        # liblzma/delta
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/delta/delta_common.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/delta/delta_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/delta/delta_encoder.c
        # liblzma/lz
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lz/lz_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lz/lz_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lz/lz_encoder_mf.c
        # liblzma/lzma
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/fastpos_table.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/fastpos_tablegen.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma2_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma2_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma_encoder_optimum_fast.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma_encoder_optimum_normal.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma/lzma_encoder_presets.c
        # liblzma/rangecoder
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/rangecoder/price_table.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/rangecoder/price_tablegen.c         
        # liblzma/simple
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/arm.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/armthumb.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/ia64.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/powerpc.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/simple_coder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/simple_decoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/simple_encoder.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/sparc.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple/x86.c
)
target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/../xz_include 
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/api
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/common
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/common 
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/check 
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/delta
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lz
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/lzma
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/rangecoder
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/liblzma/simple )
target_compile_definitions ( ${PROJECT_NAME} PRIVATE -DHAVE_CONFIG_H )

if ( ${CMAKE_C_COMPILER_ID} MATCHES "(GNU|Clang)" )
    target_compile_options ( ${PROJECT_NAME} PRIVATE --std=gnu99 )
elseif ( ${CMAKE_C_COMPILER_ID}x MATCHES "MSVCx" )
    target_compile_options ( ${PROJECT_NAME} PRIVATE
            /wd4028 /wd4113 /wd4133 )
    target_compile_definitions ( ${PROJECT_NAME} PRIVATE
            -DLZMA_API_STATIC
            -Dinline=_inline
            -Drestrict=_restrict )
endif ( )
