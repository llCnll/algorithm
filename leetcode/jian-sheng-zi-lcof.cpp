#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cuttingRope(int n){

    if(n == 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    }

    if (1 == n%3) {
        return (int)(pow(3, (n/3)-1) * 4);
    } else if(2 == n%3) {
        return (int)(pow(3, n/3) * 2);
    } else {
        return (int)pow(3, n/3);
    }
}

int main() {

    printf("%d\n", cuttingRope(2));
    printf("%d\n", cuttingRope(10));
    printf("%d\n", cuttingRope(9));
    printf("%d\n", cuttingRope(8));

    return 0;
}

