#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int titleToNumber(char * columnTitle){
    int length = strlen(columnTitle);

    int ans = 0;

    for (int i = 0; i < length; i++) {
        ans = ans * 26 + columnTitle[i]-'A'+1;
    }

    return ans;
}

int main() {

    printf("%d\n", titleToNumber("A"));
    printf("%d\n", titleToNumber("AB"));
    printf("%d\n", titleToNumber("ZY"));
    printf("%d\n", titleToNumber("FXSHRXW"));

    return 0;
}

