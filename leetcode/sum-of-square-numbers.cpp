#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool judgeSquareSum(int c){
    int max = (int)sqrt(c / 2);
    int temp;
    int b;

    for (int a = 0; a <= max; ++a) {
        temp = c;
        temp -= a*a;
        b = (int)sqrt(temp);
        if (b*b == temp) {
            // printf("a = %d, b = %d\n", a, b);
            return true;
        }
    }
    return false;
}

int main() {

    printf("%d\n", judgeSquareSum(100));

    return 0;
}
