#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s){
    if(strlen(s) == 0) {
        return 0;
    }
    int * digit = (int*)calloc(100, sizeof(int));

    int start = 0;
    digit[s[0]] ++;
    int end = 0;

    int max_count = 1, current_max = 1;

    for (int i = 1; i < strlen(s); ++i) {
        end ++;
        // 是否重复, 不重复追加更新最大长度
        // 重复, start++到不重复位置
        if (digit[s[i]] != 0) {
            while (start < end) {
                digit[s[start]] --;
                start ++;
                current_max --;
                if (s[start-1] == s[end]) {
                    break;
                }
            }
        }
        current_max ++;
        digit[s[i]] ++;
        max_count = max(current_max, max_count);
    }
    free(digit);
    return max_count;
}

int main() {

    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("dvdf"));
    printf("%d\n", lengthOfLongestSubstring("bbbb"));

    return 0;
}

