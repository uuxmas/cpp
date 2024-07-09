cmake_minimum_required(VERSION 3.0)
project(algorithms)

# 静态链接库地址
set(LIBSTATICPATH ${PROJECT_SOURCE_DIR}/libstatic)

# 可执行程序地址
set(EXEPATH ${PROJECT_SOURCE_DIR}/bin)

# 头文件地址
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)

# 库文件名字
set(LIBRANDOMARRAY randomArray)
set(LIBRIGHTONE rightOne)
set(LIBSWAPNUMS swapNums)
set(LIBBUBBLESORT bubbleSort)
set(LIBINSERTSORT insertSort)
set(LIBSELECTSORT selectSort)


# 应用的名字
set(APPNAME test)

# 添加子目录
add_subdirectory(utils)
add_subdirectory(test)
add_subdirectory(sort)
