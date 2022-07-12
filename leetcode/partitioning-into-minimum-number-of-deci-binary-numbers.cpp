#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minPartitions(char * n){
    int max_ans = 0;
    for (int i = 0; i < strlen(n); ++i) {
        max_ans = MAX(max_ans, n[i]-'0');
    }
    return max_ans;
}

int main() {

    printf("%d\n", minPartitions("32"));

    return 0;
}

