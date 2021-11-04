#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int ansIndex = 0;

int computeSize(int n) {
    int count = 1;
    for (int i = 2; i <= n; ++i) {
        count *= i;
    }
    return count;
}

void __permute(int ** ans, int * nums, int * vis, int * temp, int numsSize, int currentIndex) {
    if (currentIndex == numsSize) {
        memcpy(ans[ansIndex++], temp, sizeof(int) * numsSize);
        return ;
    }
    for (int i = 0; i < numsSize; ++i) {
        if (vis[i] == 0) {
            vis[i] = 1;
            temp[currentIndex] = nums[i];
            __permute(ans, nums, vis, temp, numsSize, currentIndex+1);
            vis[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    ansIndex = 0;
    *returnSize = computeSize(numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int ** ans = (int**)malloc(sizeof(int*) * (*returnSize));

    for (int i = 0; i < *returnSize; ++i) {
        ans[i] = (int*)calloc(numsSize, sizeof(int));
    }

    int * vis = (int*)calloc(numsSize, sizeof(int));
    int * temp = (int*)calloc(numsSize, sizeof(int));

    __permute(ans, nums, vis, temp, numsSize, 0);

    return ans;
}

int main() {

    int nums[] = {1, 2, 3, 4};

    int returnSize;
    int * returnColnumSizes;

    int ** ans = permute(nums, 4, &returnSize, &returnColnumSizes);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColnumSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

