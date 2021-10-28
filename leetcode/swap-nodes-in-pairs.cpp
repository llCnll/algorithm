#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNext2(struct ListNode* head) {
    if (head->next == NULL) {
        return NULL;
    }

    struct ListNode * one = head->next;
    if (one->next == NULL) {
        return NULL;
    }
    struct ListNode * two = one->next;

    head->next = two;
    one->next = two->next;
    two->next = one;

    return one;
}

struct ListNode* swapPairs(struct ListNode* head){
    // 头节点
    struct ListNode * pNode = (struct ListNode *)malloc(sizeof(struct ListNode));

    pNode->next = head;
    // 工作指针
    struct ListNode * pWork = pNode;

    while (pWork != NULL) {
        pWork = swapNext2(pWork);
    }

    return pNode->next;
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
    p3->next = NULL;
    p4->next = NULL;


    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");


    struct ListNode *new_head = swapPairs(p1);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
