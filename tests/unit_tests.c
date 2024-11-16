#include "solver_test.h"
#include "sudoku_test.h"

void allTests(){
    printf("Running all tests...\n");
    allSudokuTests();
    allSolverTests();
    printf("All tests passed.\n");
}

int main(){
    allTests();
    return 0;
}