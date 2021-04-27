#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numWays(int n) {

    int a, b, c;
    a = 1; b = 2, c = a+b;
    if (n == 0 || n == 1) {
        return 1;
    }else if (n == 2) {
        return 2;
    }
    for (int i = 3; i < n; ++i) {
        a = b % 1000000007;
        b = c % 1000000007;
        c = (a+b) % 1000000007;
    }

    return c;
}

int main() {

    printf("%d\n", numWays(1));
    printf("%d\n", numWays(2));
    printf("%d\n", numWays(3));
    printf("%d\n", numWays(4));
    printf("%d\n", numWays(5));
    printf("%d\n", numWays(7));
    printf("%d\n", numWays(20));
    printf("%d\n", numWays(44));
    printf("%d\n", numWays(45));

    return 0;
}
