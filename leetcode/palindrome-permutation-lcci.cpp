#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool canPermutePalindrome(char* s){
    if (s == NULL) return true;

    int mark[256] = {0};

    for (int i = 0; i < strlen(s); ++i) {
        mark[s[i]] ++;
    }

    int flag = strlen(s) & 1?1:0;

    for (int i = 0; i < 256; ++i) {
        if ((mark[i] & 1) && flag) {
            flag --;
        } else if ((mark[i] & 1) && !flag) {
            return false;
        }
    }
    return true;
}

int main() {

    char ch[] = "tactcoa";

    printf("%d\n", canPermutePalindrome(ch));

    return 0;
}

