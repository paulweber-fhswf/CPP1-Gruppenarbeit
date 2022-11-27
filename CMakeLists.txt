cmake_minimum_required(VERSION 3.23)
project(Tetris C)

set(CMAKE_C_STANDARD 99)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Tetris main.c)
target_link_libraries(Tetris ${CURSES_LIBRARIES})