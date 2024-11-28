/*"""Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
"""

"""아이디어
    recursive하게.
    현재의 depth는 left_subtree, right_subtree의 depth 중 더 큰 값 + 1
    depth(cur) = max(depth(cur->left), depth(cur->right)) + 1
"""*/


#include <iostream> 
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_depth = root->left  ? maxDepth(root->left) : 0;
        int right_depth = root->right ? maxDepth(root->right) : 0;
        int longer_depth = left_depth > right_depth ? left_depth : right_depth;
        return longer_depth + 1;
    }
};