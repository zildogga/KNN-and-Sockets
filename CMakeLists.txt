cmake_minimum_required(VERSION 3.20.2)
project(Advanced_Programming_1_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Advanced_Programming_1_Project
        # README.md
        DistanceClass.h DistanceClass.cpp Minkowski.cpp Minkowski.h Canberra.cpp Canberra.h Chebyshev.cpp Chebyshev.h Manhattan.cpp Manhattan.h Euclidean.cpp Euclidean.h ReadFile.cpp ReadFile.h Classification.cpp Classification.h Knn.h Knn.cpp Server.cpp Server.h Client.cpp Client.h MainClient.cpp MainClient.h DefaultIO.cpp DefaultIO.h Command.cpp Command.h StandardIO.cpp StandardIO.h SocketIO.cpp SocketIO.h CLI.cpp CLI.h UploadCommandServer.cpp UploadCommandServer.h SettingsCommandServer.cpp SettingsCommandServer.h ClassifyCommandServer.cpp ClassifyCommandServer.h DisplayCommandServer.cpp DisplayCommandServer.h DownloadCommandServer.cpp DownloadCommandServer.h ExitCommandClient.cpp ExitCommandClient.h Data.cpp Data.h UploadCommandClient.cpp UploadCommandClient.h UploadCommandClient.h UploadCommandClient.h UploadCommandServer.cpp SettingsCommandClient.cpp SettingsCommandClient.h ExitCommandServer.cpp ExitCommandServer.h ClassifyCommandClient.cpp ClassifyCommandClient.h DisplayCommandClient.cpp DisplayCommandClient.h DownloadCommandClient.cpp DownloadCommandClient.h BeforeDownloadCommandClient.cpp BeforeDownloadCommandClient.h)
