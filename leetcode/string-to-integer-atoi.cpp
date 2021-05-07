#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ll long long

int myAtoi(char* str){
    ll result = 0;

    int sign = 1;
    int start_flag = 0;
    for(int i = 0; i < strlen(str); ++i) {
        if (start_flag == 0 && str[i] == ' ') {
            continue;
        }
        if (start_flag == 0 && str[i] == '-') {
            sign = -1;
            start_flag = 1;
            continue;
        }
        if (start_flag == 0 && str[i] == '+') {
            start_flag = 1;
            continue;
        }
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        result = result * 10 + str[i] - '0';
        start_flag = 1;
        if (result > INT_MAX) {
            break;
        }
    }
    if (result > (ll)INT_MAX && sign == 1) {
        return INT_MAX;
    } else if (result > (ll)(INT_MAX)+1 && sign == -1) {
        return INT_MIN;
    }
    return (int)(result * sign);
}

int main() {

    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("    -42"));
    printf("%d\n", myAtoi("withs and 42"));
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("42aaaa"));
    printf("%d\n", myAtoi("2147483647"));
    printf("%d\n", myAtoi("-2147483647"));
    printf("%d\n", myAtoi("2147483648"));

    return 0;
}

