#include "solver.h"

int main(){
    sudoku *s = newSudoku();

    addAllHints(s);
    if(!solve(s, 0, 0))
        printf("No solution exists.\n");
    else
        printSudoku(*s);

    freeSudoku(s);
    return 0;
}