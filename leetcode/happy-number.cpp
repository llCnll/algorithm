#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool isHappy(int n){

    int ans = 0;
    while (true) {
        ans = 0;
        int temp_n = n;
        while (temp_n) {
            int t = temp_n % 10;
            ans += t*t;
            temp_n /= 10;
        }
        if (ans == 1) return true;
        if (ans < 10 && ans != 7) return false;
        n = ans;
    }

    return false;
}

int main() {

    printf("%d\n", isHappy(2));

    return 0;
}

