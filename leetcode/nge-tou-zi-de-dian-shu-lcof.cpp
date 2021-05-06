#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double* dicesProbability(int n, int* returnSize){
    *returnSize = 5*n + 1;
    double arr[20][121] = {0.0};
    double * result = (double*)calloc(*returnSize, sizeof(double));

    for (int i = 1; i <= 6; ++i) {
        arr[1][i] = 1 / 6.0;
    }
    for (int i = 2; i <= n; ++i) {
        int start = i-1;
        int end = 6*start;
        // 上一行
        for (int j = start; j <= end; ++j) {
            for (int k = 1; k <= 6; ++k) {
                arr[i][j+k] += arr[i-1][j] / 6.0;
            }
        }
    }
    for (int i = n, index = 0; i < *returnSize + n; ++i) {
        result[index++] = arr[n][i];
    }
    return result;
}

int main() {
    int returnSize = 0;
    double * result = dicesProbability(3, &returnSize);
    for(int i = 0 ; i < returnSize; ++i) {
        printf("%lf\t", result[i]);
    }
    return 0;
}

