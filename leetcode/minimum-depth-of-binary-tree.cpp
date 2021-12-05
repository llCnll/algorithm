#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (a) < (b) ? (a) : (b)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int ans = 0x3f3f3f;

void dfs(struct TreeNode* root, int deep) {
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL) {
        ans = min(ans, deep);
        return ;
    }
    if (ans > deep+1) {
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }
}

int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    ans = 0x3f3f3f;
    dfs(root, 1);
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

    printf("ans = %d\n", minDepth(&p0));

    DLR(&p0);

    return 0;
}

