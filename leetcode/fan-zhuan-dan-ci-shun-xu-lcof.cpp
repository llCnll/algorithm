#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void __reverse(char *s, int left, int right) {
    char temp;
    while(left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s){
    char * new_s = (char *)malloc(sizeof(char) * (strlen(s)+1));
    strcpy(new_s, s);
    __reverse(new_s, 0, strlen(s)-1);

    int left = 0, right = 0;
    int is_blank = 1;
    for (int i = 0; i < strlen(new_s); ++i) {
        if (new_s[i] != ' ' && !is_blank) {
            right = i;
        }
        if (new_s[i] != ' ' && is_blank) {
            right = i;
            left = i;
            is_blank = 0;
        }
        if (new_s[i] == ' ' && !is_blank) {
            right = i-1;
            is_blank = 1;
            __reverse(new_s, left, right);
        }
    }
    if (!is_blank) {
        __reverse(new_s, left, right);
    }

    // 删除空格
    is_blank = 1;
    int real_index = 0;
    for (int i = 0; i < strlen(new_s); ++i) {
        if (new_s[i] == ' ') {
            if (is_blank) continue;
            else {
                is_blank = 1;
                new_s[real_index++] = new_s[i];
            }
        } else {
            new_s[real_index++] = new_s[i];
            is_blank = 0;
        }
    }
    new_s[real_index] = 0;
    // 可能存在最后一个空格
    if(real_index > 0 && new_s[real_index-1] == ' ') {
        new_s[real_index-1] = 0;
    }
    return new_s;
}

int main() {

    char s[] = "the sky is blue";
    printf("%s\n", reverseWords(s));
    char s2[] = "  hello world!  ";
    printf("%s\n", reverseWords(s2));
    char s3[] = "a good   example";
    printf("%s\n", reverseWords(s3));


    return 0;
}
