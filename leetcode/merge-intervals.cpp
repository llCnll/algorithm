#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int comp(const void * a, const void * b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int** merge(int ** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ans = (int**)malloc(sizeof(int*) * intervalsSize);
    int count = 0;

    qsort(intervals, intervalsSize, sizeof(intervals[0]), comp);

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        } else {
            int * temp = (int*)malloc(sizeof(int)*2);
            temp[0] = start, temp[1] = end;
            ans[count++] = temp;
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    int * temp = (int*)malloc(sizeof(int)*2);
    temp[0] = start, temp[1] = end;
    ans[count++] = temp;

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; ++i) {
        returnColumnSizes[0][i] = 2;
    }

    return ans;
}

/*
int vis[1010] = {0};


void fill(int start, int end, int value) {
    // memset(vis+start, 1, sizeof(int) * (end-start+1));
    for (int i = start; i <= end; ++i) vis[i] = value;
}

int** merge(int intervals[][2], int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    memset(vis, 0, sizeof(int) * 1010);

    for (int i = 0; i < intervalsSize; ++i) {
        fill(intervals[i][0], intervals[i][1], i);
    }

    int ** ans = (int**)malloc(sizeof(int*) * intervalsSize);

    int start = 0;
    int end = 0;
    int count = 0;

    // 更新start: true
    int flag = vis[0] != 0 ? false : true;

    for(int i = 0; i < 1001; ++i) {
        if (vis[i] != 0 && vis[i] == vis[i-1]) {
            end = i;
            start = flag ? i: start;
            flag = false;
        } else if (vis[i] == 0 || vis[i] != vis[i-1]) {
            if (!flag) {
                flag = true;
                // 合并
                ans[count] = (int*)calloc(2, sizeof(int));
                ans[count][0] = start;
                ans[count][1] = end;
                count ++;
                if (vis[i] != 0 && vis[i] != vis[i-1]) {
                    flag = false;
                    start = i;
                }
            }
        }
    }

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; ++i) {
        returnColumnSizes[0][i] = 2;
    }

    return ans;
}
*/

int main() {

    int ** arr = (int**)malloc(sizeof(int*) * 4);
    arr[0] = (int*)calloc(2, sizeof(int));
    arr[0][0] = 1, arr[0][1] = 3;

    arr[1] = (int*)calloc(2, sizeof(int));
    arr[1][0] = 3, arr[1][1] = 4;

    arr[2] = (int*)calloc(2, sizeof(int));
    arr[2][0] = 8, arr[2][1] = 15;

    arr[3] = (int*)calloc(2, sizeof(int));
    arr[3][0] = 6, arr[3][1] = 7;

    int colSize[] = {2, 2, 2, 2};
    int returnSize;
    int * returnColumnSizes;

    int ** ans = merge(arr, 4, colSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) 
            printf("%d ", ans[i][j]);
        putchar('\n');
    }

    return 0;
}

