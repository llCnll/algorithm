#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool isPowerOfTwo(int n){
    long start = 1;
    while (start <= n) {
        if ((n & start) == start) {
            if (n == start) return true;
            else return false;
        }
        start <<= 1;
    }
    return false;
}

int main() {
    printf("%d\n", isPowerOfTwo(1));
    printf("%d\n", isPowerOfTwo(16));
    printf("%d\n", isPowerOfTwo(5));
    printf("%d\n", isPowerOfTwo(1024));
    return 0;
}

