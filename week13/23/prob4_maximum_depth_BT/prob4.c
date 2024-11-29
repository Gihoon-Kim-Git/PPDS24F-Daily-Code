#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

int main() {
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("%d\n", maxDepth(root));  // Output: 3

    // Free allocated memory
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
