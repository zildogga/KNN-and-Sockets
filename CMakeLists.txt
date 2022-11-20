cmake_minimum_required(VERSION 3.23)
project(Advanced_Programming_1_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Advanced_Programming_1_Project
        # README.md
        distance/cpp/main.cpp distance/h/main.h distance/cpp/minkowski.cpp distance/h/minkowski.h distance/cpp/canberra.cpp distance/h/canberra.h distance/cpp/chebyshev.cpp distance/h/chebyshev.h)
