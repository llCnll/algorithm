#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    while (m > 0 && n > 0) {
        if (nums1[m-1] > nums2[n-1]) {
            nums1[--nums1Size] = nums1[m-1];
            m--;
        } else {
            nums1[--nums1Size] = nums2[n-1];
            n--;
        }
    }

    if (m > 0) {
        while (m) {
            nums1[--nums1Size] = nums1[m-1];
            m--;
        }
    }

    if (n > 0) {
        while (n) {
            nums1[--nums1Size] = nums2[n-1];
            n--;
        }
    }
    return ;
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};

    merge(nums1, 6, 3, nums2, 3, 3);

    for (int i = 0; i < 6; ++i) {
        printf("%d ", nums1[i]);
    }

    return 0;
}

