#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a) > (b) ? (a) : (b)

char * longestPalindrome(char * s) {
    int length = strlen(s);
    int ** result = (int**)malloc(sizeof(int*) * (length+1));
    for (int i = 0; i <= length; ++i) {
        result[i] = (int *)calloc(length+1, sizeof(int));
    }

    int max_length = 0;
    int end = 0;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (s[i] == s[length-j-1]) {
                result[i+1][j+1] = result[i][j]+1;
            }
            if (result[i+1][j+1] > max_length && (length-1-j + result[i+1][j+1] -1 == i)) {
                max_length = result[i+1][j+1];
                end = i;
            }
        }
    }


    //for (int i = 0; i <= length; ++i) {
    //    for (int j = 0; j <= length; ++j) {
    //        printf("%d ", result[i][j]);
    //    }
    //    putchar('\n');
    //}

    char * str = (char*)calloc(max_length+1, sizeof(char));

    //printf("end = %d, max_lenght = %d\n", end, max_length);
    memcpy(str, s+end-max_length+1, sizeof(char)*max_length);
    return str;
}

int main() {

    char s[] = "aacabdkacaa";

    printf("%s\n", longestPalindrome(s));

    return 0;
}

