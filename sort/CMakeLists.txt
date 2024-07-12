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

# 引用链接库的名字，用到里面的随机整数生成器
link_libraries(${LIBUTILS})

# 引用链接库的位置路径，用到里面的随机整数生成器
link_directories(${LIBSTATICPATH})

# 排序算法静态库生成
add_library(${LIBSORT} STATIC ${SRC_FILES})