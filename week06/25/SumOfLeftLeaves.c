#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
    int result = 0;
    // base case(1) : no child
    if (root->left == NULL || root->right == NULL) {
        return 0;
    }
    // recursion about right child
    if (root->right) {result += sumOfLeftLeaves(root->right);}

    if (root->left->left) {result += sumOfLeftLeaves(root->left);}
    if (root->left->right) {result += sumOfLeftLeaves(root->right);}
    // base case(2) : target found
    if ((!root->left->left) && (!root->left->right)) {result += root->left->val;}
    
    return result;
}