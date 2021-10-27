#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode * fast = head->next;
    struct ListNode * slow = head;
    int i = 1;
    while (fast != NULL) {
        if (fast == slow) {
            return true;
        }
        if (0 == i++%2) {
            slow = slow->next;
        }
        fast = fast->next;
    }
    return false;
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
    p3->next = p1;
    p4->next = NULL;


    //struct ListNode *temp = p1;
    //while(temp != NULL) {
    //    printf("%d\t", temp->val);
    //    temp = temp->next;
    //}

    printf("\nresult = %d\n", hasCycle(p1));

    return 0;
}
