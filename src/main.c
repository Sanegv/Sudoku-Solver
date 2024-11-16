#include "sudoku.h"

int main(){
    sudoku *s = newSudoku();

    printSudoku(*s);

    freeSudoku(s);
    return 0;
}