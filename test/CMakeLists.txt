cmake_minimum_required(VERSION 3.0)
project(test)

aux_source_directory(./ SRC_FILES)

set(EXECUTABLE_OUTPUT_PATH ${EXEPATH})

include_directories(${HEADPATH})

link_directories(${LIBSTATICPATH})
link_libraries(${LIBRANDOMARRAY})
link_libraries(${LIBRIGHTONE})
link_libraries(${LIBBUBBLESORT})
add_executable(${APPNAME} ${SRC_FILES})