cmake_minimum_required(VERSION 3.10)
project(cpp11)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp11 main.cpp activator.cpp activator.hpp)

target_link_libraries(cpp11 pthread)