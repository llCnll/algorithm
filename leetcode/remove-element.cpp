#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int removeElement(int* nums, int numsSize, int val){
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == val) {
            while (numsSize-1 > i && nums[numsSize-1] == val) {
                numsSize --;
            }
            nums[i] = nums[numsSize-1];
            numsSize --;
        }
    }

    return numsSize;
}

int main() {

    int arr[] = {1};

    int returnSize = removeElement(arr, 1, 1);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

