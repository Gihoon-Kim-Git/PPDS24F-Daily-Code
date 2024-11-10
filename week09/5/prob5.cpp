#include <vector>
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        dfs_inorder(root, values);
        return values[k-1];
    }

    void dfs_inorder(TreeNode* curr, vector<int>& values) {
        // base case (nullptr) : do nothing
        if (curr == nullptr);
        // recursive case
        else {
            dfs_inorder(curr->left, values);
            values.push_back(curr->val);
            dfs_inorder(curr->right, values);
        }
    }
};