#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
      return (x > y) ? x : y;
}

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

int maxDepthHelp(struct TreeNode* root, int depth) {
    int left = depth;
    int right = depth;
    if (root->left != NULL) left = maxDepthHelp(root->left, depth+1);
    if (root->right != NULL) right = maxDepthHelp(root->right, depth+1);
    return max(left, right);
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    return maxDepthHelp(root, 1);
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
    
    printf("%d\n", maxDepth(root));

    return 0;
}