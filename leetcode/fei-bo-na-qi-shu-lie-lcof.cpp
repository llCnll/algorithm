#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int n) {

    int a, b, c;
    a = 0; b = 1, c = a+b;
    if (n == 0) {
        return 0;
    }else if (n == 1) {
        return 1;
    }
    for (int i = 2; i < n; ++i) {
        a = b % 1000000007;
        b = c % 1000000007;
        c = (a+b) % 1000000007;
    }

    return c;
}

int main() {

    printf("%d\n", fib(0));
    printf("%d\n", fib(1));
    printf("%d\n", fib(2));
    printf("%d\n", fib(3));
    printf("%d\n", fib(4));
    printf("%d\n", fib(5));
    printf("%d\n", fib(20));
    printf("%d\n", fib(44));
    printf("%d\n", fib(45));

    return 0;
}
