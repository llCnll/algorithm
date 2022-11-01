#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int uniquePathsWithObstacles(int obstacleGrid[][3], int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    int ** dp = (int**)malloc(sizeof(int*)*m);
    for (int i = 0; i < m; ++i)
        dp[i] = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i) dp[0][i] = 1;
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    int ans = dp[m-1][n-1];
    for (int i = 0; i < m; ++i)
        free(dp[i]);
    free(dp);

    return ans;
}

int main() {

    int ans[][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int colSize[] = {3};

    printf("%d\n", uniquePathsWithObstacles(ans, 3, colSize));

    return 0;
}

