#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

char vis[30];

char findTheDifference(char * s, char * t){
    memset(vis, 0, sizeof(char) * 30);
    for (int i = 0; i < strlen(s); ++i) {
        vis[s[i]-'a'] ++;
    }
    for (int i = 0; i < strlen(t); ++i) {
        vis[t[i]-'a'] --;
        if (vis[t[i]-'a'] == -1)
            return t[i];
    }
    return 0;
}

int main() {
    char s[] = "abcd";
    char t[] = "abcde";

    printf("%c\n", findTheDifference(s, t));

    return 0;
}

