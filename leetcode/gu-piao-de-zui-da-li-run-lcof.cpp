#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    int min_price = INT_MAX;
    int result = 0;
    for (int i = 0; i < pricesSize; ++i) {
        min_price = min(min_price, prices[i]);
        result = max(result, prices[i] - min_price);
    }
    return result;
}

// 超时
int maxProfit2(int* prices, int pricesSize){
    int dp[100000] = {0};

    int temp;
    for (int i = 1; i < pricesSize; ++i) {
        for (int j = i+1; j <= pricesSize; ++j) {
            temp = prices[j-1] - prices[i-1];
            temp = temp < 0 ? 0 : temp;
            dp[j] = max(temp, max(dp[j], dp[j-1]));
        }
    }
    return dp[pricesSize];
}

int main() {

    int arr[] = {7, 1,4,3,2,9};
    int size = 6;

    printf("%d\n", maxProfit(arr,size));

    return 0;
}

