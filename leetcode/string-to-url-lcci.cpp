#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char back[] = "%20";

char* replaceSpaces(char* s, int length){
    if (s == NULL) return NULL;
    char * ans = (char*)calloc(3*length + 1, sizeof(char));
    int ans_index = 0;
    for (int i = 0; i < length; ++i) {
        if (s[i] == ' ') {
            ans[ans_index++] = '%';
            ans[ans_index++] = '2';
            ans[ans_index++] = '0';
        } else {
            ans[ans_index++] = s[i];
        }
    }
    ans[ans_index] = 0;
    return ans;
}

int main() {

    char s[] = "Mr John Smith    ";

    printf("%s\n", replaceSpaces(s, 13));

    return 0;
}

