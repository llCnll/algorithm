#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define MAX 0x3f3f3f3f

int jump(int* nums, int numsSize){
    int * dp = (int*)calloc(numsSize, sizeof(int*));

    for (int i = 1; i < numsSize; ++i) dp[i] = MAX;

    for (int i = 0; i < numsSize-1; ++i) {
        for (int j = 1; j <= nums[i] && (i+j) < numsSize; ++j) {
            dp[i+j] = min(dp[i] + 1, dp[i+j]);
        }
    }

    for (int i = 1; i < numsSize; ++i) printf("%d ", dp[i]);

    int ans = dp[numsSize-1];
    free(dp);

    return ans;
}

int main() {

    int nums[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};

    printf("%d\n", jump(nums, 15));

    return 0;
}

