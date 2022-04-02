#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int a, int b){
    int flag = 1;
    if ((a < 0 && b <0) || (a > 0 && b > 0)) ;
    else flag = -1;
    a = a < 0? a: -a, b = b < 0? b: -b;

    if ( a > b ) return 0;

    int count = 1;
    int temp = b;

    while ( (flag > 0 && a < temp+b) || (flag < 0 && a < temp+b)) {
        if (flag > 0 && INT_MAX == count) return INT_MAX * flag;
        count ++;
        temp = count * b;
    }
    return count * flag;
}

int main() {

    printf("%d\n", divide(-2147483648, -1));

    return 0;
}
