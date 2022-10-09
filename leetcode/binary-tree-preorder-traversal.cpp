#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count = 0;

void _DLR(struct TreeNode *root, int * res) {
    if (NULL == root) return ;

    res[count++] = root->val;
    _DLR(root->left, res);
    _DLR(root->right, res);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    count = 0;

    int * res = (int*)calloc(101, sizeof(int));

    _DLR(root, res);

    *returnSize = count;
    return res;
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

    int size = 0;
    int * res = preorderTraversal(&p0, &size);
    for (int i = 0; i < size; ++i) printf("%d ", res[i]);
    putchar('\n');

    return 0;
}

