cmake_minimum_required(VERSION 3.20)
project(gb_cpp_essential)

set(CMAKE_CXX_STANDARD 17)

#add_library(mylib STATIC hw_07/mylib.cpp)

add_executable(gb_cpp_essential
        TicTacToe/main.cpp TicTacToe/TicTacToe.cpp TicTacToe/TicTacToe.h)

#target_link_libraries(gb_cpp_essential mylib)
