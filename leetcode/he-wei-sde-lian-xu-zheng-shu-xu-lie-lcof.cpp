#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int ** result = (int**)malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; ++i) {
        result[i] = (int*)calloc(1000, sizeof(int));
    }
    int start = 1;
    int end = 1;
    int sum = 1;
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);

    for (int i = 2; i <= (target+1) / 2; ++i) {
        sum += i;
        end ++;
        while (sum > target && start < end) {
            sum -= start;
            start++;
        }
        if (sum == target) {
            returnColumnSizes[0][*returnSize] = end-start+1;
            for (int k = 0; k <= end-start; ++k) {
                result[*returnSize][k] = k+start;
            }
            (*returnSize)++;
        }
    }
    return result;
}

int main() {

    int returnSize = 0;
    int * returnColumnSizes;
    int ** result = findContinuousSequence(15, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d\t", result[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
