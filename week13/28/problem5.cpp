#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }

    int helper(TreeNode* node, int currMin, int currMax) {
        if (!node) return currMax - currMin;
        currMin = min(currMin, node->val);
        currMax = max(currMax, node->val);
        return max(helper(node->left, currMin, currMax), helper(node->right, currMin, currMax));
    }
};