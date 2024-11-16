cmake_minimum_required(VERSION 3.27)
project(Sudoku_Solver C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(tests)

add_executable(Sudoku_Solver
        src/sudoku.c
        src/sudoku.h
        src/main.c
        src/solver.c
        src/solver.h)

add_executable(Sudoku_tester
        src/sudoku.c
        src/sudoku.h
        src/solver.c
        src/solver.h
        tests/sudoku_test.h
        tests/unit_tests.c)