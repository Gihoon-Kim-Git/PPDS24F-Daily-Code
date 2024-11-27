#include <iostream>
#include <vector>
#include <queue>

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
        return help(root, root->val, root->val);
    }

    int help(TreeNode* cur, int big, int small){
        if (!cur){
            return big - small;
        }
        int b = max(big, cur->val);
        int s = min(small, cur->val);

        int ld = help(cur->left, b, s);
        int rd = help(cur->right, b, s);

        return max(ld, rd);
    }
};