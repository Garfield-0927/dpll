cmake_minimum_required(VERSION 3.16)
project(dpll)

set(CMAKE_CXX_STANDARD 14)

add_executable(dpll main.cpp dpll-slover.h cnf-parser.h global.h sudoku.h)