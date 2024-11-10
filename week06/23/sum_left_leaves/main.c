#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function prototype for dfs
void dfs(struct TreeNode* node, int isLeft, int* total);

// Function to find the sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    int total = 0;
    dfs(root, 0, &total); // Start the DFS traversal with root, isLeft = 0 (not a left child)
    return total;
}

// Helper function to perform DFS
void dfs(struct TreeNode* node, int isLeft, int* total) {
    if (!node) return;

    // If it's a leaf node and it's a left child
    if (!node->left && !node->right && isLeft) {
        *total += node->val;
    }

    // Recursively check left and right children
    dfs(node->left, 1, total);  // isLeft = 1 for left child
    dfs(node->right, 0, total); // isLeft = 0 for right child
}

// Driver code to test the function
int main() {
    // Create a binary tree
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    // Test the sumOfLeftLeaves function
    int result = sumOfLeftLeaves(root);
    printf("Sum of left leaves: %d\n", result);  // Output should be 24 (9 + 15)

    // Clean up dynamically allocated memory
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
