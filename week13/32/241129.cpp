/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        dfs(root, ans);
        return ans;
    }

    pair<int, int> dfs(TreeNode* node, int& ans) {
        if (node == nullptr) {
            return {INT_MAX, INT_MIN};
        }
        pair<int, int> left = dfs(node->left, ans);
        pair<int, int> right = dfs(node->right, ans);

        int minVal = min(node->val, min(left.first, right.first));
        int maxVal = max(node->val, max(left.second, right.second));

        ans = max({ans, abs(minVal-node->val), abs(maxVal-node->val)});
        return {minVal, maxVal};
    }
};