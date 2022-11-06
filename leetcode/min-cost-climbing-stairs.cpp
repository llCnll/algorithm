#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int minCostClimbingStairs(int* cost, int costSize){
    for(int i = 2; i < costSize; ++i) {
        cost[i] = min(cost[i-1] + cost[i], cost[i-2] + cost[i]);
    }
    return min(cost[costSize-1], cost[costSize-2]);
}

int main() {

    int cost[] = {1,100,1,1,1,100,1,1,100,1};
    int size = 10;

    printf("%d\n", minCostClimbingStairs(cost, size));

    return 0;
}

