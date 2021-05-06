#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeSum(int * arr, int left, int right) {
    if (left > right) {
        return 1;
    }
    if (left == right) {
        return arr[left];
    }
    if (right - left == 1) {
        return arr[left] * arr[right];
    }
    int mid = (left+right) / 2;
    return computeSum(arr, left, mid) * computeSum(arr, mid+1, right);
}

int* constructArr(int* arr, int size, int* returnSize){
    *returnSize = size;
    int * result = (int*)calloc(*returnSize, sizeof(int));
    int * temp1 = (int*)calloc(*returnSize+2, sizeof(int));
    int * temp2 = (int*)calloc(*returnSize+2, sizeof(int));

    temp1[0] = temp1[*returnSize + 1] = 1;
    temp2[0] = temp2[*returnSize + 1] = 1;

    for(int i = 1; i < size+1; ++i) {
        temp1[i] = temp1[i-1] * arr[i-1];
    }
    for (int i = size; i > 0; --i) {
        temp2[i] = temp2[i+1] * arr[i-1];
    }
    for (int i = 0 ; i < *returnSize; ++i) {
        result[i] = temp1[i] * temp2[i+2];
    }
    free(temp1);
    free(temp2);
    return result;
}

// 超时
int* constructArr2(int* arr, int size, int* returnSize){
    *returnSize = size;
    int sum = computeSum(arr, 0, size-1);
    int * result = (int*)calloc(*returnSize, sizeof(int));

    for(int i = 0; i < size; ++i) {
        result[i] = computeSum(arr, 0, i-1) * computeSum(arr, i+1, size-1);
    }
    return result;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    int returnSize = 0;
    int * result = constructArr(arr, size, &returnSize);

    for (int i = 0; i < size; ++i) {
        printf("%d\t", result[i]);
    }

    free(result);
    return 0;
}

