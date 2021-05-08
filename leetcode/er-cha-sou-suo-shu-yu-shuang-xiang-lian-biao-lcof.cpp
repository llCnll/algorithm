#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * get_last(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct TreeNode * get_start(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void build(struct TreeNode * root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode * last = get_last(root->left);
    struct TreeNode * start = get_start(root->right);

    build(root->left);
    build(root->right);

    if (last != NULL) last->right = root;
    if (start != NULL) start->left = root;

    root->left = last;
    root->right = start;
}

struct TreeNode * treeToDoublyList(struct TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode * start = get_start(root);
    struct TreeNode * last = get_last(root);

    build(root);

    start->left = last;
    last->right = start;

    return start;
}

void DLR(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    DLR(root->left);
    DLR(root->right);
}

int main() {

    struct TreeNode p0;
    struct TreeNode p1;
    struct TreeNode p2;
    struct TreeNode p3;
    struct TreeNode p4;
    struct TreeNode p5;
    struct TreeNode p6;

    p0.val = 4;
    p1.val = 2;
    p2.val = 6;
    p3.val = 1;
    p4.val = 3;
    p5.val = 5;
    p6.val = 7;

    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;

    p3.left = p3.right = p4.left = p4.right = p5.right = p5.left = p6.left = p6.right = NULL;

    DLR(&p0);
    putchar('\n');

    struct TreeNode * head = treeToDoublyList(&p0);

    struct TreeNode * work = head;

    do {
        printf("%d\t", work->val);
        work = work->right;
    } while(work != NULL && work->val != head->val);

    return 0;
}

