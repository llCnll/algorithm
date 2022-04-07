#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int search(int* nums, int numsSize, int target){
    int start = 0, end = numsSize-1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {

    int nums[] = {-1,0,3,5,9,12};
    int numsSize= 6;
    int target = 10;

    printf("%d\n", search(nums, numsSize, target));

    return 0;
}

