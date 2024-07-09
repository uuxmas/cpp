cmake_minimum_required(VERSION 3.0)
project(sort)

aux_source_directory(./ SRC_FILES)

set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

include_directories(${HEADPATH})

link_libraries(${LIBSWAPNUMS})
link_directories(${LIBSTATICPATH})

add_library(${LIBBUBBLESORT} STATIC ${SRC_FILES})