cmake_minimum_required(VERSION 3.24)
project(RailwaySim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(RailwaySim main.cpp TrainStation.cpp TrainStation.h RailNetwork.cpp RailNetwork.h Route.cpp Route.h)
