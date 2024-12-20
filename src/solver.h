#ifndef SUDOKU_SOLVER_SOLVER_H
#define SUDOKU_SOLVER_SOLVER_H

#include "sudoku.h"

bool solve(sudoku* s, int square, int tile);

bool checkPlacement(sudoku* s);

bool checkSquares(sudoku *s);

bool checkRows(sudoku *s);

bool checkColumns(sudoku *s);

void addAllHints(sudoku* s);

#endif //SUDOKU_SOLVER_SOLVER_H
