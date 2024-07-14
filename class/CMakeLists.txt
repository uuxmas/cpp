cmake_minimum_required(VERSION 3.0)
project(class)

# 源文件搜索
aux_source_directory(./ SRC_FILES)

# 头文件路径
include_directories(${HEADPATH})

# 静态链接库输出路径，不是DIRECTORY是PATH
set(LIBRARY_OUTPUT_PATH ${LIBSTATICPATH})

# 静态链接库生成
add_library(${LIBCLASS} STATIC ${SRC_FILES})