#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int * arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int position(int * arr, int left, int right) {
    int dest = arr[left];
    int dest_index = left;

    left ++;
    while (left <= right) {
        if (arr[left] < dest) {
            left++;
            continue;
        }
        if (arr[right] > dest) {
            right --;
            continue;
        }
        swap(arr, left, right);
        left++, right--;
    }
    swap(arr, right, dest_index);
    return right;
}

void quick_sort(int * arr, int k, int left, int right) {
    if (left >= right) {
        return ;
    }
    int pos = position(arr, left, right);

    if (pos+1 == k) {
        return ;
    }

    if (pos > k) {
        quick_sort(arr, k, left, pos-1);
    }
    if (pos < k) {
        quick_sort(arr, k, pos+1, right);
    }
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    quick_sort(arr, k, 0, arrSize-1);
    *returnSize = k;
    return arr;
}

int main() {
    int arr[] = {1,3,5,7,2,4,6,8};
    int arrSize = 8;
    int k = 4;

    int returnSize = 0;

    int * ans = smallestK(arr, arrSize, k, &returnSize);

    for (int i = 0; i < returnSize; ++i)
        printf("%d\t", ans[i]);
    putchar('\n');

    return 0;
}

