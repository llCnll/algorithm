#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool isUnique(char* astr){
    // 假设只有26个字母的情况
    int mark = 0;
    for (int i = 0; i < strlen(astr); ++i) {
        int shift = 1 << (astr[i]-'a');
        if ((mark & shift) == shift) {
            return false;
        }
        mark |= shift;
    }
    return true;
}

int main() {

    char s[] = "leetcode";
    char s2[] = "abs";

    printf("%d\n", isUnique(s));
    printf("%d\n", isUnique(s2));

    return 0;
}

