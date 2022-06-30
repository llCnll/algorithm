#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int * left = (int*)malloc(sizeof(int) * numsSize);
    int * right = (int*)malloc(sizeof(int) * numsSize);
    int * ans = (int*)malloc(sizeof(int) * numsSize);

    left[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        left[i] = nums[i] * left[i-1];
    }

    right[numsSize-1] = nums[numsSize-1];
    for (int i = numsSize-2; i >= 0; --i) {
        right[i] = nums[i] * right[i+1];
    }

    for (int i = 0; i < numsSize; ++i) {
        ans[i] = (i-1 < 0 ? 1 : left[i-1]) * (i+1>=numsSize ? 1 : right[i+1]);
    }

    *returnSize = numsSize;

    free(left);
    free(right);
    return ans;
}

int main() {
    int arr[] = {1,2,3,4};
    int numsSize = 4;
    int returnSize = 0;

    int * ans = productExceptSelf(arr, numsSize, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}

