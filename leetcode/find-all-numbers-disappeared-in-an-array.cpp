#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void swap(int * nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int * ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    int i = 0;
    while (i < numsSize) {
        if (nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
            swap(nums, i, nums[i]-1);
        } else i++;
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i+1) {
            ans[(*returnSize)++] = i+1;
        }
    }
    return ans;
}

int main() {

    int nums[] = {4,3,2,7,8,2,3,1};
    int numsSize = 8;
    int size = 0;

    int * ans = findDisappearedNumbers(nums, numsSize, &size);

    for (int i = 0; i < size; ++i) {
        printf("%d\t", ans[i]);
    }
    free(ans);

    return 0;
}

