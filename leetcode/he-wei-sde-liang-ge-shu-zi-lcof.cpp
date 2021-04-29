#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinarySearch(int * nums, int left, int right, int target) {
    if (left > right) {
        return 0;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if(nums[mid] > target) {
        return BinarySearch(nums, left, mid-1, target);
    }
    if(nums[mid] < target) {
        return BinarySearch(nums, mid+1, right, target);
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int * result = (int*)calloc(*returnSize, sizeof(int));
    for (int i = 0; i < numsSize && nums[i] <= target/2; ++i) {
        int index = BinarySearch(nums, i+1, numsSize-1, target-nums[i]);
        if (index > i) {
            result[0] = nums[i];
            result[1] = nums[index];
            break;
        }
    }
    return result;
}

int main() {

    int arr[] = {2, 7, 11, 15};

    int returnSize = 0;
    int * result = twoSum(arr, 4, 9, &returnSize);

    printf("%d, %d\n", result[0], result[1]);

    return 0;
}

