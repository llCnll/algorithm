#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void lowerChar(char * s) {
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

void bfs(char ** ans, char * s, int index, int * count) {
    if (index == strlen(s)) {
        ans[*count] = (char*)calloc(strlen(s)+1, sizeof(char));
        memcpy(ans[(*count)++], s, strlen(s) + 1);
        return ;
    }
    if (s[index] >= 'a' && s[index] <= 'z') {
        bfs(ans, s, index+1, count);
        s[index] -= 32;
        bfs(ans, s, index+1, count);
        s[index] += 32;
    } else {
        bfs(ans, s, index+1, count);
    }
}

char ** letterCasePermutation(char * s, int* returnSize){
    lowerChar(s);

    char ** ans = (char**)malloc(sizeof(char*) * (1 << strlen(s)));
    int count = 0;

    bfs(ans, s, 0, &count);

    *returnSize = count;
    return ans;
}

int main() {
    char s[] = {'a', 'b', '1', '2', 0};

    int returnSize = 0;

    char ** ans = letterCasePermutation(s, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", ans[i]);
    }
    return 0;
}
