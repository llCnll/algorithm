#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int __getDeep(struct TreeNode* root, int deep) {
    if (root == NULL) return deep;
    int rightDeep = __getDeep(root->left, deep+1);
    int leftDeep = __getDeep(root->right, deep+1);
    return rightDeep > leftDeep ? rightDeep : leftDeep;
}

int getDeep(struct TreeNode* root) {
    return __getDeep(root, 0);
}

void dfs(struct TreeNode* root, double * ans, int * column, int deep) {
    if(root == NULL) {
        return ;
    }

    ans[deep] += root->val;
    column[deep] ++;

    dfs(root->left, ans, column, deep+1);
    dfs(root->right, ans, column, deep+1);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        * returnSize = 0;
        return NULL;
    }
    int deep = getDeep(root);
    double* ans = (double*)calloc(deep, sizeof(double));
    int *column = (int*)calloc(deep, sizeof(int));

    dfs(root, ans, column, 0);

    for (int i = 0; i < deep; ++i) {
        ans[i] /= column[i];
    }

    *returnSize = deep;

    return ans;
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

    int returnSize = 0;
    double * ans = averageOfLevels(&p0, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%lf ", ans[i]);
    }

    return 0;
}

