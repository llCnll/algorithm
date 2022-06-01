#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int comp(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);

    int g_idx = 0;
    int s_idx = 0;
    int count = 0;

    while (true) {
        if (g_idx >= gSize || s_idx >= sSize) {
            break;
        }
        if (g[g_idx] <= s[s_idx]) {
            g_idx++, s_idx++, count++;
        } else {
            s_idx++;
        }
    }
    return count;
}

int main() {

    int g[] = {1,2,3};
    int s[] = {2,1};

    printf("%d\n", findContentChildren(g, 3, s, 2));

    return 0;
}
