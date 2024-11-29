#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* node, int current_min, int current_max) {
    if (!node) {
        return current_max - current_min;
    }
    current_min = min(current_min, node->val);
    current_max = max(current_max, node->val);
    
    int left_diff = helper(node->left, current_min, current_max);
    int right_diff = helper(node->right, current_min, current_max);
    
    return max(left_diff, right_diff);
}

int maxAncestorDiff(TreeNode* root) {
    return helper(root, root->val, root->val);
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << maxAncestorDiff(root) << endl;  // Output: 7
    
    return 0;
}
