#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **grid;
    int **solution;
    bool **mask;
} sudoku;

sudoku* newSudoku();

void placeDigit(sudoku* s, int digit, int x, int y);

bool compareDigitToSolution(sudoku* s, int x, int y);

void printSudoku(sudoku s);

void freeSudoku(sudoku* s);

#endif //SUDOKU_SOLVER_SUDOKU_H
