cmake_minimum_required(VERSION 3.0)
project(utils)

aux_source_directory(./ SRC_FILES)

set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

include_directories(${HEADPATH})

add_library(${LIBRANDOMARRAY} STATIC ${SRC_FILES})
add_library(${LIBRIGHTONE} STATIC ${SRC_FILES})
add_library(${LIBSWAPNUMS} STATIC ${SRC_FILES})
