#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode * fast = head;
    struct ListNode * slow = head;
    while (fast != NULL) {
        if (fast->next == NULL) {
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }
    slow = head;
    while (fast != NULL) {
        if (fast == slow) {
            return fast;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
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
    p2->next = NULL;
    p3->next = p4;
    p4->next = p2;


    //struct ListNode *temp = p1;
    //while(temp != NULL) {
    //    printf("%d\t", temp->val);
    //    temp = temp->next;
    //}
    struct ListNode * ans = detectCycle(p1);
    printf("\nresult = %d\n", ans == NULL ? -1 : ans->val);

    return 0;
}
