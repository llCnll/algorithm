#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int deep(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_deep = deep(root->left);
    int right_deep = deep(root->right);
    return max(left_deep, right_deep) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    if (abs(deep(root->left) - deep(root->right)) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
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
    p2.val = 2;
    p3.val = 1;
    p4.val = 3;
    p5.val = 3;
    p6.val = 1;

    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;

    p3.left = p3.right = p4.left = p4.right = p5.right = p5.left = p6.left = p6.right = NULL;

    DLR(&p0);

    printf("\nafter\n");

    printf("%d\n", isBalanced(&p0));

    return 0;
}

