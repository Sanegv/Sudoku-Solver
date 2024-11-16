# Sudoku solver

## Goal

The goal of this program is to solve any given sudoku grid, if a solution exists.
The backtracking algorithm used in this repo is copied from the one I implemented in my [8-Queens Solver](https://github.com/Sanegv/8-Queens-Solver) project, because the steps are basically the same, except that you have to check for sub grids instead of diagonals.

The goal here was to use two concepts:
- backtracking
- Unit Testing (in C)

### Backtracking

A backtracking algorithm is a type of algorithm used to find a solution that satisfies some constraints.
To do so, we iterate over a tree of possibilities, and as soon as one possibility proves to violate a constraint, we eliminate it.

This kind of algorithm is used to solve problems like exploring a labyrinth,finding moves in chess, solving sudoku grids, etc.

### Unit Testing

While not a brand-new concept, I wanted to force myself to do this project properly, and TDD (Test Driven Development) allowed me to gain a lot of time when trying an implementation.
C unit testing is not as advanced as Java's JUnit or Go's Testing, but it is more than enough to create a working TDD environment.

## SUdoku

A sudoku is a well known puzzle, in which we are given a 9*9 grid with a few digits already placed in it.

This grid is also divided in nine 3*3 smaller grids, and to solve a sudoku puzzle, one must fill every tile in such a way that each row, column, and 3*3 square contains one an only one occurrence of each digit.

This is obviously extremely similar to the [N-Queens problem](https://github.com/Sanegv/N-Queens-Solver), that I've already solved. 

## Files

This repository is divided in two main directories.

### [src](./src)

This folder contains all the actual code used for the [sudoku](./src/sudoku.h),the [solver](./src/solver.h), and a [main](./src/main.c) function that finds prints a solution in the terminal.

### [tests](./tests)

This folder holds all the unit tests for all the functions of src 
(except the one that prints the board).

- [unit_tests](./tests/unit_tests.c) has its own main, and calls all the tests of the other files.
- [sudoku_test](./tests/sudoku_test.h) and [solver_test](./tests/solver_test.h) test all the functions defined in [sudoku](./src/sudoku.h) and [solver](./src/solver.h), respectively.