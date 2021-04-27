#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs(int n) {

    int a, b, c;
    a = 1; b = 2, c = a+b;
    if (n == 0 || n == 1) {
        return 1;
    }else if (n == 2) {
        return 2;
    }
    for (int i = 3; i < n; ++i) {
        a = b;
        b = c;
        c = a+b;
    }

    return c;
}

int main() {

    printf("%d\n", climbStairs(1));
    printf("%d\n", climbStairs(2));
    printf("%d\n", climbStairs(3));
    printf("%d\n", climbStairs(4));
    printf("%d\n", climbStairs(5));
    printf("%d\n", climbStairs(7));
    printf("%d\n", climbStairs(20));
    printf("%d\n", climbStairs(44));
    printf("%d\n", climbStairs(45));

    return 0;
}
