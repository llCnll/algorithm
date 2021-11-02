#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int lengthOfLIS(int* nums, int numsSize){
    int * dp = (int*)calloc(numsSize, sizeof(int));
    int result = 0;

    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            result = max(dp[i], result);
        }
    }

    return result + 1;
}

int main() {

    int nums[] = {10,9,2,5,3,7,101,18};

    printf("%d\n", lengthOfLIS(nums, 8));

    return 0;
}

