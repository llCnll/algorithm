#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char * createPath(int * temp, int deep) {
    char * ans = (char*)calloc(1000, sizeof(char));

    int len = 0;
    for (int i = 0; i < deep; ++i) {
        len += sprintf(ans + len, "%d->", temp[i]);
    }

    sprintf(ans + len, "%d", temp[deep]);
    return ans;
}

void RDL(struct TreeNode *root, int deep, int * temp, char ** ans, int * returnSize) {
    if (NULL == root) return ;
    temp[deep] = root->val;
    if (root->left == NULL && root->right == NULL) {
        strcpy(ans[*returnSize], createPath(temp, deep));
        (*returnSize) ++;
        return;
    }
    RDL(root->left, deep+1, temp, ans, returnSize);
    RDL(root->right, deep+1, temp, ans, returnSize);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (NULL == root) return NULL;

    char ** ans = (char**)malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; ++i) 
        ans[i] = (char*)calloc(1000, sizeof(char));

    int * temp = (int*)calloc(100, sizeof(int));


    RDL(root, 0, temp, ans, returnSize);

    return ans;
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

    int size = 0;

    char ** ans = binaryTreePaths(&p0, &size);

    for (int i = 0; i < size; ++i) {
        printf("%s\n", ans[i]);
    }

    return 0;
}

