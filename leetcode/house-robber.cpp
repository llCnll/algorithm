#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numssize){
    if (numssize >= 2) {
        nums[1] = max(nums[1], nums[0]);
    }
    // i-1的值 与 i-2 + i 的值比较大小
    for (int i = 2; i < numssize; ++i) {
        nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
    }

    return nums[numssize-1];
}

int main() {

    int nums[] = {1, 2, 3, 1};

    printf("%d\n", rob(nums, 4));

    return 0;
}

