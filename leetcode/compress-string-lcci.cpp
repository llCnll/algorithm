#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* compressString(char* s){
    if (s == NULL) return NULL;
    if (strlen(s) == 0) return s;

    int current_ch = s[0];
    int cnt = 1;

    char * ans = (char*)calloc(strlen(s)*3, sizeof(char));
    char * temp = (char*)calloc(10, sizeof(char));

    for (int i = 1; i < strlen(s); ++i) {
        if (current_ch != s[i]) {
            sprintf(temp, "%c%d", current_ch, cnt);
            strcat(ans, temp);
            cnt = 1;
            current_ch = s[i];
        } else cnt++;
    }
    sprintf(temp, "%c%d", current_ch, cnt);
    strcat(ans, temp);
    return strlen(ans) >= strlen(s) ? s : ans;
}

int main() {

    char s[] = "abcccccaaa";

    printf("%s\n", compressString(s));

    return 0;
}


