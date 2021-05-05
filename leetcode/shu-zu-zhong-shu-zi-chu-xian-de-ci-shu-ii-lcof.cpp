#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int* nums, int numsSize){
    unsigned int result = 0;
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for (int j = 0; j < numsSize; ++j) {
            if ((nums[j] & ((unsigned int) 1 << i)) != 0) {
                count ++;
            }
        }
        if (count%3 == 1) {
            result |= 1 << i;
        }
    }
    return result;
}

int main() {

    int nums[] = {3, 4, 3, 3};
    printf("%d\n", singleNumber(nums, 4));
    return 0;
}

