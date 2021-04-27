#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* reversePrint(struct ListNode* head, int* returnSize){
    *returnSize = 0;

    struct ListNode* work = head;
    while(work != NULL) {
        work = work->next;
        (*returnSize) ++;
    }

    int * arr = (int*)malloc(sizeof(int) * *returnSize);

    work = head;
    for (int i = *returnSize-1; i >= 0 && work != NULL; --i) {
        arr[i] = work->val;
        work = work->next;
    }

    return arr;
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;

    int size = 0;
    int * arr = reversePrint(p1, &size);
    printf("size = %d\n", size);

    for(int i = 0; i < size; ++i) {
        printf("%d\t", arr[i]);
    }

    free(arr);

    return 0;
}
