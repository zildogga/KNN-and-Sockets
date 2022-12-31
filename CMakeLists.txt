cmake_minimum_required(VERSION 3.20.2)
project(Advanced_Programming_1_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Advanced_Programming_1_Project
        # README.md
        DistanceClass.h DistanceClass.cpp Main.cpp Main.h Minkowski.cpp Minkowski.h Canberra.cpp Canberra.h Chebyshev.cpp Chebyshev.h Manhattan.cpp Manhattan.h Euclidean.cpp Euclidean.h ReadFile.cpp ReadFile.h Classification.cpp Classification.h Knn.h Knn.cpp
        Server.cpp Server.h)
