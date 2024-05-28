cmake_minimum_required(VERSION 3.14)
project(lc VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADER_FILES "./*.h" lc/*.h lcr/*.h tool/*.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tool)

add_executable(lc
        main.cc
        ${HEADER_FILES})
