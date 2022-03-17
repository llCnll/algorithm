#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode * fast = head;
    int step = 1;
    while (fast) {
        if (0 == step%2) {
            head = head->next;
        }
        fast = fast->next;
        step++;
    }
    return head;
}

void tran(struct ListNode * head) {
    while (head) {
        printf("%d\t", head->val);
        head = head->next;
    }
    putchar('\n');
}

int main() {

    struct ListNode * p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    p1->val = 1;
    p2->val = 2;
    p3->val = 2;
    p4->val = 4;
    p5->val = 4;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    tran(p1);
    struct ListNode * ans = middleNode(p1);
    tran(ans);

    return 0;
}

