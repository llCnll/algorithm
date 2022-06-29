#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int longestPalindrome(char * s){
    int * ans = (int*)calloc(100, sizeof(int));
    int count = 0;

    for(int i = 0; i < strlen(s); ++i) {
        ans[s[i] - 'A'] ++;
    }

    int choose_odd = false;

    for (int i = 0; i < 100; ++i) {
        if (ans[i] % 2 == 0) {
            count += ans[i];
        } else {
            if (choose_odd && ans[i] > 1) {
                count += ans[i]-1;
            } else if (!choose_odd) {
                count += ans[i];
                choose_odd  = true;
            }
        }

    }

    free(ans);
   return count;
}

int main() {
    char s[] = "bb";

    printf("%d\n", longestPalindrome(s));

    return 0;
}

