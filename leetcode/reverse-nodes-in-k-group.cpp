#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasKNode(struct ListNode * pHead, int k) {
    if (pHead == NULL) return false;
    pHead = pHead->next;
    while (k--) {
        if (pHead != NULL) {
            pHead = pHead->next;
        } else {
            return false;
        }
    }
    return true;
}

struct ListNode* reverseNextK(struct ListNode * pHead, int k) {
    // 判断是否剩余k个, 存在, 则返回第一个节点, 否则返回NULL.
    if (!hasKNode(pHead, k)) return NULL;
    struct ListNode* pLast = pHead->next;

    // 遍历k个. 将pLast->next插入到头节点前面
    // 只需移动k-1个
    while (--k) {
        struct ListNode * pWork = pLast->next;
        pLast->next = pWork->next;
        pWork->next = pHead->next;
        pHead->next = pWork;
    }
    return pLast;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pNode->next = head;

    struct ListNode * temp = pNode;
    while (temp != NULL) {
        temp = reverseNextK(temp, k);
    }

    struct ListNode * ans = pNode->next;
    return ans;
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

    struct ListNode* ans = reverseKGroup(p1, 5);

    while (ans) {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}

