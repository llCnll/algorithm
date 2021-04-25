#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    // 头节点
    struct ListNode * new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next = head;
    struct ListNode * resverse_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * resverse_end = NULL;
    struct ListNode * resverse_start = new_head;
    struct ListNode * next = NULL;

    int index = 0;

    while(head != NULL && index+1 < left) {
        resverse_start = head;
        head = head->next;
        index++;
    }
    resverse_head->next = NULL;
    // 当前节点要接后面正序的
    resverse_end = head;

    while(head != NULL && index < right) {
        next = resverse_head->next;
        resverse_head->next = head;
        head = head->next;
        resverse_head->next->next = next;
        index ++;
    }
    resverse_end->next = head;
    resverse_start->next = resverse_head->next;
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

    struct ListNode *new_head = reverseBetween(p1, 1, 4);

    temp = new_head;

    printf("\nreverse finish\n");

    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
