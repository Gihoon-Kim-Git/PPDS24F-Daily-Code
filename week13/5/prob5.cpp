#include <algorithm>
#include <cmath>
using namespace std;

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
        return helper(root, root->val, root->val, -1);
    }

    int helper(TreeNode* node, int anc_largest, int anc_smallest, int diff_largest) {
        // base case : NIL
        if (node == nullptr) {
            return diff_largest;
        }
        // recursive case
        else {
            int diff_curr = max(abs(anc_largest - node->val), abs(anc_smallest - node->val));
            diff_largest = max(diff_largest, diff_curr);

            if (node->val > anc_largest) anc_largest = node->val;
            if (node->val < anc_smallest) anc_smallest = node->val;
            int left = helper(node->left, anc_largest, anc_smallest, diff_largest);
            int right = helper(node->right, anc_largest, anc_smallest, diff_largest);
            return max(left, right);
        }
    }
};
