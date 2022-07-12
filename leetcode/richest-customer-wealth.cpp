#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int max_account = 0;

    for (int i = 0; i < accountsSize; ++i) {
        int temp_max = 0;
        for (int j = 0; j < accountsColSize[i]; ++j)
            temp_max += accounts[i][j];
        max_account = MAX(max_account, temp_max);
    }
    return max_account;
}

int main() {
    int ** accounts = (int**)malloc(sizeof(int*) * 3);
    accounts[0] = (int*)malloc(sizeof(int) * 2);
    accounts[0][0] = 2;
    accounts[0][1] = 8;

    accounts[1] = (int*)malloc(sizeof(int) * 2);
    accounts[1][0] = 2;
    accounts[1][1] = 9;

    accounts[2] = (int*)malloc(sizeof(int) * 2);
    accounts[2][0] = 2;
    accounts[2][1] = 7;

    int accountsColSize[3] = {2,2,2};

    printf("%d\n", maximumWealth(accounts, 3, accountsColSize));

    return 0;
}

