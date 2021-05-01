#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b){
    unsigned int c;
    while (b != 0) {
        c = a&b;
        a ^= b;
        b = c << 1;
    }
    return a;
}

int main() {

    printf("%d\n", add(5, 7));

    return 0;
}
