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
        // base case : empty tree
        if (root == nullptr) {
            return 0;
        }
        // recursive case
        else {
            int left = maxDepth(root->left) + 1;
            int right = maxDepth(root->right) + 1;
            return left > right? left : right;
        }
    }
};
