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

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int * ans = (int *)calloc(numsSize/2, sizeof(int));
    int count = 0;

    int i = 0;

    while (i < numsSize) {
        if (nums[i]-1 != i && nums[i] != nums[nums[i]-1]) {
            swap(nums, i, nums[i]-1);
        } else i++;
    }

    for (i = 0; i < numsSize; ++i) {
        if (nums[i]-1 != i) {
            ans[count++] = nums[i];
        }
    }

    *returnSize = count;
    return ans;
}

int main() {

    int nums[] = {4,3,2,7,8,2,3,1};
    int numsSize = 8;
    int returnSize = 0;

    int * ans = findDuplicates(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; ++i) 
        printf("%d ", ans[i]);
    putchar('\n');

    return 0;
}

