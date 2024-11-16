#include "solver.h"

bool solve(sudoku* s, int square, int tile){
//    for(int i = square; i < 9; i++){
//        for(int j = tile; j < 9; j++){
//            if(s->mask[i][j])
//                continue;
//            for(int digit = 1; digit < 9; digit++){
//                placeDigit(s, digit, i, j);
//                if(!checkPlacement(s))
//                    continue;
//                int y = tile+1;
//                int x = square + tile/10;
//                y %= 9;
//                printSudoku(*s);
//                if(solve(s, x, y) || sudokuFull(s))
//                    return true;
//            }
//            s->grid[square][tile] = 0;
//        }
//    }
    return false;
}

bool checkPlacement(sudoku* s){
    return checkSquares(s) && checkRows(s) && checkColumns(s);
}

bool checkSquares(sudoku *s){
    for(int i = 0; i < 9; i++){
        int count[9] = {0};
        for(int j = 0; j < 9; j++){
            int x = i;
            int y = j;
            int value = s->grid[x][y];
            if(!value)
                continue;
            if((++count[value-1]) > 1)
                return false;
        }
    }
    return true;
}

bool checkRows(sudoku *s){
    for(int i = 0; i < 9; i++){
        int count[9] = {0};
        for(int j = 0; j < 9; j++){
            int x = j/3 + (i/3)*3;
            int y = j%3 + (i%3)*3;
            int value = s->grid[x][y];
            if(!value)
                continue;
            if((++count[value-1]) > 1)
                return false;
        }
    }
    return true;
}

bool checkColumns(sudoku *s){
    for(int i = 0; i < 9; i++){
        int count[9] = {0};
        for(int j = 0; j < 9; j++){
            int x = (i/3) + (j/3)*3;
            int y = (j%3)*3 + i%3;
            int value = s->grid[x][y];
            if(!value)
                continue;
            if((++count[value-1]) > 1)
                return false;
        }
    }
    return true;
}

void addAllHints(sudoku* s){
    int numberOfHints = -1;
    while(numberOfHints < 0 || numberOfHints > 81){
        printf("How many hints do you have?\n>");
        scanf("%d", &numberOfHints);
    }

    for(int i = 0; i < numberOfHints; i++){
        int hint = 0, square = -1, tile = -1;
        while(square < 0 || square > 8) {
            printf("In which square is the hint? (0 to 8)\n>");
            scanf("%d", &square);
        }
        while(tile < 0 || tile > 8) {
            printf("In which tile of the square is the hint? (0 to 8)\n>");
            scanf("%d", &tile);
        }
        while(hint < 1 || hint > 9) {
            printf("What is the value of the hint? (1 to 9)\n>");
            scanf("%d", &hint);
        }
        placeHint(s, hint, square, tile);
        printSudoku(*s);
    }
}