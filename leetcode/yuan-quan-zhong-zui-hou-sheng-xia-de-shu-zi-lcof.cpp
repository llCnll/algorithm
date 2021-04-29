#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastRemaining(int n, int m){
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result  = (result + m) % i;
    }
    return result;
}

int main() {

    printf("%d\n", lastRemaining(2, 2));
    printf("%d\n", lastRemaining(3, 2));
    printf("%d\n", lastRemaining(5, 3));

    return 0;
}

