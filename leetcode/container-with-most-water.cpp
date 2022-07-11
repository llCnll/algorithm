#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int max_area = 0;
    int front = 0, tail = heightSize-1;
    while ( front < tail ) {
        max_area = max(max_area, (tail - front) * (min(height[tail], height[front])));
        if (height[tail] > height[front]) {
            front ++;
        } else {
            tail --;
        }
    }
    return max_area;
}

int maxArea1(int* height, int heightSize){
    int max_area = 0;
    for (int i = 0; i < heightSize-1; ++i) {
        for (int j = i+1; j < heightSize; ++j) {
            max_area = max(max_area, (j-i) * min(height[i], height[j]));
        }
    }
    return max_area;
}

int main() {

    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = 9;

    printf("%d\n", maxArea(arr, size));

    return 0;
}

