#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int longestCommonSubsequence(char * text1, char * text2){
    int text2_length = strlen(text2);
    int text1_length = strlen(text1);

    int ** dp = (int**)malloc(sizeof(int*) * (text2_length+1));
    for (int i = 0; i <= text2_length; ++i) {
        dp[i] = (int*)calloc(text1_length+1, sizeof(int));
    }

    for (int i = 1; i <= text2_length; ++i) {
        for (int j = 1; j <= text1_length; ++j) {
            if (text1[j-1] == text2[i-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for (int i = 1; i <= text2_length; ++i) {
        for (int j = 1; j <= text1_length; ++j) {
            printf("%d ", dp[i][j]);
        }
        putchar('\n');
    }
    return dp[text2_length][text1_length];
}

int main() {
    char text1[] = "abcbcba";
    char text2[] = "abcba";

    printf("%d\n", longestCommonSubsequence(text1, text2));

    return 0;
}

