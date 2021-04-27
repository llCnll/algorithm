#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int* nums, int numsSize){
    for (int i = 0; i < numsSize-1; ++i) {
        if (nums[i] > nums[i+1]) {
            return nums[i+1];
        }
    }
    return nums[0];
}

int main() {

    int arr[] = {3, 4, 5, 1, 2};
    printf("%d\n", findMin(arr, 5));

    int arr2[] = {2, 2, 2, 0, 1};
    printf("%d\n", findMin(arr2, 5));

    return 0;
}
