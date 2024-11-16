#ifndef SUDOKU_SOLVER_SOLVER_TEST_H
#define SUDOKU_SOLVER_SOLVER_TEST_H

#include <assert.h>
#include "solver.h"

sudoku* createSolvableSudoku(){
    sudoku *s = newSudoku();

    placeHint(s, 2, 0, 2);
    placeHint(s, 1, 0, 5);
    placeHint(s, 4, 0, 6);
    placeHint(s, 5, 0, 7);

    placeHint(s, 5, 1, 0);
    placeHint(s, 4, 1, 4);
    placeHint(s, 9, 1, 5);
    placeHint(s, 8, 1, 6);

    placeHint(s, 7, 2, 5);

    placeHint(s, 1, 3, 0);
    placeHint(s, 4, 3, 1);
    placeHint(s, 6, 3, 3);
    placeHint(s, 9, 3, 7);

    placeHint(s, 9, 4, 0);
    placeHint(s, 6, 4, 1);
    placeHint(s, 2, 4, 2);
    placeHint(s, 8, 4, 4);
    placeHint(s, 3, 4, 6);

    placeHint(s, 3, 5, 0);
    placeHint(s, 8, 5, 2);
    placeHint(s, 4, 5, 3);
    placeHint(s, 1, 5, 8);

    placeHint(s, 5, 6, 0);
    placeHint(s, 9, 6, 3);
    placeHint(s, 3, 6, 4);
    placeHint(s, 8, 6, 6);

    placeHint(s, 4, 7, 0);
    placeHint(s, 6, 7, 2);
    placeHint(s, 2, 7, 3);
    placeHint(s, 1, 7, 4);
    placeHint(s, 7, 7, 6);

    placeHint(s, 8, 8, 0);
    placeHint(s, 3, 8, 1);
    placeHint(s, 2, 8, 2);
    placeHint(s, 7, 8, 3);
    placeHint(s, 5, 8, 5);
    placeHint(s, 1, 8, 6);
    placeHint(s, 6, 8, 8);

    return s;
}

sudoku* createCompletedSudoku(){
    sudoku *s = createSolvableSudoku();

    //ones
    s->grid[1][2] = s->grid[2][7] = s->grid[4][3] = s->grid[6][1] = 1;

    //twos
    s->grid[1][7] = s->grid[2][3] = s->grid[3][6] = s->grid[5][4] = s->grid[6][7] = 2;

    //threes
    s->grid[0][3] = s->grid[1][1] = s->grid[2][8] = s->grid[3][5] = s->grid[7][8] = 3;

    //fours
    s->grid[2][2] = s->grid[4][8] = s->grid[6][8] = s->grid[8][4] = 4;

    //fives
    s->grid[2][4] = s->grid[3][2] = s->grid[4][5] = s->grid[5][6] = s->grid[7][7] = 5;

    //sixes
    s->grid[0][1] = s->grid[1][3] = s->grid[2][6] = s->grid[5][7] = s->grid[6][5] = s->grid[1][3] = 6;

    //sevens
    s->grid[0][0] = s->grid[1][8] = s->grid[3][4] = s->grid[4][7] = s->grid[5][1] = s->grid[6][2] = 7;

    //eights
    s->grid[0][4] = s->grid[2][1] = s->grid[3][8] = s->grid[7][5] = 8;

    //nines
    s->grid[0][8] = s->grid[2][0] = s->grid[5][5] = s->grid[7][1] = s->grid[8][7] = 9;

    return s;
}

void testSolve(){
    printf("Running all solve() tests... ");
    sudoku* expected = createCompletedSudoku();
    sudoku *result = createSolvableSudoku();
    assert(solve(result, 0, 0) && "Solvable sudoku should be solved.");
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            assert(result->grid[i][j] == expected->grid[i][j] && "Result should be the same as solution.");
    }
    freeSudoku(expected);
    freeSudoku(result);
    printf("Passed.\n");
}

void testCheckPlacement(){
    printf("Running all checkPlacement() tests... ");
    sudoku *s = newSudoku();
    assert(checkPlacement(s) && "Empty sudoku should not be wrong.");
    freeSudoku(s);
    s = createCompletedSudoku();
    assert(checkPlacement(s) && "Valid solution should not be wrong.");
    freeSudoku(s);
    printf("Passed.\n");
}

void testCheckSquares(){
    printf("Running all checkSquares() tests... ");
    sudoku *s = newSudoku();
    assert(checkSquares(s) && "Empty sudoku should not be wrong.");
    freeSudoku(s);
    s = createCompletedSudoku();
    assert(checkSquares(s) && "Valid solution should not be wrong.");
    freeSudoku(s);
    printf("Passed.\n");
}

void testCheckRows(){
    printf("Running all checkRows() tests... ");
    sudoku *s = newSudoku();
    assert(checkRows(s) && "Empty sudoku should not be wrong.");
    freeSudoku(s);
    s = createCompletedSudoku();
    assert(checkRows(s) && "Valid solution should not be wrong.");
    freeSudoku(s);
    printf("Passed.\n");
}

void testCheckColumns(){
    printf("Running all checkColumns() tests... ");
    sudoku *s = newSudoku();
    assert(checkColumns(s) && "Empty sudoku should not be wrong.");
    freeSudoku(s);
    s = createCompletedSudoku();
    assert(checkColumns(s) && "Valid solution should not be wrong.");
    freeSudoku(s);
    printf("Passed.\n");
}

void allSolverTests(){
    printf("Running all solver tests...\n");
    testCheckColumns();
    testCheckRows();
    testCheckSquares();
    testCheckPlacement();
    testSolve();
    printf("All solver tests passed.\n");
}

#endif //SUDOKU_SOLVER_SOLVER_TEST_H
