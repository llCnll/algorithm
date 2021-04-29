#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize){

    int maxSum =  nums[0];

    for(int i = 1; i < numsSize; ++i) {
        if(nums[i-1] + nums[i] > nums[i]) {
            nums[i] = nums[i-1] + nums[i];
        } else {
            nums[i] = nums[i];
        }
        maxSum = max(nums[i], maxSum);
    }

    return maxSum;
}

int main() {

    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};

    printf("%d\n", maxSubArray(arr, 9));

    return 0;
}

