#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int nthUglyNumber(int n){
    int * arr = (int*)calloc(n+1, sizeof(int));
    arr[0] = 1;
    int current_index = 1;
    int a = 0, b = 0, c = 0;

    int temp_a, temp_b, temp_c;
    int temp_min;
    for (int i = 0 ; i < n; ++i) {
        temp_a = arr[a] * 2;
        temp_b = arr[b] * 3;
        temp_c = arr[c] * 5;
        temp_min = min(temp_a, min(temp_b, temp_c));
        arr[current_index++] = temp_min;
        if (temp_a == temp_min) a++;
        if (temp_b == temp_min) b++;
        if (temp_c == temp_min) c++;
    }

    return arr[n-1];
}

int main() {

    printf("%d\n", nthUglyNumber(10));

    return 0;
}

