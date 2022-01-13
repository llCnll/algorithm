#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void swap(int * nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int getPartition(int * nums, int left, int right) {
    int target = nums[left];

    int i = left+1, j = right;
    while (true) {
        while (nums[i] < target && i <= right) {
            i++;
        }
        while (nums[j] > target && j >= left+1) {
            j--;
        }
        if (i >= j) break;

        swap(nums, i, j);
        i++, j--;
    }
    swap(nums, left, j);
    return j;
}

int __quickSort(int * nums, int left, int right, int k) {
    if (left >= right) return nums[left];

    int partition = getPartition(nums, left, right);
    printf("%d, %d, partition = %d\n", left, right, partition);
    if (partition == k) return nums[k];
    else if (partition > k) return __quickSort(nums, left, partition-1, k);
    else return __quickSort(nums, partition+1, right, k);
}

int findKthLargest(int* nums, int numsSize, int k){
    return __quickSort(nums, 0, numsSize-1, numsSize-k);
}

int main() {

    int nums[] = {3, 2};

    printf("%d\n", findKthLargest(nums, 2, 1));

    for (int i = 0; i < 2; ++i) {
        printf("%d\t", nums[i]);
    }

    return 0;
}

