cmake_minimum_required(VERSION 3.27)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(learn_cpp
        start/start.cpp
        start/io.cpp
        )

add_executable(data_type data_type/types.cpp)
