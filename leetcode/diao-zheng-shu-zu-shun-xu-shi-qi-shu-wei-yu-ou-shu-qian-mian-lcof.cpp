#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int odd(int num) {
    return 0 == (num % 2);
}

int* exchange(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        if (!odd(nums[left])) {
            left ++;
            continue;
        }
        if (odd(nums[right])) {
            right --;
            continue;
        }
        nums[left] = nums[left] + nums[right];
        nums[right] = nums[left] - nums[right];
        nums[left] = nums[left] - nums[right];
    }
    return nums;
}

int main() {

    int arr[] = {1, 3, 5, 7};

    int returnSize = 0;
    exchange(arr, 4, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
