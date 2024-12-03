/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <iostream>
#include <algorithm> // For std::max
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base Case: tree is empty
        if (root == nullptr) {
            return 0; // depth is 0
        }

        // Recursively find the maximum depth of the left subtree
        int leftDepth = maxDepth(root->left);

        // Recursively find the maximum depth of the right subtree
        int rightDepth = maxDepth(root->right);

        // Maximum depth of the current node
        // : greater depth between the two subtrees + 1
        return max(leftDepth, rightDepth) + 1;
    }
};

// Function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val); // Dynamically allocate a new TreeNode
    return node;
}

int main() {
    // Example 1: Create the binary tree [3,9,20,null,null,15,7]
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    // Test maxDepth function
    Solution solution;
    cout << "Maximum Depth of the Tree: " << solution.maxDepth(root) << endl; // Output: 3

    // Example 2: Create the binary tree [1,null,2]
    TreeNode* root2 = newNode(1);
    root2->right = newNode(2);

    // Test maxDepth function
    cout << "Maximum Depth of the Tree: " << solution.maxDepth(root2) << endl; // Output: 2

    return 0;
}