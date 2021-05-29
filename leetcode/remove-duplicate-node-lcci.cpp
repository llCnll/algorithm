#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if (head == NULL) return NULL;

    int mark[20001] = {0};
    mark[head->val] ++;
    struct ListNode* temp = head;
    while (head->next != NULL) {
        if (mark[head->next->val]++ > 0) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
    return temp;
}

int main() {


    return 0;
}
