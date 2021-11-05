#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = head;

    struct ListNode* pLow = pHead;
    struct ListNode* pFast = pHead;

    while(n--) {
        pFast = pFast->next;
    }

    while (pFast->next != NULL) {
        pFast = pFast->next;
        pLow = pLow->next;
    }

    pLow->next = pLow->next->next;

    return pHead->next;
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 1;
    p2->val = 2;
    p3->val = 2;
    p4->val = 4;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;


    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");


    struct ListNode *new_head = removeNthFromEnd(p1, 2);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
