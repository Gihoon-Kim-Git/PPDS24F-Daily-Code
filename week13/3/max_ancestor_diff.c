/*
Given the root of a binary tree, find the maximum value `v` for which there exist different nodes `a` and `b` such that:
  - `v = |a.val - b.val|`
  - `a` is an ancestor of `b`

Definition:
  A node `a` is an ancestor of `b` if:
    - Any child of `a` is equal to `b`, or
    - Any child of `a` is an ancestor of `b`.

Examples:
1. Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
   Output: 7
   Explanation:
     - Various ancestor-node differences include:
       |8 - 3| = 5
       |3 - 7| = 4
       |8 - 1| = 7
       |10 - 13| = 3
     - The maximum value is obtained by |8 - 1| = 7.

2. Input: root = [1,null,2,null,0,3]
   Output: 3
   Explanation:
     - Differences include:
       |1 - 2| = 1
       |2 - 0| = 2
       |2 - 3| = 1
       |1 - 0| = 1
       |1 - 3| = 3
     - The maximum value is 3.

Constraints:
  - The number of nodes in the tree is in the range [2, 5000].
  - 0 <= Node.val <= 10^5
*/

#include <stdlib.h>  // Memory allocation
#include <stdio.h>   // Input/Output
#include <limits.h>  // Min/Max limits
#include <stdbool.h> // Boolean values

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
/*
An ancestor is defined recursively (either the parent or in the lineage). -> IDEA: DFS
For each node, we need to compute the difference between its value and the values of all its ancestors.

1. root ~ curr node path: pass minimum & maximum values
2. at each node: calculate maximum difference between curr value and minimum / maximum -> update maximum difference
3. recursion: left & right children nodes
3. maximum difference from whole binary tree, between node and ancestor
*/

// DFS: recursive function
// start from the root node and traverse binary tree
int dfs(struct TreeNode* node, int min_val, int max_val) {
    // base case: reach leaf node -> return total maximum difference
    if (!node) {
        return max_val - min_val;
    }

    // pass state: maintain 2 variables
    // minimum value in the path until current node
    // maximum value in the path until current node

    // update state: for each node
    // maximum difference at current node: max(abs(node.val - min_val), abs(node.val - max_val))
    // update min_val & max_val with current node
    if (node->val < min_val) {
        min_val = node->val;
    }
    if (max_val < node->val) {
        max_val = node->val;
    }
    
    // recursive case: left and right children
    int left_diff = dfs(node->left, min_val, max_val);
    int right_diff = dfs(node->right, min_val, max_val);

    // return current maximum difference
    return left_diff > right_diff ? left_diff : right_diff;
}


int maxAncestorDiff(struct TreeNode* root) {
    return dfs(root, root->val, root->val);
}


// Create a new TreeNode
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Free the tree
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Create the sample tree [8,3,10,1,6,null,14,null,null,4,7,13]
struct TreeNode* createTree() {
    struct TreeNode* root = newTreeNode(8);
    root->left = newTreeNode(3);
    root->right = newTreeNode(10);
    
    root->left->left = newTreeNode(1);
    root->left->right = newTreeNode(6);
    root->left->right->left = newTreeNode(4);
    root->left->right->right = newTreeNode(7);
    
    root->right->right = newTreeNode(14);
    root->right->right->left = newTreeNode(13);

    return root;
}

// TreeNode creation omitted for brevity; build tree as needed
int main() {
    struct TreeNode* root = createTree();
    printf("%d\n", maxAncestorDiff(root));  // Output: 7
    freeTree(root);
    return 0;
}
