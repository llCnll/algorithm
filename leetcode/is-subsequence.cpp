#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool isSubsequence(char * s, char * t){
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len == 0 && t_len == 0) return true;

    for (int t_i = 0, s_i = 0; t_i < t_len; ++t_i) {
        if (t[t_i] == s[s_i]) {
            s_i++;
        }
        if (s_i == s_len) return true;
    }

    return false;
}

int main() {

    char s[] = "abcd";
    char t[] = "ahbgdc";

    printf("%d\n", isSubsequence(s, t));

    return 0;
}

