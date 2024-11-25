#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return maxDepthHelp(root, 1);
    }

    int maxDepthHelp(TreeNode* root, int depth) {
        int left = depth;
        int right = depth;
        if (root->left) left = maxDepthHelp(root->left, depth+1);
        if (root->right) right = maxDepthHelp(root->right, depth+1);
        return max(left, right);
    }
};

int main() {
    TreeNode *root = new TreeNode(3);;
    TreeNode *tree1 = new TreeNode(9);;
    TreeNode *tree2 = new TreeNode(20);;
    TreeNode *tree3 = new TreeNode(15);;
    TreeNode *tree4 = new TreeNode(7);;
    root->left = tree1;
    root->right = tree2;
    tree2->left = tree3;
    tree2->right = tree4;
    
    Solution result;
    cout << result.maxDepth(root) << endl;

    return 0;
}