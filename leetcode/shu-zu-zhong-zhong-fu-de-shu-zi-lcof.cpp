#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findRepeatNumber(int* nums, int numsSize){
    int * bucket = (int*)malloc(sizeof(int) * numsSize);
    memset(bucket, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        bucket[nums[i]] ++;
        if (bucket[nums[i]] > 1) {
            return nums[i];
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 2};
    printf("%d\n", findRepeatNumber(nums, 7));
    return 0;
}
