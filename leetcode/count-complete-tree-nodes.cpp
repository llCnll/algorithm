#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (a) > (b) ? (a) : (b)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxAns = 0;


void DLR(TreeNode *root, int deep) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->val);
    deep++;
    maxAns = max(deep, maxAns);

    DLR(root->left, deep);
    DLR(root->right, deep);
}

int maxDepth(struct TreeNode* root){
    if (NULL == root) return 0;

    maxAns = 0;
    DLR(root, 0);

    return maxAns;
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

    DLR(&p0,0);

    printf("\nafter\n");

    printf("\n\n%d\n", maxDepth(&p0));

    return 0;
}

