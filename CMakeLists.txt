cmake_minimum_required(VERSION 3.27)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(learn_cpp
        start/start.cpp
        start/io.cpp
        )

add_executable(data_type data_type/types.cpp)

add_executable(cpp20 cpp20/shorthand.cpp
        cpp20/m_airline_ticket.h
        cpp20/m_airline_ticket.cpp

)
