#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* getRow(int rowIndex, int* returnSize){
    int * nums = (int*)calloc(rowIndex+3, sizeof(int));
    nums[1] = 1;
    for (int i = 2; i <= rowIndex+1; ++i) {
        for (int j = (i+1)/2; j >= 1; --j) {
            nums[j] = nums[i-j+1] = nums[j]+nums[j-1];
        }
    }
    *returnSize = rowIndex+1;
    return nums+1;
}

int main() {
    int size;
    int * ans = getRow(3, &size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", ans[i]);
    }
    putchar('\n');

    return 0;
}

