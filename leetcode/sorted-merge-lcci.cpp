#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void merge(int* A, int ASize, int m, int* B, int BSize, int n){

    int cur_index = m+n-1;
    int a_index = m-1;
    int b_index = n-1;

    while (a_index >= 0 && b_index >= 0) {
        if (A[a_index] > B[b_index]) {
            A[cur_index--] = A[a_index--];
        } else {
            A[cur_index--] = B[b_index--];
        }
    }

    while (a_index >= 0) {
        A[cur_index--] = A[a_index--];
    }

    while (b_index >= 0) {
        A[cur_index--] = B[b_index--];
    }

    return ;
}

int main() {

    int a[] = {1,2,3,0,0,0,0};
    int b[] = {1,2,5,6};

    merge(a, 3, 3, b, 4,4);

    for (int i = 0; i < 7; ++i) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    return 0;
}

