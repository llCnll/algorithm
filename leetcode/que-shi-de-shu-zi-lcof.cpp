#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int missingNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}

int main() {

    int arr[] = {0,1,2,3,4,5,6,7,9};

    printf("%d\n", missingNumber(arr, 9));

    return 0;
}
