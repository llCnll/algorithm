#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    uint32_t mul = 1;
    for (int i = 0; i <32 ; ++i) {
        if ((n&mul) == mul) {
            count ++;
        }
        mul <<= 1;
    }
    return count;
}

int main() {

    printf("%d\n", hammingWeight(00000000000000000000000000001011u));

    return 0;
}
