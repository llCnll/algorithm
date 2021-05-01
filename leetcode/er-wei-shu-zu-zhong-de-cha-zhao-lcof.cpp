#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool search(int ** matrix, int i, int j, int row, int col, int target) {
    if (j < 0 || i >= row || j >= col || i < 0) {
        return false;
    }
    if (matrix[i][j] == target) {
        return true;
    }
    if (matrix[i][j] > target) {
        return search(matrix, i, j-1, row, col, target);
    }
    if (matrix[i][j] < target) {
        return search(matrix, i+1, j, row, col, target);
    }
    return false;
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0) {
        return false;
    }
    return search(matrix, 0, matrixColSize[0]-1, matrixSize, matrixColSize[0], target);
}

int main() {

    int ** arr = (int**)malloc(sizeof(int*) * 5);

    arr[0] = (int*)calloc(4, sizeof(int));
    arr[1] = (int*)calloc(4, sizeof(int));
    arr[2] = (int*)calloc(4, sizeof(int));
    arr[3] = (int*)calloc(4, sizeof(int));
    arr[4] = (int*)calloc(4, sizeof(int));

    arr[0][0] = 1, arr[0][1] = 4, arr[0][2] = 11, arr[0][3] = 15;
    arr[1][0] = 2, arr[1][1] = 5, arr[1][2] = 12, arr[1][3] = 19;
    arr[2][0] = 3, arr[2][1] = 6, arr[2][2] = 16, arr[2][3] = 22;
    arr[3][0] = 10, arr[3][1] = 13, arr[3][2] = 17, arr[3][3] = 24;
    arr[4][0] = 18, arr[4][1] = 21, arr[4][2] = 26, arr[4][3] = 30;

    int matrixColSize[] = {4, 4, 4, 4, 4};

    printf("%d\n", findNumberIn2DArray(arr, 5, matrixColSize, 5));

    return 0;
}

