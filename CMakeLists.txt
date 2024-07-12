# algorithms CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(algorithms)

# 宏定义

# print开关
# add_definitions(-DDEBUG)

# 设置编译参数
add_compile_options(-std=c++11 -Wall -g)

# C++编译标准，上面可以实现，这里暂不使用
# set(CMAKE_CXX_STANDARD 11)

# 暂不使用
# set(CMAKE_BUILD_TYPE "Debug")

# 静态链接库地址
set(LIBSTATICPATH ${PROJECT_SOURCE_DIR}/libstatic)

# 可执行程序地址
set(EXEPATH ${PROJECT_SOURCE_DIR}/bin)

# 头文件地址
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)

# 静态链接库名
set(LIBUTILS utils)
set(LIBSORT sort)
set(LIBLEETCODE leetcode)

# 应用名
set(APPTEST test)

# 添加子目录
add_subdirectory(utils)
add_subdirectory(sort)
add_subdirectory(leetcode)

add_subdirectory(test)
