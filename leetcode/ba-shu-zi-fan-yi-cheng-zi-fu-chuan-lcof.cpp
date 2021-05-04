#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count;

void trackBack(int num){
    if (num == 0) {
        count ++;
        return;
    }
    trackBack(num / 10);
    int mod_num = num % 100;
    if (mod_num > 9 && mod_num < 26) {
        trackBack(num / 100);
    }
}

int translateNum(int num){
    count = 0;
    trackBack(num);
    return count;
}

int main() {

    printf("%d\n", translateNum(12258));

    return 0;
}

