#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max(a, b) (a) > (b) ? (a) : (b)

bool canJump(int* nums, int numsSize){
    int max_index = 0;

    for (int i = 0; i < numsSize; ++i) {
        max_index = max_index > (nums[i] + i) ? max_index : (nums[i] + i);

        if (max_index == i) return false;

        if (max_index >= numsSize) return true;
    }

    return max_index == numsSize-1;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    printf("%d\n", canJump(nums, 5));

    return 0;
}

