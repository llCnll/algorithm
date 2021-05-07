#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int deep = 0;

void dfs(struct TreeNode* root, int ** ans, int current_deep, int ** returnColumnSizes) {
    if(root == NULL) {
        return ;
    }

    if (current_deep + 1 > deep) {
        deep = current_deep+1;
    }

    ans[current_deep][(*returnColumnSizes)[current_deep] ++] = root->val;

    dfs(root->left, ans, current_deep+1, returnColumnSizes);
    dfs(root->right, ans, current_deep+1, returnColumnSizes);
}

// *returnSize 树高, *returnColumnSizes 每层个数
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    deep = 0;
    if (root == NULL) {
        * returnSize = 0;
        return NULL;
    }
    int** ans = (int**)malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; ++i) {
        ans[i] = (int*)calloc(1000, sizeof(int));
    }

    *returnColumnSizes = (int*)calloc(1000, sizeof(int));

    dfs(root, ans, 0, returnColumnSizes);

    *returnSize = deep;

    for (int i = 1; i < *returnSize; i+=2) {
        for (int j = 0; j < returnColumnSizes[0][i]/2; ++j) {
            int temp = ans[i][j];
            ans[i][j] = ans[i][returnColumnSizes[0][i]-j-1];
            ans[i][returnColumnSizes[0][i]-j-1] = temp;
        }
    }
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

    p0.val = 3;
    p1.val = 1;
    p2.val = 4;
    p3.val = 7;
    p4.val = 9;
    p5.val = 5;
    p6.val = 2;

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
    int * returnColumnSizes = NULL;

    int ** arr = levelOrder(&p0, &returnSize, &returnColumnSizes);

    printf("returnSize = %d\n", returnSize);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d\t", arr[i][j]);
        }
        putchar('\n');
    }

    free(returnColumnSizes);
    free(arr);

    return 0;
}

