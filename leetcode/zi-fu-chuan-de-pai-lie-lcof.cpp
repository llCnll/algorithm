#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __QsortComp(const void * a, const void * b) {
    return *(char*)a - *(char*)b;
}

void backTrack(char ** result, int * currentSize, char * s, bool * chooses, char * last_s, int last_index) {
    if (last_index >= strlen(s)) {
        // printf("%d --> (%s)\n", *currentSize, last_s);
        strcpy(result[(*currentSize)++], last_s);
    }

    for (int i = 0; i < strlen(s); ++i) {
        if (chooses[i] != 0 || (i > 0 && s[i] == s[i-1] && chooses[i-1] == 0)) {
            continue;
        }
        chooses[i] = 1;
        last_s[last_index++] = s[i];

        backTrack(result, currentSize, s, chooses, last_s, last_index);

        last_index--;
        chooses[i] = 0;
    }
}

char** permutation(char* s, int* returnSize){
    char ** result = (char**)malloc(sizeof(char*)*40320);
    *returnSize = 0;
    for (int i = 0; i < 40320; ++i) {
        result[i] = (char*)calloc(strlen(s)+1, sizeof(char));
    }

    // 给char排序用于剪枝
    qsort(s, strlen(s), sizeof(char), __QsortComp);

    bool * chooses = (bool*)calloc(strlen(s)+1, sizeof(bool));
    char * last_s = (char*)calloc(strlen(s)+1, sizeof(char));

    backTrack(result, returnSize, s, chooses, last_s, 0);

    free(chooses);
    free(last_s);
    return result;
}

int main() {

    int returnSize = 0;
    char ch[] = "aba";
    char ** result = permutation(ch, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
    }

    return 0;
}

