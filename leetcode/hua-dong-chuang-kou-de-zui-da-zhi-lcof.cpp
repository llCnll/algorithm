#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMaxIndex(int * nums, int start, int end) {
    int max_index = start;
    int max_val = nums[max_index];
    for (int i = start+1; i < end; ++i) {
        if (max_val < nums[i]) {
            max_index = i;
            max_val = nums[i];
        }
    }
    return max_index;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize-k+1;
    int * ans = (int*)calloc(*returnSize, sizeof(int));

    int max_index = findMaxIndex(nums, 0, k);
    ans[0] = nums[max_index];

    for (int i = 1; i < *returnSize; ++i) {
        if (max_index < i) max_index = findMaxIndex(nums, i, i+k);
        if (nums[max_index] < nums[i+k-1]) max_index = i+k-1;
        ans[i] = nums[max_index];
    }
    return ans;
}

int main() {

    int nums[] = {1,3,-1,-3,5,3,6,7};

    int returnSize = 0;
    int * result = maxSlidingWindow(nums, 8, 3, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", result[i]);
    }

    free(result);

    return 0;
}

