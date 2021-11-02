#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

char * longestCommonPrefix(char strs[][200], int strsSize){
    if (strsSize == 1) {
        return strs[0];
    }
    char * ans = (char*)calloc(200, sizeof(char));



    int length = strlen(strs[0]);
    for (int i = 0; i < length; ++i) {
        for (int j = 1; j < strsSize; ++j) {
            if (strlen(strs[j]) <= i || strs[j][i] != strs[0][i]) {
                return ans;
            }

            if (j+1 == strsSize) {
                ans[i] = strs[0][i];
            }

        }
    }


    return ans;
}

int main() {

    char strs[][200] = {
        "abc",
        "abcbd",
        "abrded"
    };

    printf("%s\n", longestCommonPrefix(strs,3));

    return 0;
}

