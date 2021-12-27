#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* getLastRgiht(struct TreeNode * root) {
    if (root->right == NULL) return root;
    return getLastRgiht(root->right);
}

void flatten(struct TreeNode* root){
    if (root == NULL) return ;

    struct TreeNode * left = root->left;
    struct TreeNode * right = root->right;

    if (left != NULL) {
        struct TreeNode * temp = getLastRgiht(left);
        temp->right = right;
        root->right = left;
        root->left = NULL;
    }
    flatten(root->right);
}

void DLR(struct TreeNode *root) {
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

    p0.val = 1;
    p1.val = 2;
    p2.val = 3;
    p3.val = 4;
    p4.val = 5;
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

    flatten(&p0);

    DLR(&p0);

    return 0;
}

