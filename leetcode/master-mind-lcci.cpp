#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converIndex(char ch) {
    switch (ch) {
        case 'R': return 0;
        case 'Y': return 1;
        case 'G': return 2;
        case 'B': return 3;
        default: return 0;
    }
}

int* masterMind(char* solution, char* guess, int* returnSize){
    *returnSize = 2;
    int * answer = (int *)malloc(sizeof(int) * *returnSize);
    int * amount = (int *)malloc(sizeof(int) * 4);

    memset(answer, 0, sizeof(int) * *returnSize);
    memset(amount, 0, sizeof(int) * 4);

    // 计算正确结果的数量
    for (int i = 0; i < 4; ++i) {
        amount[converIndex(solution[i])] ++;
    }

    // 先判断猜中
    for (int i = 0; i < 4; ++i) {
        if (solution[i] == guess[i]) {
            answer[0] ++;
            amount[converIndex(guess[i])] --;
        }
    }
    // 再判断伪猜中
    for (int i = 0; i < 4; ++i) {
        if (solution[i] != guess[i]) {
            int index = converIndex(guess[i]);
            // 判断是否存在该颜色
            if(amount[index] > 0) {
                amount[index] --;
                answer[1] ++;
            }
        }
    }

    free(amount);
    return answer;
}

int main() {
    char solution[] = {'R', 'G', 'B', 'Y'};
    char guess[] = {'G', 'G', 'R', 'R'};

    int size= 0;
    int * answer = masterMind(solution, guess, &size);

    for (int i = 0; i < size; ++i) {
        printf("%d\t", answer[i]);
    }

    free(answer);

    return 0;
}
