#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    // 头节点
    struct ListNode * new_head = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode * work = new_head;

    while(l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            work->next = l2;
            work = work->next;
            l2 = l2->next;
        } else {
            work->next = l1;
            work = work->next;
            l1 = l1->next;
        }
    }

    if (l1 == NULL) {
        work->next = l2;
    }
    if (l2 == NULL) {
        work->next = l1;
    }
    return new_head->next;
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

    struct ListNode * p11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p33 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p44 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p11->val = 1;
    p22->val = 2;
    p33->val = 3;
    p44->val = 4;
    p11->next = p22;
    p22->next = p33;
    p33->next = p44;
    p44->next = NULL;

    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    temp = p11;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");


    struct ListNode *new_head = mergeTwoLists(p1, p11);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
