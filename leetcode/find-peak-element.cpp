#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int binaryselect(int * nums, int left, int right, int size) {
    if (left >= right) {
        return left;
    }
    int mid = (left + right) / 2;
    if ((mid-1 < 0 || nums[mid] > nums[mid-1]) && (mid+1 > size || nums[mid] > nums[mid+1])) return mid;

    if (nums[mid] > nums[mid+1]) {
        return binaryselect(nums, left, mid, size);
    } else {
        return binaryselect(nums, mid+1, right, size);
    }
}

int findPeakElement(int* nums, int numssize){
    return binaryselect(nums, 0, numssize-1, numssize-1);
}

int main() {

    int nums[] = {2,1};

    printf("%d\n", findPeakElement(nums, 2));

    return 0;
}

