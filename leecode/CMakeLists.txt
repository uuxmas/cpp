cmake_minimum_required(VERSION 3.0)
project(leecodeSolution)

# 源文件搜索
aux_source_directory(./ SRC_FILES)

# 头文件路径
include_directories(${HEADPATH})

# 静态链接库输出路径
set(LIBRARY_OUTPUT_DIRECTORY ${LIBSTATICPATH})

# 静态链接库生成
add_library(${LIBLEECODE} STATIC ${SRC_FILES})