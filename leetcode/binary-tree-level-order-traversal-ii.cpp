#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX 2000
#define max(a, b) (a) > (b) ? (a) : (b)

struct TreeNodeWrap {
    struct TreeNode * pNode;
    int deep;
};

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (NULL == root) {
        *returnSize = 0;
        return NULL;
    }

    int ** ans = (int**)malloc(sizeof(int *) * MAX);
    for (int i = 0; i < MAX; ++i) {
        ans[i] = (int*)calloc(MAX, sizeof(int));
    }
    *returnColumnSizes = (int *)calloc(MAX, sizeof(int));

    int maxDeep = 0;

    struct TreeNodeWrap queue[MAX];
    int front = 0, tail = 0;

    struct TreeNodeWrap temp;
    temp.pNode = root;
    temp.deep = 0;
    queue[tail++] = temp;

    while (front != tail) {
        temp = queue[front++];
        // 赋值
        ans[temp.deep][(*returnColumnSizes)[temp.deep]++] = temp.pNode->val;
        printf("%d\n", temp.pNode->val);

        if (NULL != temp.pNode->left) {
            struct TreeNodeWrap left;
            left.pNode = temp.pNode->left;
            left.deep = temp.deep+1;
            maxDeep = max(maxDeep, left.deep);
            queue[tail++] = left;
        }
        if (NULL != temp.pNode->right) {
            struct TreeNodeWrap right;
            right.pNode = temp.pNode->right;
            right.deep = temp.deep+1;
            maxDeep = max(maxDeep, right.deep);
            queue[tail++] = right;
        }
    }
    *returnSize = maxDeep + 1;

    // 翻转
    for (int i = 0; i < (*returnSize) / 2; ++i) {
        int start = i, end = *returnSize - start -1;
        // 翻转结果集
        int * temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;

        // 翻转列集
        int t = (*returnColumnSizes)[start];
        (*returnColumnSizes)[start] = (*returnColumnSizes)[end];
        (*returnColumnSizes)[end] = t;
    }

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
    int * returnColumn;
    int ** ans = levelOrderBottom(&p0, &returnSize, &returnColumn);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumn[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

