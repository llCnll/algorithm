#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int uniquePaths(int m, int n){
    int ** dp = (int**)malloc(sizeof(int*)*m);
    for (int i = 0; i < m; ++i)
        dp[i] = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) dp[0][i] = 1;
    for (int i = 0; i < m; ++i) dp[i][0] = 1;

    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

    int ans = dp[m-1][n-1];
    for (int i = 0; i < m; ++i)
        free(dp[i]);
    free(dp);
    return ans;
}

int main() {

    printf("%d\n", uniquePaths(3, 7));
    printf("%d\n", uniquePaths(3, 3));

    return 0;
}

