#ifndef SUDOKU_SOLVER_SOLVER_TEST_H
#define SUDOKU_SOLVER_SOLVER_TEST_H

#include <assert.h>
#include "solver.h"

void testSolve(){
    printf("Running all solve() tests... ");
    //TODO
    assert(false);
    printf("Passed.\n");
}

void testCheckPlacement(){
    printf("Running all checkPlacement() tests... ");
    //TODO
    assert(false);
    printf("Passed.\n");
}

void testCheckSquares(){
    printf("Running all checkSquares() tests... ");
    //TODO
    assert(false);
    printf("Passed.\n");
}

void testCheckRows(){
    printf("Running all checkRows() tests... ");
    //TODO
    assert(false);
    printf("Passed.\n");
}

void testCheckColumns(){
    printf("Running all checkColumns() tests... ");
    //TODO
    assert(false);
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
