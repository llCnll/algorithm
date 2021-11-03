#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int removeDuplicates(int* nums, int numsSize){
    // 如果重复是否可删除
    bool flag = false;
    int rm_count = 0;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i-1]) {
            if (flag) {
                rm_count ++;
            } else {
                flag = true;
            }
        } else {
            flag = false;
        }
        nums[i-rm_count] = nums[i];
    }

    return numsSize - rm_count;
}

int main() {
    int nums[] = {1,1,1,2,2,3,3,3};

    int size = removeDuplicates(nums, 8);

    for (int i = 0; i < size; ++i) {
        printf("%d ", nums[i]);
    }
    putchar('\n');

    return 0;
}

