#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int * ans = (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int front = 0, tail = numsSize - 1;

    int temp;
    for (int i = numsSize-1; i >= 0; --i) {
        if (abs(nums[front]) > abs(nums[tail])) {
            temp = nums[front++];
        } else {
            temp = nums[tail--];
        }
        ans[i] = temp * temp;
    }
    return ans;
}

int main() {

    int nums[] = {-4,-1,0,3,10};
    int numsSize = 5;
    int returnSize;

    int * ans = sortedSquares(nums, numsSize, &returnSize);

    for (int i = 0; i < numsSize; ++i) {
        printf("%d\t", ans[i]);
    }
    free(ans);

    return 0;
}

