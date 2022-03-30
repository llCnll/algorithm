#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int findDuplicate(int* nums, int numsSize){
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;

    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

/*
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int findDuplicate(int* nums, int numsSize){

    int i = 0;
    while (i < numsSize) {
        if (nums[i]-1 != i && nums[i] != nums[nums[i]-1]) {
            swap(nums, i, nums[i]-1);
        } else if (nums[i]-1 != i && nums[i] == nums[nums[i]-1]) return nums[i];
        else i ++;
    }

    for (i = 0; i < numsSize; ++i) printf("%d ", nums[i]);
    putchar('\n');
    return 1;
}
*/
int main() {

    int nums[] = {1,3,4,2,2};
    int numsSize = 5;

    printf("%d\n", findDuplicate(nums, numsSize));

    return 0;
}

