cmake_minimum_required(VERSION 3.16)

project(bool_vec)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


add_executable(bool_vec main.cpp bool_vec.hpp bool_vec.cpp)