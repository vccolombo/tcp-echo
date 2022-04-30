cmake_minimum_required(VERSION 3.21)
project(client)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(client
        src/main.cpp src/chat_message.hpp)
