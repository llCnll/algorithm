#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    std::set<int> num_set;
    for (int i = 0; i < numsSize; ++i) {
        if (num_set.size() == k+1) {
            num_set.erase(nums[i-k-1]);
        }
        if (num_set.find(nums[i]) != num_set.end()) {
            return true;
        }
        num_set.insert(nums[i]);
    }
    return false;
}

int main() {
    int nums[] = {1,2,3,1};
    int k = 3;

    printf("%d\n", containsNearbyDuplicate(nums, 4, k));

    return 0;
}

