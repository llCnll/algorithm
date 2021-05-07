#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* levelOrder(struct TreeNode* root, int* returnSize){
    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    int * result = (int*)calloc(1010, sizeof(int));
    //struct TreeNode * queue = (struct TreeNode *)malloc(1000 * sizeof(struct TreeNode));

    struct TreeNode* queue[1010];

    int start = 0;
    int end = 0;

    queue[end++] = root;

    while (start != end) {
        if (queue[start]->left != NULL) queue[end++] = queue[start]->left;
        if (queue[start]->right != NULL) queue[end++] = queue[start]->right;
        result[(*returnSize)++] = queue[start++]->val;
    }

    return result;
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
    int returnSize = 0;
    int * arr = levelOrder(&p0, &returnSize);

    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t", arr[i]);
    }

    free(arr);
    return 0;
}

