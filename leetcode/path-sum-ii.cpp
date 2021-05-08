#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count = 0;

void dfs(struct TreeNode* root, int target, int * temp_arr, int temp_index, int ** returnColumnSizes, int ** ans) {
    if (root == NULL) {
        return ;
    }
    temp_arr[temp_index++] = root->val;
    target -= root->val;
    if (root->left == NULL && root->right == NULL) {
        if (target == 0) {
            // 记录
            returnColumnSizes[0][count] = temp_index;
            ans[count] = (int*)calloc(temp_index, sizeof(int));
            memcpy(ans[count], temp_arr, sizeof(int)*temp_index);
            count++;
        }
        return ;
    }
    dfs(root->left, target, temp_arr, temp_index, returnColumnSizes, ans);
    dfs(root->right, target, temp_arr, temp_index, returnColumnSizes, ans);
}

int** pathSum(struct TreeNode* root, int target, int* returnSize, int** returnColumnSizes){
    count = 0;
    *returnSize = 0;
    int ** ans = (int**)malloc(sizeof(int*)*1010);
    int * temp_arr = (int*)calloc(10010, sizeof(int));
    *returnColumnSizes = (int*)calloc(1010, sizeof(int));
    dfs(root, target, temp_arr, 0, returnColumnSizes, ans);

    *returnSize = count;
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

    p0.val = 5;
    p1.val = 1;
    p2.val = 1;
    p3.val = 4;
    p4.val = 3;
    p5.val = -2;
    p6.val = 3;

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

    int ** arr = pathSum(&p2, 4, &returnSize, &returnColumnSizes);

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

