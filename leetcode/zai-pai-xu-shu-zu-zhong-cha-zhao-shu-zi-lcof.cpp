#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

void __Binary(int * nums, int left, int right, int target) {
    if (left == right) {
        if (nums[left] == target) {
            count ++;
        }
        return ;
    }
    if (left > right || nums[right] < target || nums[left] > target) {
        return ;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        count ++;
    }
    __Binary(nums, left, mid-1, target);
    __Binary(nums, mid+1, right, target);
}

void Binary(int * nums, int numsSize, int target) {
    __Binary(nums, 0, numsSize-1, target);
}

int search(int* nums, int numsSize, int target){
    count = 0;
    Binary(nums, numsSize, target);
    return count;
}

int main() {

    int arr[] = {5,7,7,8,8,10};
    printf("%d\n", search(arr, 6, 8));
    int arr2[] = {1};
    printf("%d\n", search(arr2, 1, 1));

    return 0;
}
