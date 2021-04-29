#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* common_node = NULL;

int LRD(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int val = 0;
    if (root == NULL) {
        return 0;
    }

    val += LRD(root->left, p, q);
    val += LRD(root->right, p, q);

    if (root == p) {
        val += 1;
    }
    if (root == q) {
        val += 2;
    }
    if (val == 3 && common_node == NULL) {
        common_node = root;
    }
    return val;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){

    common_node = NULL;

    LRD(root, p, q);

    return common_node;
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
    p3.val = 0;
    p4.val = 8;
    p5.val = 7;
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

    lowestCommonAncestor(&p0, &p3, &p4);

    printf("%d\n", common_node->val);

    return 0;
}

