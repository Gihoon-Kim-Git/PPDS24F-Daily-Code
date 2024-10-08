#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* addNodes(int val) {
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int sumOfLeftLeavesHelper(struct TreeNode* root, int result) {
    if (root == NULL) {
        return result;
    }
    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) {
            result += root->left->val;
        } else {
            result = sumOfLeftLeavesHelper(root->left, result);
        }
    }
    if (root->right != NULL) {
        result = sumOfLeftLeavesHelper(root->right, result);
    }
    return result;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int result = 0;
    return sumOfLeftLeavesHelper(root, result);
}

int main() {
    struct TreeNode *root = addNodes(3);
    struct TreeNode *tree1 = addNodes(9);
    struct TreeNode *tree2 = addNodes(20);
    struct TreeNode *tree3 = addNodes(15);
    struct TreeNode *tree4 = addNodes(7);
    root->left = tree1;
    root->right = tree2;
    tree2->left = tree3;
    tree2->right = tree4;
    
    printf("%d\n", sumOfLeftLeaves(root));

    return 0;
}