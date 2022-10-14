#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;

    int * nums = (int*)calloc(numRows+2, sizeof(int));
    nums[1] = 1;

    int ** ans = (int**)malloc(sizeof(int*) * numRows);
    ans[0] = (int*)calloc(1, sizeof(int));
    memcpy(ans[0], nums+1, sizeof(int) * 1);
    returnColumnSizes[0] = (int*)calloc(numRows, sizeof(int));
    returnColumnSizes[0][0] = 1;

    for (int i = 2; i <= numRows; ++i) {
        // update nums
        for (int j = (i+1)/2; j >= 1; --j) {
            nums[j] = nums[i-j+1] = nums[j]+nums[j-1];
        }
        // copy
        ans[i-1] = (int*)calloc(i, sizeof(int));
        memcpy(ans[i-1], nums+1, sizeof(int) * i);
        returnColumnSizes[0][i-1] = i;
    }
    return ans;
}


int main() {
    int size;
    int * colSize;
    int ** ans = generate(7, &size, &colSize);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < colSize[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

