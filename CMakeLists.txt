cmake_minimum_required(VERSION 3.31)
project(PingPong)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(PingPong src/main.cpp
        src/Ball.cpp
        src/Ball.h
        src/CpuPaddle.cpp
        src/CpuPaddle.h
        src/Paddle.cpp
        src/Paddle.h)

target_link_libraries(PingPong raylib)
