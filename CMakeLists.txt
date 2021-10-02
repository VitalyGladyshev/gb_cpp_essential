cmake_minimum_required(VERSION 3.20)
project(gb_cpp_essential)

set(CMAKE_CXX_STANDARD 17)

add_executable(gb_cpp_essential
        hw_03/hw_03.cpp cmake-build-debug/hw_03/DataCube.cpp cmake-build-debug/hw_03/DataCube.h cmake-build-debug/hw_03/hw_03.cpp)
