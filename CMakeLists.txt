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

# project
project ( external_xz CXX C )
set ( ${PROJECT_NAME}_STATICLIB_VERSION 5.1.2-1 )
set ( ${PROJECT_NAME}_DESCRIPTION "XZ (lzma) library build for Staticlibs" )
set ( ${PROJECT_NAME}_URL https://github.com/staticlibs/external_lzma.git )

# standalone build
if ( NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY )
    set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
endif ( )

# xz subproject
add_subdirectory ( ${CMAKE_CURRENT_LIST_DIR}/resources/xz_cmake ${CMAKE_CURRENT_BINARY_DIR}/xz )
add_custom_target ( ${PROJECT_NAME} DEPENDS lzma )

# pkg-config
set ( ${PROJECT_NAME}_MODULE liblzma )
set ( ${PROJECT_NAME}_PC_CFLAGS "-I${CMAKE_CURRENT_LIST_DIR}/resources/xz_include -I${CMAKE_CURRENT_LIST_DIR}/xz/src/liblzma/api" )
if ( ${CMAKE_C_COMPILER_ID}x MATCHES "MSVCx" )
    set ( ${PROJECT_NAME}_PC_CFLAGS "${${PROJECT_NAME}_PC_CFLAGS} -DLZMA_API_STATIC" )
endif ( )
set ( ${PROJECT_NAME}_PC_LIBS "-L${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -llzma" )
configure_file ( ${CMAKE_CURRENT_LIST_DIR}/resources/pkg-config.in 
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/liblzma.pc )
configure_file ( ${CMAKE_CURRENT_LIST_DIR}/resources/pkg-config.in 
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/lzma.pc )
