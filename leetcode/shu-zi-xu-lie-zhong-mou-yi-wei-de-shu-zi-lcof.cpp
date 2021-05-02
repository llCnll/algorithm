#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long

int findNthDigit(int n){
    if (n < 10) {
        return n;
    }

    // 边界总长度
    ll len_sum = 10;
    // 当前数字位数
    ll current_digit = 1;
    // 上一次边界的长度
    ll last_len = 0;
    // 临时变量
    ll current_period_len = 0;
    while (true) {
        current_digit ++;
        last_len = len_sum;
        current_period_len = (ll)(pow(10, current_digit) * 0.9 * current_digit);
        len_sum += current_period_len;
        if (len_sum >= n) {
            break;
        }
    }

    ll current_period_start_len = n - last_len;
    // 第几个
    ll nth = current_period_start_len / current_digit;
    // 从低到高
    ll nth_digit = current_digit - (current_period_start_len % current_digit) - 1;

    ll num = pow(10, current_digit-1) + nth;
    printf("digit_len = %lld, num = %lld, nth_digit = %lld\n", current_digit, num, nth_digit);
    while(num != 0) {
        if (nth_digit == 0) {
            return num % 10;
        }
        num /= 10;
        nth_digit --;
    }
    return 0;
}

int main() {

    printf("%d\n", findNthDigit(3));
    printf("%d\n", findNthDigit(10));
    printf("%d\n", findNthDigit(11));
    printf("%d\n", findNthDigit(19));
    printf("%d\n", findNthDigit(1000));

    return 0;
}

