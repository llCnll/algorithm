#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isStraight(int* nums, int numsSize){
    int * count = (int*)calloc(14, sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        count[nums[i]]++;
    }

    int start = 0;
    int end = 0;
    int flag = 1;
    for (int i = 1; i < 14; ++i) {
        if (count[i] > 1) {
            return 0;
        }
        if (count[i] == 1 && flag) {
            start = i;
            flag = 0;
        }
        if (count[i] == 1 && !flag) {
            end = i;
        }
    }
    int king = count[0];
    free(count);

    return end - start - king <= 4;
}

int main() {

    int nums[] = {1, 2, 3, 4, 5};

    printf("%d\n", isStraight(nums, 5));

    return 0;
}

