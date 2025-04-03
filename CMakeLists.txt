cmake_minimum_required(VERSION 3.27)
project(snowman)

set(CMAKE_CXX_STANDARD 17)

add_executable(snowman main.cpp
        functions.cpp
        functions.h)
