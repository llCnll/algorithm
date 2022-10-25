#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

void binary_search(int* nums, int left, int right, int target, int * result) {
    if (left > right) {
        return ;
    }

    int mid = (left + right) / 2;

    if (nums[mid] == target) {
        result[0] = min(result[0], mid);
        result[1] = max(result[1], mid);
    }

    if(nums[mid] >= target) {
        binary_search(nums, left, mid-1, target, result);
    }

    if (nums[mid] <= target) {
        binary_search(nums, mid+1, right, target, result);
    }
}

int* searchRange(int* nums, int numsSize, int target, int * returnSize){
    int * result = (int *)calloc(2, sizeof(int));
    *returnSize = 2;
    result[0] = 100010;
    result[1] = -1;
    binary_search(nums, 0, numsSize-1, target, result);

    result[0] = result[0] == 100010 ? -1 : result[0];
    return result;
}

int main() {

    int arr[] = {5,7,7,8,8,10};
    int returnSize = 0;
    int * result = searchRange(arr, 6, 8, &returnSize);
    printf("%d, %d\n", result[0], result[1]);
    int arr2[] = {1};
    result = searchRange(arr2, 1, 1, &returnSize);
    printf("%d, %d\n", result[0], result[1]);


    return 0;
}
