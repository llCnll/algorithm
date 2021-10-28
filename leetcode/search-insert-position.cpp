#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int binarySearch(int * nums, int left, int right, int target) {
    if (left >= right) {
        return nums[left] >= target ? left : left +1;
    }
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] > target) {
        return binarySearch(nums, left, mid, target);
    } else {
        return binarySearch(nums, mid+1, right, target);
    }
}

int searchInsert(int* nums, int numsSize, int target){
    return binarySearch(nums, 0, numsSize-1, target);
}

int main() {

    int nums[] = {1, 3, 5, 6};

    printf("%d\n", searchInsert(nums, 4, 2));

    return 0;
}

