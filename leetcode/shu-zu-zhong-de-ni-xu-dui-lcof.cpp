#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count = 0;

void __MergeSort(int * arr, int left, int right, int * temp) {
    if (left >= right) {
        return;
    }

    int mid = (left+right) / 2;
    __MergeSort(arr, left, mid, temp);
    __MergeSort(arr, mid+1, right, temp);

    memcpy(temp+left, arr+left, (right-left+1) * sizeof(int));

    int i = left, j = mid+1;
    int index = left;

    while(i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            arr[index] = temp[i];
            i++;
        } else {
            arr[index] = temp[j];
            count += mid-i+1;
            j++;
        }
        index++;
    }
    // 拷贝剩余j之后的元素
    if (i == mid+1) {
        for (; j <= right; ++j) {
            arr[index++] = temp[j];
        }
    }
    // 拷贝i之后的元素
    if(j == right+1) {
        for (; i <= mid; ++i) {
            arr[index++] = temp[i];
        }
    }
}

void MergeSort(int * arr, int size) {
    int * arr2 = (int*)calloc(size, sizeof(int));
    __MergeSort(arr, 0, size-1, arr2);
    free(arr2);
}

int reversePairs(int* nums, int numsSize){
    count = 0;

    MergeSort(nums, numsSize);

    return count;
}

int main() {

    int arr[] = {7, 5, 6, 4};

    printf("%d\n", reversePairs(arr, 4));

    for (int i = 0; i < 4; ++i) {
        printf("%d\t", arr[i]);
    }
    putchar('\n');

    return 0;
}
