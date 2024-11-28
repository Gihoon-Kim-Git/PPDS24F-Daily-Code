#include<iostream>

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
    int maxAncestorDiff(TreeNode* root) {
        return max_find(root, root->val, root->val);
    }

    int max_find(TreeNode* root, int cur_max, int cur_min){
        if(root == NULL){
            return cur_max - cur_min;
        }
        int left_diff = 0;
        int right_diff = 0;

        // find max, min value
        cur_max = max(cur_max, root->val);
        cur_min = min(cur_min, root->val);

        // recursive for left and right subtrees
        left_diff = max_find(root->left, cur_max, cur_min);
        right_diff = max_find(root->right, cur_max, cur_min);

        // return the max diff found
        return max(left_diff, right_diff);
    }

};