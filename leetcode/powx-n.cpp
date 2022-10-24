#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double myPow(double x, long n){
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n < 0) {
        n = -n;
        x = 1/x;
    }
    return n%2 == 1 ? x*myPow(x*x, n/2) : myPow(x*x, n/2);
}

double myPow_2(double x, int n){
    if (0 == n) {
        return 1;
    }
    long b = (long)n;
    double res = 1.0;
    if (b < 0) {
        x = 1/x;
        b = -b;
    }
    while (b > 0) {
        if ((b&1) == 1) {
            res *= x;
        }
        x *= x;
        b >>= 1;
    }
    return res;
}

int main() {

    printf("%lf\n", myPow(2.0, 10));
    printf("%lf\n", myPow(2.0, 0));
    printf("%lf\n", myPow(2.1, 3));
    printf("%lf\n", myPow(2.0, -2));
    printf("%lf\n", myPow(34.00515, -3));

    return 0;
}

