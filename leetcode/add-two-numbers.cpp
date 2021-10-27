#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * work = result;

    int carry = 0;

    while (l1 != NULL && l2 != NULL) {
        work->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        work->next->next = NULL;
        int value = l1->val + l2->val + carry;
        carry = 0;
        if (value >= 10) {
            carry = 1;
            value -= 10;
        }
        work->next->val = value;
        l1 = l1->next;
        l2 = l2->next;
        work = work->next;
    }

    while (l1 != NULL) {
        work->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        work->next->next = NULL;
        int value = l1->val + carry;
        carry = 0;
        if (value >= 10) {
            carry = 1;
            value -= 10;
        }
        work->next->val = value;
        l1 = l1->next;
        work = work->next;
    }

    while (l2 != NULL) {
        work->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        work->next->next = NULL;
        int value = l2->val + carry;
        carry = 0;
        if (value >= 10) {
            carry = 1;
            value -= 10;
        }
        work->next->val = value;
        l2 = l2->next;
        work = work->next;
    }

    if (carry != 0) {
        work->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        work->next->next = NULL;
        work->next->val = 1;
    }

    return result->next;
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 9;
    p2->val = 2;
    p3->val = 3;
    p4->val = 9;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;

    struct ListNode * p11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p21 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p31 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p41 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p11->val = 4;
    p21->val = 3;
    p31->val = 2;
    p41->val = 1;
    p11->next = p21;
    p21->next = p31;
    p31->next = p41;
    p41->next = NULL;

    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");
    temp = p11;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");

    printf("\nafter\n");


    struct ListNode *new_head = addTwoNumbers(p1, p11);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
