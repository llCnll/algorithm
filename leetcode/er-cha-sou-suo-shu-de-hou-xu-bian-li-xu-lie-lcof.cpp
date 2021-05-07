#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool __verify(int * postorder, int start, int end) {
    if (start >= end) {
        return true;
    }
    // 寻找左右子树
    // 左子树根
    int left_index = start;
    while(postorder[left_index] < postorder[end]) left_index++;

    // 右子树根
    int right_index = left_index;
    while(postorder[right_index] > postorder[end]) right_index++;

    return right_index == end && __verify(postorder, start, left_index-1) && __verify(postorder, left_index==-1 ? -1 : left_index, end-1);
}

bool verifyPostorder(int* postorder, int postorderSize){
    if (postorderSize < 2) {
        return true;
    }
    return __verify(postorder, 0, postorderSize-1);
}

int main() {
    int arr[] = {1,2,5,10,6,9,4,3};

    printf("%d\n", verifyPostorder(arr, 8));

    return 0;
}

