#include "sudoku.h"

sudoku* newSudoku(){
    sudoku* result = malloc(sizeof (sudoku));
    if(result == NULL)
        return NULL;

    result->mask = malloc(9 * sizeof (bool*));
    if(result->mask == NULL)
        return NULL;

    result->grid = malloc(9 * sizeof (int *));
    if(result->grid == NULL)
        return NULL;

    result->solution = malloc(9 * sizeof (int*));
    if(result->solution == NULL)
        return NULL;

    for(int i = 0; i < 9; i++){
        result->mask[i] = calloc(9, sizeof (bool));
        if(result->mask[i] == NULL)
            return NULL;
        result->grid[i] = calloc(9, sizeof (int));
        if(result->grid[i] == NULL)
            return NULL;
        result->solution[i] = calloc(9, sizeof (int));
        if(result->solution[i] == NULL)
            return NULL;
    }

    return result;
}

void freeSudoku(sudoku* s){
    for(int i = 0; i < 9; i++){
        free(s->solution[i]);
        free(s->mask[i]);
        free(s->grid[i]);
    }
    free(s->mask);
    free(s->grid);
    free(s->solution);
    free(s);
}

void placeDigit(sudoku* s, int digit, int x, int y){
    if(digit < 1 || x < 0 || y < 0 || digit > 9 || x > 8 || y > 8 || s == NULL || s->mask[x][y])
        return;
    s->grid[x][y] = digit;
}

void placeHint(sudoku* s, int digit, int x, int y){
    if(digit < 1 || x < 0 || y < 0 || digit > 9 || x > 8 || y > 8 || s == NULL)
        return;
    s->solution[x][y] = digit;
    s->mask[x][y] = true;
}

bool compareDigitToSolution(sudoku* s, int x, int y){
    if(s == NULL || x < 0 || x > 8 || y > 8)
        return false;
    return s->grid[x][y] == s->solution[x][y];
}

void printSudoku(sudoku s){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int x = 3*(i/3) + j/3;
            int y = j%3 + (i%3)*3;
            if(j == 3 || j == 6)
                printf("| ");
            printf("%c ", s.mask[x][y] ? '0' + s.solution[x][y] : s.grid[x][y] != 0 ? '0' + s.grid[x][y] : '#');
        }
        printf("\n");
        if(i == 2 || i == 5)
            printf("---------------------\n");
    }
}