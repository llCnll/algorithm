#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int getLength(int x) {
    int length = 0;

    while (x) {
        length ++;
        x /= 10;
    }

    return length;
}

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }

    int length = getLength(x);

    int * bits = (int *)malloc(sizeof(int) * length);

    for (int i = 0; i < length; ++i) {
        bits[i] = x % 10;
        x /= 10;
    }

    int flag = true;

    for (int i = 0; i < length/2; ++i) {
        if (bits[i] != bits[length-i-1]) {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {

    printf("%d\n", isPalindrome(19));
    printf("%d\n", isPalindrome(121));
    printf("%d\n", isPalindrome(-1));

    return 0;
}

