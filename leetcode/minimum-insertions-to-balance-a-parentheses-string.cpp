#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int minInsertions(char * s){
    int left_count = 0;
    int right_count = 0;
    int ans = 0;

    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '(') {
            left_count ++;
            if (right_count == 1) ans++, right_count = 0, left_count--;
        }
        if (s[i] == ')')
            right_count ++;

        if (left_count ==0 && right_count > 0) {
            left_count ++, ans++;
        }else if (left_count != 0 && right_count != 0) {
            if (right_count == 2) {
                left_count --, right_count = 0;
            }
        }
    }

    if (left_count == 0 && right_count == 0) return ans;
    else if (left_count == 0) return ans + right_count/2 + right_count%2==0?0:2;
    else if (right_count == 0) return ans + left_count * 2;
    else return ans + (left_count-1)*2 + 1;

    return 0;
}

int main() {

    char s1[] = "(()))";
    char s2[] = "())";

    printf("%d\n", minInsertions(s1));
    printf("%d\n", minInsertions(s2));

    return 0;
}

