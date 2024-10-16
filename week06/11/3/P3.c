#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};

int help(struct TreeNode* root, struct TreeNode* par){
    if(!root){
        return 0;
    }
    else if(!root->left && !root->right && par && root == par->left){
        return root->val;
    }
    return help(root->left, root) + help(root->right, root);
}
 
int sumOfLeftLeaves(struct TreeNode* root) {
    return help(root, NULL);
}



int main(void) {
    // Test Case: Tree with a single left leaf
    //       3
    //      / \
    //     9  20
    //        / \
    //       15  7
    
    struct TreeNode n15 = {15, NULL, NULL};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n20 = {20, &n15, &n7};
    struct TreeNode root = {3, &n9, &n20};

    printf("Sum of left leaves: %d\n", sumOfLeftLeaves(&root)); // Expected output: 24
    return 0;
}