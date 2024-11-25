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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return AncestorHelp(root)[2];
    }

    vector<int> AncestorHelp(TreeNode* root) {
        int minleft = root->val;
        int maxleft = root->val;
        int minright = root->val;
        int maxright = root->val;
        int difleft = 0;
        int difright = 0;
        vector<int> left = {minleft, maxleft, difleft};
        vector<int> right = {minright, maxright, difright};
        if (root->left)
            left = AncestorHelp(root->left);
        if (root->right)
            right = AncestorHelp(root->right);
        int minval = min(min(root->val, left[0]), right[0]);
        int maxval = max(max(root->val, left[1]), right[1]);
        int maxdiff = max(root->val - minval, maxval - root->val);
        maxdiff = max(max(maxdiff, left[2]), right[2]);
        return {minval, maxval, maxdiff};
    }
};

int main() {
    TreeNode *root = new TreeNode(8);
    TreeNode *tree1 = new TreeNode(3);
    TreeNode *tree2 = new TreeNode(10);
    TreeNode *tree3 = new TreeNode(1);
    TreeNode *tree4 = new TreeNode(6);
    TreeNode *tree5 = new TreeNode(14);
    TreeNode *tree6 = new TreeNode(4);
    TreeNode *tree7 = new TreeNode(7);
    TreeNode *tree8 = new TreeNode(13);
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree2->right = tree5;
    tree4->left = tree6;
    tree4->right = tree7;
    tree5->left = tree8;
    
    Solution result;
    cout << result.maxAncestorDiff(root) << endl;

    return 0;
}