#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxDepth(root) << endl;  // Output: 3

    // Free allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    return 0;
}
