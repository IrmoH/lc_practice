cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADER_FILES "./*.h")

add_executable(leetcode
        main.cpp
        ${HEADER_FILES})
