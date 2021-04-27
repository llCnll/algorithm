#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char firstUniqChar(char* s){
    // 0: 顺序 1: 次数
    int count[26][2];
    int s_len = strlen(s);
    memset(count, 0, sizeof(int)*26*2);

    int seq = 0;
    int index;
    for (int i = 0; i < s_len; ++i) {
        index = s[i] - 'a';
        if (count[index][1] == 0) {
            count[index][0] = seq++;
        }
        count[index][1] ++;
    }

    int min_seq = 100;
    char ch = ' ';
    for (int i = 0; i < 26; ++i) {
        if (count[i][1] == 1 && min_seq > count[i][0]) {
            min_seq = count[i][0];
            ch = i+'a';
        }
    }

    return ch;
}

int main() {

    char s[] = "leetcode";

    printf("%c\n", firstUniqChar(s));

    return 0;
}
