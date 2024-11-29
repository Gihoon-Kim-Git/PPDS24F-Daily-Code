/**
 * Definition for a binary tree node.
104. Maximum Depth of Binary Tree
Solved
Easy
Topics
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <iostream>

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
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return 1;
        }
        
        //int height = 1;
        int left=0;
        int right=0;
        if(root->left)
        {
            left = maxDepth(root->left) + 1;
        }
        if(root->right)
        {
            right = maxDepth(root->right) + 1;
        }
        int height = left > right ? left: right;
        return height;
    }
};