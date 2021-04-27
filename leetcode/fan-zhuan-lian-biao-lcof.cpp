#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    // 头节点
    struct ListNode * new_head = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode *next = new_head->next = NULL;

    while(head != NULL) {
        next = new_head->next;
        new_head->next = head;
        head = head->next;
        new_head->next->next = next;
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


    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");


    struct ListNode *new_head = reverseList(p1);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
