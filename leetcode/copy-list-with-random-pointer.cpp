#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *random;
};

struct ListNode* copyRandomList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode * temp = NULL;
    struct ListNode * result = NULL;

    struct ListNode * work = head;
    struct ListNode * new_work = NULL;

    while(work != NULL) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = work->val;
        temp->next = work->next;
        temp->random = work->random;

        work->next = temp;
        work = temp->next;
    }

    work = head;
    // 重置 random
    while (work != NULL) {
        work->next->random = work->random != NULL ? work->random->next : NULL;
        work = work->next->next;
    }


    work = head;
    result = new_work = work->next;

    // 复原 新旧链表
    while (work != NULL) {
        work->next = new_work->next;
        work = work->next;
        new_work->next = work != NULL ? work->next : NULL;
        new_work = new_work->next;
    }

    return result;
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p5->val = 5;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    p1->random = p5;
    p2->random = p1;
    p3->random = p2;
    p4->random = p3;
    p5->random = p4;


    struct ListNode *temp = p1;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");


    struct ListNode *new_head = copyRandomList(p1);

    temp = new_head;
    while(temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
