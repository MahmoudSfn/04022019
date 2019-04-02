cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER g++-8)
project(platooning)
set(SRC main.cpp
        icar.cpp
        mcp_can.cpp
        )
add_executable(ex_platooning ${SRC})