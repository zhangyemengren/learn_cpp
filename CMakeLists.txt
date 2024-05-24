cmake_minimum_required(VERSION 3.28)
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

# 构建module步骤(3.28版本 不知道后续能否简化)
## 构建库
add_library(hello)
## 添加模块到库
target_sources(hello
        PUBLIC
        FILE_SET CXX_MODULES FILES
        module_demo/hello.ixx
)
## 添加可执行文件
add_executable(module_demo
        module_demo/main.cpp
)
## 链接库
target_link_libraries(module_demo hello)
