#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minArray(int* numbers, int numbersSize){
    for (int i = 0; i < numbersSize-1; ++i) {
        if (numbers[i] > numbers[i+1]) {
            return numbers[i+1];
        }
    }
    return numbers[0];
}

int main() {

    int arr[] = {3, 4, 5, 1, 2};
    printf("%d\n", minArray(arr, 5));

    int arr2[] = {2, 2, 2, 0, 1};
    printf("%d\n", minArray(arr2, 5));

    return 0;
}
