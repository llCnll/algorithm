#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <map>
#include <iostream>

int subarraySum(int* nums, int numsSize, int k){
    int count = 0;

    std::map<int, int> map;
    map[0]++;
    for (int i = 0; i < numsSize; ++i) {
        if (i > 0) {
            nums[i] += nums[i-1];
            map[nums[i-1]] ++;
        }
        count += map[nums[i]-k];
    }
    //std::map<int,int>::iterator iter;
    //for(iter = map.begin(); iter != map.end(); iter++)
    //    std::cout<< iter->first << ' ' << iter->second << std::endl;

    return count;
}

int main() {

    int nums[20] = {1,2,3};

    printf("%d\n", subarraySum(nums, 3, 3));

    return 0;
}

