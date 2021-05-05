#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* singleNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int * result = (int*)calloc(*returnSize, sizeof(int));
    int temp_result = 0;
    for (int i = 0 ; i < numsSize; ++i) {
        temp_result ^= nums[i];
    }
    int shift = 1;
    while ((temp_result & shift) == 0) {
        shift <<= 1;
    }
    for (int i = 0 ; i < numsSize; ++i) {
        if (nums[i] & shift) {
            result[0] ^= nums[i];
        } else {
            result[1] ^= nums[i];
        }
    }
    return result;
}

int main() {

    int arr[] = {1, 2, 5, 2};
    int returnSize = 0;

    int * result = singleNumbers(arr, 4, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", result[i]);
    }

    return 0;
}

