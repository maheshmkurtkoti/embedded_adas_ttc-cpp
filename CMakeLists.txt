cmake_minimum_required(VERSION 3.16)
project(embedded_adas_ttc-cpp)

set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Include headers
include_directories(include)

#Source files 
file(GLOB_RECURSE SRC_FILES src/*.cpp)

#Library
add_library(adas_lib ${SRC_FILES})

#Demo executable
add_executable(pipeline_demo examples/pipeline_demo.cpp)
traget_link_libraries(pipeline_demo adas_lib)