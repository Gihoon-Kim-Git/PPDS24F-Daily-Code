#include<iostream>

using namespace std;

//  Definition for a binary tree node.
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
        if(root == NULL){
            return 0;
        }

        int max_depth = 0;

        max_depth = max(max_depth, maxDepth(root->left));
        max_depth = max(max_depth, maxDepth(root->right));

        return max_depth + 1;
    }
};