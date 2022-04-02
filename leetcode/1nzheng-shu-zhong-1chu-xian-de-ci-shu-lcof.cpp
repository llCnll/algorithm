#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int count;

void search(long long current, int count_1, int n) {
    if (current > n) {
        return ;
    }
    count += count_1;
    for (long i = 0; i < 10; ++i) {
            search(current*10+i, i == 1 ? count_1+1 : count_1, n);
    }
}

int computeFront2(int n) {
    while (n > 99) {
        n /= 10;
    }
    return n;
}

int computeCount1(int n) {
    int count1 = 0;
    while (n >0) {
        if (1 == n%10) {
            count1++;
        }
        n /= 10;
    }
    return count1;
}

int countDigitOne(int n){
    count = 0;
    if (n == 0) {
        return 0;
    }
    if (n < 10) {
        return 1;
    }
    count++;
    // 外层循环从[xx, n的前两位]开始, 前提要大于10
    //int front2 = computeFront2(n);
    for (int i = 10; i <= 99; ++i) {
        search(i, computeCount1(i), n);
    }

    return count;
}

int main() {

    //824883294
    printf("%d\n", countDigitOne(820000000));

    return 0;
}

