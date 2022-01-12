#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

char temp[20];
int t_index = 0;
int left_count = 0;
int right_count = 0;
int total_count = 0;

void start(int n, char ** ans) {
    if (left_count == n && right_count == n) {
        ans[total_count] = (char*)calloc(20, sizeof(char));
        strcpy(ans[total_count++], temp);
        return ;
    }

    if (left_count < n) {
        left_count ++;
        temp[t_index++] = '(';
        start(n, ans);
        t_index--;
        left_count--;
    }
    if (right_count < n && left_count > right_count) {
        right_count ++;
        temp[t_index++] = ')';
        start(n, ans);
        t_index--;
        right_count --;
    }
}

char ** generateParenthesis(int n, int* returnSize){

    char ** ans = (char**)malloc(sizeof(char*) * 1500);

    start(n, ans);

    *returnSize = total_count;
    return ans;
}

int main() {

    int size = 0;

    char ** ans = generateParenthesis(8, &size);

    printf("size: %d\n", size);

    for (int i = 0; i < size; ++i) {
        printf("%s\n", ans[i]);
    }

    return 0;
}

