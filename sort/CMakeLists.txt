#sort CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(sort)

# 搜索源文件
aux_source_directory(./ SRC_FILES)

# 头文件路径
include_directories(${HEADPATH})

# 静态库输出路径
set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

# 排序算法中用到别的库swapNums，需将此库引用链接，只有SRC_FILES不够

# 引用链接库的名字，不用自己的SWAP了，使用系统的
# link_libraries(${LIBSWAPNUMS})

# 引用链接库的位置路径，不用自己的SWAP了，使用系统的
# link_directories(${LIBSTATICPATH})

# 排序算法静态库生成
add_library(${LIBBUBBLESORT} STATIC ${SRC_FILES})
add_library(${LIBINSERTSORT} STATIC ${SRC_FILES})
add_library(${LIBSELECTSORT} STATIC ${SRC_FILES})
add_library(${LIBMERGESORT} STATIC ${SRC_FILES})
add_library(${LIBSYSTEMSORT} STATIC ${SRC_FILES})