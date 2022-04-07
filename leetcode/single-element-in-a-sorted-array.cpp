#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool singleNumber(int * nums, int index, int numsSize) {
    if (numsSize == 1) {
        return true;
    }
    if (index == 0) {
        return nums[index] != nums[index+1];
    } else if (index == numsSize-1) {
        return nums[index] != nums[index-1];
    } else {
        return nums[index-1] != nums[index] && nums[index] != nums[index+1];
    }
}

int singleNonDuplicate(int* nums, int numsSize){
    // n为偶数且n+1 相等, 则找右区间. 反之左区间.
    // 相邻元素不相等, 则返回当前下标

    int start = 0, end = numsSize-1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        if (singleNumber(nums, mid, numsSize)) {
            return nums[mid];
        } else if ((0 == mid%2 && nums[mid] == nums[mid+1]) || (1 == mid%2 && nums[mid] == nums[mid-1])) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {

    int nums[] = {1,2, 2,3,3,4,4,8,8};
    int numsSize = 9;

    printf("%d\n", singleNonDuplicate(nums, numsSize));

    return 0;
}

