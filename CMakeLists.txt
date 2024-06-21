cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)

project(learn_cpp)


add_executable(learn_cpp
        start/start.cpp
        start/io.cpp
        data_type data_type/types.cpp
)


add_executable(demo_simple_class demo_simple_class/shorthand.cpp
        demo_simple_class/m_airline_ticket.h
        demo_simple_class/m_airline_ticket.cpp
)

add_executable(malloc_free malloc_free/main.cpp)

# 构建module步骤(3.28版本)
# 目前不支持import std; 3.30版本更新后尝试
## 构建库
add_library(hello)
## 添加模块到库
target_sources(hello
        PUBLIC
        FILE_SET CXX_MODULES FILES
        demo_module/hello.ixx
)
## 添加可执行文件
add_executable(demo_module
        demo_module/main.cpp
)
## 链接库
target_link_libraries(demo_module hello)
# 构建 demo_module结束

## employee 编译段
add_executable(demo_employee
        demo_employee/main.cpp
        demo_employee/employee.h
        demo_employee/employee.cpp
        demo_employee/database.h
        demo_employee/database.cpp
)

## employee 编译段结束
