#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseLeftWords(char* s, int n){
    char * new_s = (char*)malloc(sizeof(char) * (strlen(s)+1+n));
    strcpy(new_s, s);
    int last_index = strlen(new_s);
    for (int i = 0; i < n; ++i) {
        new_s[last_index++] = s[i];
    }
    new_s[last_index] = 0;
    return new_s+n;
}

int main() {

    char s[] = "abcdefg";

    printf("%s\n", reverseLeftWords(s, 2));

    return 0;
}
