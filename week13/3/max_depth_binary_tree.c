/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    // Base Case: tree is empty
    if (root == NULL) {
        return 0; // depth is 0
    }

    // Recursively find the maximum depth of the left subtree
    int leftDepth = maxDepth(root->left);

    // Recursively find the maximum depth of the right subtree
    int rightDepth = maxDepth(root->right);

    // Maximum depth of the current node
    // : greater depth between the two subtrees + 1
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    // Allocate memory for the new node
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the node with the given value
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {
    // Example 1: Create the binary tree [3,9,20,null,null,15,7]
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    // Test maxDepth function
    printf("Maximum Depth of the Tree: %d\n", maxDepth(root)); // Output: 3

    // Example 2: Create the binary tree [1,null,2]
    struct TreeNode* root2 = newNode(1);
    root2->right = newNode(2);

    // Test maxDepth function
    printf("Maximum Depth of the Tree: %d\n", maxDepth(root2)); // Output: 2

    return 0;
}