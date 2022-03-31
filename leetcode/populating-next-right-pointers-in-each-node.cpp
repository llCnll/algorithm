#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

#define MAX 100

struct NodeWrap {
    struct Node * pNode;
    int deep;
};

struct Node* connect(struct Node* root) {

    if (NULL == root) {
        return NULL;
    }
    struct Node * ans = root;

    struct NodeWrap queue[MAX];
    int front = 0, tail = 0;

    struct NodeWrap temp;
    temp.pNode = root;
    temp.deep = 0;
    queue[tail++] = temp;

    while (front != tail) {
        temp = queue[front++];
        // 赋值
        if (temp.deep == queue[front].deep) {
            temp.pNode->next = queue[front].pNode;
        } else {
            temp.pNode->next = NULL;
        }

        if (NULL != temp.pNode->left) {
            struct NodeWrap left;
            left.pNode = temp.pNode->left;
            left.deep = temp.deep+1;
            queue[tail++] = left;
        }
        if (NULL != temp.pNode->right) {
            struct NodeWrap right;
            right.pNode = temp.pNode->right;
            right.deep = temp.deep+1;
            queue[tail++] = right;
        }
    }

    return ans;
}

void DLR(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->val);
    DLR(root->left);
    DLR(root->right);
}

int main() {

    struct Node p0;
    struct Node p1;
    struct Node p2;
    struct Node p3;
    struct Node p4;
    struct Node p5;
    struct Node p6;

    p0.val = 4;
    p1.val = 2;
    p2.val = 7;
    p3.val = 1;
    p4.val = 3;
    p5.val = 6;
    p6.val = 9;

    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;

    p3.left = p3.right = p4.left = p4.right = p5.right = p5.left = p6.left = p6.right = NULL;

    DLR(&p0);

    printf("\nafter\n");
    struct Node * ans = connect(&p0);
    while (ans != NULL) {
        struct Node * temp = ans;
        while (temp != NULL) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        putchar('\n');
        ans = ans->left;
    }

    return 0;
}

