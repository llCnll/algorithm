#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define min(a,b) (a) < (b) ? (a) : (b)
#define MAX 10100

int minSubArrayLen(int target, int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int start = 0, end = -1;
    int sum = 0;
    int minLength = MAX;

    while (true) {
        if (start >= numsSize) return minLength;
        if (end >= numsSize-1 && sum < target) return minLength == MAX ? 0 : minLength;

        while (sum > target && start <= end) {
            minLength = min(minLength, end-start+1);
            sum -= nums[start++];
        }

        while (sum < target && end < numsSize-1)
            sum += nums[++end];

        if (sum >= target) {
            minLength = min(minLength, end-start+1);
            sum -= nums[start++];
        }
    }
    return minLength;
}

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = 6;
    int target = 7;

    printf("%d\n", minSubArrayLen(target, nums, numsSize));

    return 0;
}

