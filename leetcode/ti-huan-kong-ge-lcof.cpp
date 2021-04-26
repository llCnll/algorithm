#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceSpace(char* s){
    int s_len = strlen(s);
char* new_s = (char *)malloc(sizeof(char) * s_len * 3 + 1);

    int new_s_index = 0;
    for(int i = 0; i < s_len; ++i) {
        if (s[i] == ' ') {
            new_s[new_s_index++] = '%';
            new_s[new_s_index++] = '2';
            new_s[new_s_index++] = '0';
        } else {
            new_s[new_s_index++] = s[i];
        }
    }

    new_s[new_s_index] = 0;
    return new_s;
}

int main() {
    char s[] = "We are happy.";
    char s2[] = " ";
    printf("%s\n", replaceSpace(s));
    printf("%s\n", replaceSpace(s2));
    return 0;
}
