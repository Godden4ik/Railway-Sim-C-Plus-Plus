cmake_minimum_required(VERSION 3.24)
project(RailwaySim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(RailwaySim main.cpp Railway/TrainStation.cpp Railway/TrainStation.h Railway/RailNetwork.cpp
        Railway/RailNetwork.h Railway/Route.cpp Railway/Route.h Train/Train.h Train/Train.cpp)

