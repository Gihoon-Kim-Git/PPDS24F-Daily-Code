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
    int sumOfLeftLeaves(struct TreeNode* root) {
        int result = 0;
        return sumOfLeftLeavesHelper(root, result);
    }

    int sumOfLeftLeavesHelper(struct TreeNode* root, int result) {
        if (root == NULL) {
            return result;
        }
        if (root->left != NULL) {
            if (root->left->left == NULL && root->left->right == NULL) {
                result += root->left->val;
            } else {
                result = sumOfLeftLeavesHelper(root->left, result);
            }
        }
        if (root->right != NULL) {
            result = sumOfLeftLeavesHelper(root->right, result);
        }
        return result;
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
    cout << result.sumOfLeftLeaves(root) << endl;

    return 0;
}