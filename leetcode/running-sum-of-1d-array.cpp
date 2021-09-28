#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int * result = (int*)malloc(sizeof(int) * numsSize);
    memset(result, 0, sizeof(int)*numsSize);

    result[0] = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        result[i] = result[i-1] + nums[i];
    }

    return result;
}

int main() {

    int nums[] = {1, 2, 3, 4};
    int returnSize;

    int * result = runningSum(nums, 4, &returnSize);

    for (int i = 0; i < 4; ++i) {
        printf("%d\t", result[i]);
    }

    free(result);

    return 0;
}
