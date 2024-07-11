# utils CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(utils)

# 搜索源文件
aux_source_directory(./ SRC_FILES)

# 头文件位置路径
include_directories(${HEADPATH})

# 静态库输出路径
set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

# 工具静态库生成
add_library(${LIBUTILS} STATIC ${SRC_FILES})