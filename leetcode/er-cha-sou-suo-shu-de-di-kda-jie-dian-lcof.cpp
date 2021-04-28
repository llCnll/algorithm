#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int top_k;

void RDL(struct TreeNode * root, int *k) {
    if (root == NULL || *k == 0) {
        return;
    }

    RDL(root->right, k);
    if (--(*k) == 0) {
        top_k = root->val;
        return;
    }
    RDL(root->left, k);
}

int kthLargest(struct TreeNode* root, int k){
    top_k = 0;

    RDL(root, &k);

    return top_k;
}

void DLR(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->val);
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
    p2.val = 5;
    p3.val = 1;
    p4.val = 3;
    p5.val = 6;
    p6.val = 7;

    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;

    p3.left = p3.right = p4.left = p4.right = p5.right = p5.left = p6.left = p6.right = NULL;

    DLR(&p0);

    printf("\nafter\n");

    printf("%d\n", kthLargest(&p0, 3));

    return 0;
}

