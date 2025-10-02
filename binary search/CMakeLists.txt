cmake_minimum_required(VERSION 3.31)
project(binary_search)

set(CMAKE_CXX_STANDARD 20)

add_executable(binary_search
        task_1.cpp
        task_2.cpp
        task_3.cpp)

add_executable(Test1 task_1.cpp)
add_executable(Test2 task_2.cpp)
add_executable(Test3 task_3.cpp)

target_compile_options(binary_search PRIVATE -Wextra -Werror)
