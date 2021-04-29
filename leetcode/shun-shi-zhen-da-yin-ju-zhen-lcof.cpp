#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void traverse(int ** matrix, int start_i, int start_j, int end_i, int end_j, int * result, int *index) {
    for (int j = start_j; j < end_j; ++j) {
        result[(*index)++] = matrix[start_i][j];
    }
    for (int i = start_i+1; i < end_i && end_j-1 >= start_j; ++i) {
        result[(*index)++] = matrix[i][end_j-1];
    }
    for (int j = end_j-1-1; j >= start_j && end_i-1 > start_i; --j) {
        result[(*index)++] = matrix[end_i-1][j];
    }
    for (int i = end_i-1-1; i >= start_i+1; --i) {
        result[(*index)++] = matrix[i][start_j];
    }
}

int* spiralOrder(int ** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = 0;
    if(matrixSize == 0) {
        return NULL;
    }
    for (int i = 0; i < matrixSize; ++i) {
        *returnSize += matrixColSize[i];
    }

    int * result = (int*)malloc(2 * sizeof(int) * *returnSize);
    int index = 0;

    int end_i = (matrixSize + 1) / 2;
    int end_j = (matrixColSize[0] + 1) / 2;

    for (int i = 0; i < end_i && i < end_j; ++i) {
        traverse(matrix, i, i, matrixSize - i, matrixColSize[0] - i, result, &index);
    }

    return result;
}

int main() {

    int ** arr = (int**)malloc(sizeof(int*) * 3);

    arr[0] = (int*)calloc(4, sizeof(int));
    arr[1] = (int*)calloc(4, sizeof(int));
    arr[2] = (int*)calloc(4, sizeof(int));


    int matrixColSize[] = {4, 4, 4};
    int returnSize = 0;
    int * result = spiralOrder(arr, 3, matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", result[i]);
    }

    return 0;
}

