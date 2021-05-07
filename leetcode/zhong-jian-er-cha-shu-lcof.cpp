#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int preorder_index = 0;

struct TreeNode * buildLeft(int parent_inorder_index, int * preorder, int * vis, int left, int right, int * inorder);

struct TreeNode * buildRight(int parent_inorder_index, int * preorder, int * vis, int left, int right, int * inorder);

int findInOrderIndex(int val, int * inorder, int size) {
    for (int i = 0; i < size; ++i) {
        if (val == inorder[i]) {
            return i;
        }
    }
    return 0;
}

int hasLeft(int val_index, int * vis) {
    for (int i = val_index-1; i >= 0; --i) {
        if (vis[i] == 0) {
            return 1;
        }
    }
    return 0;
}

int hasRight(int val_index, int * vis, int size) {
    for (int i = val_index + 1; i < size; ++i) {
        if (vis[i] == 0) {
            return 1;
        }
    }
    return 0;
}

struct TreeNode * buildLeft(int parent_inorder_index, int * preorder, int * vis, int left, int right, int * inorder) {
    if (left > right) {
        return NULL;
    }

    if (!hasLeft(parent_inorder_index, vis)) {
        return NULL;
    }
    struct TreeNode * root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preorder_index++];

    int index = findInOrderIndex(root->val, inorder, right+1);
    vis[index] = 1;

    struct TreeNode * child_left = buildLeft(index, preorder, vis, 0, index-1, inorder);
    struct TreeNode * child_right = buildRight(index, preorder, vis, index+1, right, inorder);

    root->left = child_left;
    root->right = child_right;
    return root;
}


struct TreeNode * buildRight(int parent_inorder_index, int * preorder, int * vis, int left, int right, int * inorder) {
    if (left > right) {
        return NULL;
    }

    if (!hasRight(parent_inorder_index, vis, right+1)) {
        return NULL;
    }

    struct TreeNode * root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preorder_index++];

    int index = findInOrderIndex(root->val, inorder, right+1);
    vis[index] = 1;

    struct TreeNode * child_left = buildLeft(index, preorder, vis, 0, index-1, inorder);
    struct TreeNode * child_right = buildRight(index, preorder, vis, index+1, right, inorder);

    root->left = child_left;
    root->right = child_right;
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0) {
        return NULL;
    }
    int * vis = (int*)calloc(inorderSize, sizeof(int));
    struct TreeNode * root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = root->right = NULL;

    int index = findInOrderIndex(root->val, inorder, inorderSize);
    vis[index] = 1;

    preorder_index = 1;

    struct TreeNode * left = buildLeft(index, preorder, vis, 0, index-1, inorder);
    struct TreeNode * right = buildRight(index, preorder, vis, index+1, inorderSize-1, inorder);

    root->left = left;
    root->right = right;

    return root;
}

void DLR(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    DLR(root->left);
    DLR(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    struct TreeNode * root = buildTree(preorder, 5, inorder, 5);

    DLR(root);

    return 0;
}

