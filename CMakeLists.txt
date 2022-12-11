cmake_minimum_required(VERSION 3.20.2)
project(Advanced_Programming_1_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Advanced_Programming_1_Project
        # README.md
        distance/h/DistanceClass.h distance/cpp/DistanceClass.cpp distance/cpp/Main.cpp distance/h/Main.h distance/cpp/Minkowski.cpp distance/h/Minkowski.h distance/cpp/Canberra.cpp distance/h/Canberra.h distance/cpp/Chebyshev.cpp distance/h/Chebyshev.h distance/cpp/Manhattan.cpp distance/h/Manhattan.h distance/cpp/Euclidean.cpp distance/h/Euclidean.h
        distance/h/Knn.h distance/cpp/Knn.cpp)
