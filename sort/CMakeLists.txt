cmake_minimum_required(VERSION 3.0)
project(sort)

aux_source_directory(./ SRC_FILES)

set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

include_directories(${HEADPATH})

# 用到了别的库swapNums，所以需要链接进来，只有SRC_FILES不够
link_libraries(${LIBSWAPNUMS})
link_directories(${LIBSTATICPATH})

add_library(${LIBBUBBLESORT} STATIC ${SRC_FILES})
add_library(${LIBINSERTSORT} STATIC ${SRC_FILES})
add_library(${LIBSELECTSORT} STATIC ${SRC_FILES})