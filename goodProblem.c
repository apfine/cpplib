#include <stdio.h>

int isSafe(int grid[9][9], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int grid[9][9], int row, int col) {
    if (row == 9) {
        return 1; // Sudoku solved
    }

    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }

    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return 0; // No solution
}

int main() {
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    printf("\nThe initial sudoku : \n");
     for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    if (solveSudoku(grid, 0, 0)) {
        printf("Sudoku solved:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}