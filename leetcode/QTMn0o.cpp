#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int subarraySum(int* nums, int numsSize, int k){
    if (numsSize == 0) return 0;

    int count = 0;

    for (int i = 1; i < numsSize; ++i) {
        nums[i] += nums[i-1];
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == k) count ++;
        for (int j = 0; j < i; ++j) {
            if (nums[i] - nums[j] == k) count ++;
        }
    }

    return count;
}

int main() {
    //int nums[20] = {1, 2, 1, 2, 1, 2};
    int nums[20] = {0, 0};

    printf("%d\n", subarraySum(nums, 2, 0));

    return 0;
}
