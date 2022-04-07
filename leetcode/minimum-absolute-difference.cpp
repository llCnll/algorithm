#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr, arrSize, sizeof(int), comp);

    int min_difference = 0x3f3f3f;
    int min_count = 0;

    for (int i = arrSize-1; i > 0 ; --i) {
        if ((arr[i] - arr[i-1]) < min_difference) {
            min_difference = arr[i] - arr[i-1];
            min_count = 1;
        } else if ((arr[i] - arr[i-1]) == min_difference) {
            min_count ++;
        }
    }

    int ** ans = (int**)malloc(sizeof(int*) * min_count);
    *returnColumnSizes = (int*)calloc(sizeof(int), min_count);
    int index = 0;
    for (int i = 0; i < arrSize-1; ++i) {
        if (arr[i+1] - arr[i] == min_difference) {
            (*returnColumnSizes)[index] = 2;
            ans[index] = (int*)calloc(2, sizeof(int));
            ans[index][0] = arr[i], ans[index][1] = arr[i+1];
            index++;
        }
    }

    *returnSize = min_count;
    return ans;
}

int main() {

    int arr[] = {4,2,1,3};
    int arrSize = 4;

    int returnSize = 0;
    int * returnColumnSizes;

    int ** ans = minimumAbsDifference(arr, arrSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

