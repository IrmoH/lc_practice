cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADER_FILES "./*.h" lc/*.h lcr/*.h tool/*.h)
include_directories("tool")

add_executable(leetcode
        main.cpp
        ${HEADER_FILES})
