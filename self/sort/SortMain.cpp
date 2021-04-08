#include <stdio.h>

#include "SortTools.h"

#define MAX 100000

int main() {

    int arr1[MAX];
    int arr2[MAX];

    GetRandOrderArray(arr1, MAX, 0, 100000);
    CopyArray(arr2, arr1, MAX);

    printf("%d\t%d\t%d\t\n", arr1[0], arr1[1000], arr1[10000]);
    printf("%d\t%d\t%d\t\n", arr2[0], arr2[1000], arr2[10000]);

    return 0;
}
