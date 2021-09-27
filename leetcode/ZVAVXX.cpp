#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if (numsSize == 0) return 0;

    int front = 0;
    int rear = 0;
    int count = 0;

    int mul = 1;

    while (rear < numsSize) {
        if (nums[rear] * mul < k) {
            mul *= nums[rear];
            count += rear-front+1;
            rear++;
        } else {
            mul /= nums[front];
            front ++;
            if (front > rear) {
                rear = front;
                mul = 1;
            }
        }
    }
    return count;
}

int main() {
    int nums[20] = {10, 5, 2, 6};

    printf("%d\n", numSubarrayProductLessThanK(nums, 4, 100));

    return 0;
}
