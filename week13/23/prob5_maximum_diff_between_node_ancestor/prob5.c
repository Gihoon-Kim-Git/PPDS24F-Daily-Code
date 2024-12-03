#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int helper(TreeNode* node, int current_min, int current_max) {
    if (!node) {
        return current_max - current_min;
    }
    if (node->val < current_min) current_min = node->val;
    if (node->val > current_max) current_max = node->val;
    
    int left_diff = helper(node->left, current_min, current_max);
    int right_diff = helper(node->right, current_min, current_max);
    
    return (left_diff > right_diff) ? left_diff : right_diff;
}

int maxAncestorDiff(TreeNode* root) {
    return helper(root, root->val, root->val);
}

int main() {
    TreeNode* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    printf("%d\n", maxAncestorDiff(root));  // Output: 7

    // Free memory
    free(root->left->left);
    free(root->left->right->left);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right->right->left);
    free(root->right->right);
    free(root->right);
    free(root);
    return 0;
}
