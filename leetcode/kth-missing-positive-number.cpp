#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findKthPositive(int* arr, int arrSize, int k){

    int current = 1;

    for (int i = 0; i < arrSize; current++) {
        if (arr[i] == current) {
            i++;
            continue;
        }
        k--;
        if (k == 0) {
            return current;
        }
    }
    // 说明超过限制
    current += k-1;
    return current;
}

int main() {

    int arr[] = {2, 3, 4, 7, 11};

    printf("%d\n", findKthPositive(arr, 6, 5));

    int arr2[] = {1, 2, 3, 4};

    printf("%d\n", findKthPositive(arr2, 4, 2));

    return 0;
}
