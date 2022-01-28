#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX_VALUE 0x3f3f3f3f
#define min(a,b) (a) > (b) ? (b) : (a)

int coinChange(int* coins, int coinsSize, int amount){
    if (amount == 0) return 0;

    int * ans = (int *)calloc(amount+1, sizeof(int));
    memset(ans, 0x3f3f, sizeof(int) * (amount+1));
    ans[0] = 0;


    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i) {
                ans[i] = min(ans[i], ans[i-coins[j]] + 1);
            }
        }
    }

    return ans[amount] > amount ? -1 : ans[amount];
}

int main() {

    int coins[] = {2};

    printf("%d\n", coinChange(coins, 1, 3));

    return 0;
}

