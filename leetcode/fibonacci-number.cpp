#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c = 1;
    for (int i = 2; i <= n; ++i) {
        c = a+b;
        a = b, b = c;
    }
    return c;
}

int main() {

    printf("%d\n", fib(2));
    printf("%d\n", fib(3));
    printf("%d\n", fib(4));

    return 0;
}

