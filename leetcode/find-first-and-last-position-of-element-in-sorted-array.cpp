#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)

void __Binary(int * nums, int left, int right, int target, int * result) {
    if (left == right) {
        if (nums[left] == target) {
            result[0] = min(result[0], left);
            result[1] = max(result[1], right);
        }
        return ;
    }
    if (left > right || nums[right] < target || nums[left] > target) {
        return ;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        result[0] = min(result[0], mid);
        result[1] = max(result[1], mid);
    }
    __Binary(nums, left, mid-1, target, result);
    __Binary(nums, mid+1, right, target, result);
}

void Binary(int * nums, int numsSize, int target, int *result) {
    __Binary(nums, 0, numsSize-1, target, result);
}

int* searchRange(int* nums, int numsSize, int target, int * returnSize){
    *returnSize = 2;
    int * result = (int *)malloc(sizeof(int) * *returnSize);
    result[0] = 0x3f3f3f;
    result[1] = -1;
    Binary(nums, numsSize, target, result);

    if (result[0] == 0x3f3f3f) {
        result[0] = result[1] = -1;
    }

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
