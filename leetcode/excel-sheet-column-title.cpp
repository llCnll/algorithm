#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

char * convertToTitle(int columnNumber){
    char * ans = (char*)malloc(sizeof(char) * 50);
    memset(ans, 0, sizeof(char) * 50);

    int i = 0;
    while (columnNumber > 0) {
        columnNumber --;
        ans[i++] = (columnNumber) % 26 + 'A';
        columnNumber /= 26;
    }

    // 反转
    for (int x = 0, y = i-1; x < i/2; ++x,--y) {
        int tmp = ans[x];
        ans[x] = ans[y];
        ans[y] = tmp;
    }

    return ans;
}

int main() {

    printf("%s\n", convertToTitle(2));
    printf("%s\n", convertToTitle(26));
    printf("%s\n", convertToTitle(28));
    printf("%s\n", convertToTitle(701));

    return 0;
}

