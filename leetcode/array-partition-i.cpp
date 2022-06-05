#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int comp(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int ans = 0;
    for (int i = 0; i < numsSize; i+=2) {
        ans += nums[i];
    }
    return ans;
}

int main() {

    int nums[] = {1,4,3,2};
    printf("%d\n", arrayPairSum(nums, 4));

    return 0;
}

