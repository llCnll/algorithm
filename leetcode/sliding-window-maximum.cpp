#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize-k+1;
    int * ans = (int*)calloc(*returnSize, sizeof(int));

    /// value 为 下标
    int * queue = (int*)calloc(numsSize+10, sizeof(int));
    int start = 0;
    int end = 0;

    for (int i = 0; i < k; ++i) {
        while (start < end && nums[queue[end-1]] < nums[i]) {
            end --;
        }
        queue[end++] = i;
    }
    ans[0] = nums[queue[start]];

    for (int i = 1; i < *returnSize; ++i) {
        while (start < end && queue[start] < i) {
            start++;
        }
        while (start < end && nums[queue[end-1]] < nums[i+k-1]) {
            end --;
        }
        queue[end++] = i+k-1;

        ans[i] = nums[queue[start]];
    }
    free(queue);
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

