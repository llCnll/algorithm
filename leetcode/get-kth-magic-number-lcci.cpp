#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) > (b) ? (b) :(a) )
#define MAX 1000000

int nums[MAX];

int getKthMagicNumber(int k){
    if (1 == k) {
        return 1;
    }
    memset(nums, 0, sizeof(nums));
    nums[0] = 1;

    int i3 = 0, i5 = 0, i7 = 0;

    for (int i = 1; i < k; ++i) {
        nums[i] = min(nums[i3]*3, min(nums[i5]*5, nums[i7]*7));
        if (nums[i3]*3 == nums[i]) i3++;
        if (nums[i5]*5 == nums[i]) i5++;
        if (nums[i7]*7 == nums[i]) i7++;
    }
    return nums[k-1];
}

int main() {
    printf("%d\n", getKthMagicNumber(5));
    return 0;
}
