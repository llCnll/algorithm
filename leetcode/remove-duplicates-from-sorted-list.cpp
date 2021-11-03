#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = head;

    struct ListNode* pLow = pHead;
    pLow->next = NULL;
    struct ListNode* pFast = head;

    while (pFast->next != NULL) {
        if (pFast->val == pFast->next->val) {
            pFast = pFast->next;
        } else {
            pLow->next = pFast;
            pLow = pFast;
            pFast = pFast->next;
            pLow->next = NULL;
        }
    }
    if (pLow != pFast) {
        pLow->next = pFast;
        pLow = pFast;
        pLow->next = NULL;
    }

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


    struct ListNode *new_head = deleteDuplicates(p1);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
