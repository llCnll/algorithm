#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

int getSum(int i, int j) {
    int sum = 0;
    while(i) {
        sum += i%10;
        i /= 10;
    }
    while(j) {
        sum += j%10;
        j /= 10;
    }

    return sum;
}

void dfs(int vis[][110], int row, int col, int i, int j, int k) {
    if (i < 0 || j < 0 || i >= row || j >= col || vis[i][j] == 1) return;

    if (getSum(i, j) > k) return;

    vis[i][j] = 1;
    count ++;

    dfs(vis, row, col, i, j+1, k);
    dfs(vis, row, col, i+1, j, k);
    dfs(vis, row, col, i-1, j, k);
    dfs(vis, row, col, i, j-1, k);
}

int movingCount(int m, int n, int k){
    count = 0;
    int vis[110][110] = {0};

    dfs(vis, m, n, 0, 0, k);

    return count;
}

int main() {

    printf("%d\n", movingCount(2, 3, 1));
    printf("%d\n", movingCount(3, 1, 0));

    return 0;
}

