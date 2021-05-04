#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int maxValue(int** grid, int gridSize, int* gridColSize){
    int i, j;
    for (i = 1; i < gridSize; ++i) {
        grid[i][0] += grid[i-1][0];
    }
    for (j = 1; j < gridColSize[0]; ++j) {
        grid[0][j] += grid[0][j-1];
    }

    for (int i = 1; i < gridSize; ++i) {
        for (int j = 1; j < gridColSize[0]; ++j) {
            grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
        }
    }
    return grid[gridSize-1][gridColSize[0]-1];
}

int main() {

    int ** arr = (int**)malloc(sizeof(int*) * 3);

    arr[0] = (int*)calloc(3, sizeof(int));
    arr[1] = (int*)calloc(3, sizeof(int));
    arr[2] = (int*)calloc(3, sizeof(int));

    arr[0][0] = 1, arr[0][1] = 3, arr[0][2] = 1;
    arr[1][0] = 1, arr[1][1] = 5, arr[1][2] = 1;
    arr[2][0] = 4, arr[2][1] = 2, arr[2][2] = 1;

    int colSize[] = {3, 3, 3};
    printf("%d\n", maxValue(arr, 3, colSize));

    return 0;
}

