# test CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(test)

# 搜索源文件
aux_source_directory(./ SRC_FILES)

# 头文件路径
include_directories(${HEADPATH})

# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${EXEPATH})

# 下面的可执行程序中用到了下面的库，所以需要将这些库引用链接进来，只有SRC_FILES不够

# 引用链接库的名字
link_libraries(${LIBRANDOMVECTOR})
link_libraries(${LIBRIGHTONE})
link_libraries(${LIBBUBBLESORT})
link_libraries(${LIBINSERTSORT})
link_libraries(${LIBSELECTSORT})
link_libraries(${LIBMERGESORT})
link_libraries(${LIBSYSTEMSORT})

# 引用链接库的位置路径
link_directories(${LIBSTATICPATH})

# 可执行程序生成
add_executable(${APPNAME} ${SRC_FILES})