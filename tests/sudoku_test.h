#ifndef SUDOKU_SOLVER_SUDOKU_TEST_H
#define SUDOKU_SOLVER_SUDOKU_TEST_H

#include <assert.h>
#include "sudoku.h"

void testNewSudoku(){
    printf("Running newSudoku() Tests... ");

    sudoku *s = newSudoku();

    assert(s != NULL && "newSudoku should allocate space for sudoku");
    assert(s->grid != NULL && "newSudoku should allocate space for grid");
    assert(s->mask != NULL && "newSudoku should allocate space for mask");

    for(int i = 0; i < 9; i++)
        assert(s->mask[i] != NULL && "newSudoku should allocate space for digits in solution");
    for(int i = 0; i < 9; i++)
        assert(s->grid[i] != NULL && "newSudoku should allocate space for digits in solution");

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            assert(!s->mask[i][j] && "newSudoku should initialize solution at false");
            assert(s->grid[i][j] == 0 && "newSudoku should initialize grid at 0");
        }
    }

    freeSudoku(s);
    printf("Passed.\n");
}

void testPlaceDigit(){
    printf("Running placeDigit() tests... ");

    int expected = 7;
    sudoku *s = newSudoku();

    assert(s->grid[5][5] == 0 && "Grid should be empty.");
    placeDigit(s, expected, 5, 5);
    assert(s->grid[5][5] == expected && "Expected 5 after placing digit.");
    s->mask[3][8] = true;
    placeDigit(s, expected, 3, 8);
    assert(s->grid[3][8] == 0 && "placeDigit should not replace digit that is masked.");
    placeDigit(s, 0, 5, 5);
    assert(s->grid[5][5] == expected && "placeDigit should not insert number below 1.");
    placeDigit(s, 15, 1, 1);
    assert(s->grid[1][1] == 0 && "placeDigit should not insert number greater than 9.");

    placeDigit(s, 1, 42, 0); //placing digits outside the grid should not crash.
    placeDigit(s, 1, 0, 17); //placing digits outside the grid should not crash.
    placeDigit(s, 1, -1, 0); //placing digits outside the grid should not crash.
    placeDigit(s, 1, 0, -1); //placing digits outside the grid should not crash.
    placeDigit(NULL, 1, 0, 0); //placing digits in NULL should not crash.

    freeSudoku(s);
    printf("Passed.\n");
}

void testPlaceHint(){
    printf("Testing placeHint()... ");

    int expected = 7;
    sudoku *s = newSudoku();

    assert(s->grid[5][5] == 0 && "Solution should be empty.");
    assert(s->mask[5][5] == false && "Mask should be empty.");
    placeHint(s, expected, 5, 5);
    assert(s->grid[5][5] == expected && "Expected 5 after placing hint.");
    assert(s->mask[5][5] == true && "Expected true after placing hint.");
    placeHint(s, 0, 5, 5);
    assert(s->grid[5][5] == expected && "placeHint should not insert number below 1.");
    placeHint(s, 15, 1, 1);
    assert(s->grid[1][1] == 0 && "placeHint should not insert number greater than 9.");

    placeHint(s, 1, 42, 0); //placing hints outside the grid should not crash.
    placeHint(s, 1, 0, 17); //placing hints outside the grid should not crash.
    placeHint(s, 1, -1, 0); //placing hints outside the grid should not crash.
    placeHint(s, 1, 0, -1); //placing hints outside the grid should not crash.
    placeHint(NULL, 1, 0, 0); //placing hints in NULL should not crash.

    printf("Passed.\n");
}

void allSudokuTests(){
    printf("Running all sudoku tests...`\n");

    testNewSudoku();
    testPlaceDigit();
    testPlaceHint();

    printf("All sudoku tests passed.`\n");
}

#endif //SUDOKU_SOLVER_SUDOKU_TEST_H
