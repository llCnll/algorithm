#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* printNumbers(int n, int* returnSize){
    *returnSize = (int) (pow(10, n) - 1);
    int * arr = (int *)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        arr[i] = i+1;
    }
    return arr;
}

int main() {

    int returenSize = 0;

    int * arr = printNumbers(1, &returenSize);
    for (int i = 0; i < returenSize; ++i) {
        printf("%d\t", arr[i]);
    }
    free(arr);

    return 0;
}
