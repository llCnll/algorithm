#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumNums(int n){
    int basic = 1 + n;
    int sum = 0;
    int shift = 0;

    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    shift ++;
    sum += n&(1<<shift) ? basic << shift : 0;

    return sum >> 1;
}

int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}

int main() {

    printf("%d\n", sumNums(100));

    return 0;
}

