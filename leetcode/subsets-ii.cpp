#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* appendNum(int* old, int oldSize, int num) {
    int * ans = (int*)malloc(sizeof(int) * (oldSize+1));
    memcpy(ans, old, sizeof(int) * oldSize);
    ans[oldSize] = num;
    return ans;
}

int comp(const void * arg1, const void * arg2) {
    return *(int*)arg1 - *(int*)arg2;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (NULL == nums) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;
    int ** ans = (int **)malloc(sizeof(int*) * (int)pow(2, numsSize));
    *returnColumnSizes = (int*)calloc((int)pow(2, numsSize), sizeof(int));

    qsort(nums, numsSize, sizeof(int), comp);

    int count = 1;
    int start = 0;
    for (int i = 0; i < numsSize; ++i) {
        int count_tmp = 0;
        if (i > 0 && nums[i] == nums[i-1]) {
            // 添加上一次追加的位置开始,到最后.
            for (int k = start; k < count; ++k) {
                ans[count+count_tmp] = appendNum(ans[k], (*returnColumnSizes)[k], nums[i]);
                (*returnColumnSizes)[count+count_tmp] = (*returnColumnSizes)[k] + 1;
                count_tmp ++;
            }
            start = count;
            count += count_tmp;
            continue;
        }
        for (int j = 0; j < count; ++j) {
            ans[count+count_tmp] = appendNum(ans[j], (*returnColumnSizes)[j], nums[i]);
            (*returnColumnSizes)[count+count_tmp] = (*returnColumnSizes)[j] + 1;
            count_tmp ++;
        }
        start = count;
        count += count_tmp;
    }
    *returnSize = count;
    return ans;
}

int main() {

    int nums[] = {1,2,2};
    int numsSize = 3;
    int returnSize = 0;
    int * returnColumnSizes;

    int ** ans = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
