#include <algorithm>
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
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* node, int small, int big) {
        if (!node) return big - small;
        small = min(node->val, small);
        big = max(node->val, big);
        int left = dfs(node->left, small, big);
        int right = dfs(node->right, small, big);
        return max(left, right);
    }
};