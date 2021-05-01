#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA,  *b = headB;
    while(a != NULL || b != NULL) {
        if (a == b) {
            return a;
        }
        if (a == NULL) {
            a = headB;
        } else {
            a = a->next;
        }
        if (b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }
    return NULL;
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 4;
    p2->val = 1;
    p3->val = 8;
    p4->val = 4;
    p5->val = 5;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    struct ListNode * p6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p8 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p6->val = 5;
    p7->val = 0;
    p8->val = 1;
    p6->next = p7;
    p7->next = p8;
    p8->next = p3;

    struct ListNode * node = getIntersectionNode(p1, p6);
    if (node == NULL) {
        printf("no node\n");
    } else {
        printf("%d\n", node->val);
    }


    return 0;
}

