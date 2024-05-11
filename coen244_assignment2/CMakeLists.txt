cmake_minimum_required(VERSION 3.23)
project(coen244_assignment2)

set(CMAKE_CXX_STANDARD 20)

add_executable(coen244_assignment2 main.cpp Game.h Game.cpp Player.h Player.cpp Board.h Board.cpp Position.h Position.cpp PlayablePosition.h PlayablePosition.cpp)
