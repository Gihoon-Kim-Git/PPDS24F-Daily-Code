#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree;
        tree = kthSmallestHelp(root, tree);
        return tree[k-1];
    }

    vector<int> kthSmallestHelp(TreeNode* root, vector<int> tree) {
        if (root == nullptr) return tree;
        if (root->left != nullptr) tree = kthSmallestHelp(root->left, tree);
        tree.push_back(root->val);
        if (root->right != nullptr) tree = kthSmallestHelp(root->right, tree);
        return tree;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *tree1 = new TreeNode(3);
    TreeNode *tree2 = new TreeNode(6);
    TreeNode *tree3 = new TreeNode(2);
    TreeNode *tree4 = new TreeNode(4);
    TreeNode *tree5 = new TreeNode(1);
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree3->left = tree5;
    
    Solution result;
    cout << result.kthSmallest(root, 3) << endl;

    return 0;
}