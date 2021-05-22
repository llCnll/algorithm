#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool CheckPermutation(char* s1, char* s2){
    // 当做只有26个小写字母
    if (s1 == NULL && s2 == NULL) return true;
    if (strlen(s1) != strlen(s2)) return false;
    int * flag = (int*)calloc(26, sizeof(int));

    for (int i = 0; i < strlen(s1); ++i) {
        flag[s1[i]-'a']++;
        flag[s2[i]-'a']--;
    }

    for(int i = 0; i < 26; ++i) {
        if (flag[i] != 0) {
            return false;
        }
    }
    free(flag);
    return true;
}

int main() {

    char s1[] = "abc";
    char s2[] = "bca";

    printf("%d\n", CheckPermutation(s1, s2));

    return 0;
}

