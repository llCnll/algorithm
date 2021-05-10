#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

const int NODE_MAX = -9999;

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    char * ans = (char*)calloc(100000, sizeof(char));

    struct TreeNode* queue[20100];
    int start = 0;
    int end = 0;

    queue[end++] = root;
    char temp[10];
    while(start < end) {
        if (queue[start] == NULL) {
            sprintf(temp, "%d#", NODE_MAX);
            strcat(ans, temp);
        } else {
            sprintf(temp, "%d#", queue[start]->val);
            strcat(ans, temp);
            queue[end++] = queue[start]->left;
            queue[end++] = queue[start]->right;
        }
        start++;
    }
    return ans;
}

int getDigit(char * data, int start, int end) {
    int sign = 1;
    int sum = 0;

    for (int i = start; i < end; ++i) {
        if (data[i] == '-') {
            sign = -1;
            continue;
        }
        sum = sum * 10 + data[i] - '0';
    }
    return sign * sum;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (strlen(data) == 0) {
        return NULL;
    }

    struct TreeNode* queue[20100];
    int start_queue = 1;

    int start = 0;

    for (int i = 0; i <= strlen(data); ++i) {
        if (data[i] == '#') {
            int digit = getDigit(data, start, i);
            if (digit == NODE_MAX) {
                queue[start_queue++] = NULL;
            } else {
                struct TreeNode * temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                temp->val = digit;
                temp->left = NULL;
                temp->right = NULL;
                queue[start_queue++] = temp;
            }
            start = i+1;
        }
    }

    int empty_count = 0;
    for (int i = 1; i < start_queue; ++i) {
        if (queue[i] == NULL) {
            empty_count += 2;
            continue;
        }
        if (2 * i - empty_count < start_queue) {
            queue[i]->left = queue[2*i - empty_count];
        }
        if (2 * i + 1 - empty_count < start_queue) {
            queue[i]->right = queue[2*i + 1 - empty_count];
        }
    }
    return queue[1];
}

void DLR(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    DLR(root->left);
    DLR(root->right);
}

int main() {
    //char r[] = "4#2#2#1#3#3#1#-999999#-999999#-999999#-999999#-999999#-999999#-999999#-999999#";
    char r[] = "5#2#3#-999999#-999999#2#4#3#1#";

    struct TreeNode * root = deserialize(r);
    DLR(root);

    char * s = serialize(root);
    printf("\n%s\n", s);

    root = deserialize(s);
    DLR(root);

    free(s);
    return 0;
}

