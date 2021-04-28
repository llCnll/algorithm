#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool __isSymmetric(struct TreeNode * left_root, struct TreeNode * right_root){
    if (left_root == NULL && right_root == NULL) {
        return true;
    }
    if (left_root == NULL || right_root == NULL) {
        return false;
    }
    if (left_root->val != right_root->val) {
        return false;
    }
    return __isSymmetric(left_root->left, right_root->right) && __isSymmetric(left_root->right, right_root->left);
}

bool isSymmetric(struct TreeNode* root){
    return __isSymmetric(root, root);
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

    printf("%d\n", isSymmetric(&p0));

    return 0;
}

