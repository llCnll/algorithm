#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Swap(int * arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int __Position(int * arr, int left, int right) {
    //Swap(arr, left, rand() % (right-left+1) + left);
    int pos = arr[left];
    int i = left+1;
    int j = right;

    while(true) {
        while(i <= right && arr[i] < pos) {
            i++;
        }
        while(j >= left+1 && arr[j] > pos) {
            j--;
        }
        if (i > j) {
            break;
        }
        Swap(arr, i, j);
        i++;
        j--;
    }
    Swap(arr, left, j);
    return j;
}

void __QuickSort(int * arr, int left, int right, int k) {
    if (left >= right || right < k-1 || left > k-1) {
        return;
    }
    int pos = __Position(arr, left, right);
    if (pos+1 == k) {
        return;
    }
    __QuickSort(arr, left, pos, k);
    __QuickSort(arr, pos+1, right, k);
}

void QuickSort(int* arr, int size, int k) {
    //srand(time(NULL));
    __QuickSort(arr, 0, size-1, k);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;

    QuickSort(arr, arrSize, k);

    return arr;
}

int main() {

    int arr[] = {32,41,21,29,7,53,97,76,71,53,53,53,72,53,53,14,22,53,67,53,53,53,54,98,53,46,53,53,62,53,76,20,60,53,31,53,53,53,95,27,53,53,53,53,36,59,40,53,53,64,53,53,53,21,53,51,53,53,2,53,53,53,53,53,50,53,53,53,23,88,3,53,61,19,53,68,53,35,42,53,53,48,34,54,53,75,53,53,50,44,92,41,71,53,53,82,53,53,14,53};

    int returnSize = 0;
    getLeastNumbers(arr, 99, 2, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
