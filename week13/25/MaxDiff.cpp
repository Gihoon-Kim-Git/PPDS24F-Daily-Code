#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
//Definition for a binary tree node.
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
        // recursive function call
        return helper(root, root->val, root->val);
    }

private:
    int helper(TreeNode* node, int currMax, int currMin) {
        // condition of termination
        if (node == nullptr) {
            return currMax - currMin;
        }

        // update max and min value using current node's value
        currMax = max(currMax, node->val);
        currMin = min(currMin, node->val);

        // search left and right tree recursively
        int leftDiff = helper(node->left, currMax, currMin);
        int rightDiff = helper(node->right, currMax, currMin);

        // return Maximum
        return max(leftDiff, rightDiff);
    }
};

