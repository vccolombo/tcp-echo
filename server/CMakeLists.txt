cmake_minimum_required(VERSION 3.21)
project(server)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(server
        src/main.cpp
        src/server.cpp
        src/server.h src/Connection.cpp src/Connection.h)
