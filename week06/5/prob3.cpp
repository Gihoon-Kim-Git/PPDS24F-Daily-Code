/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // left subtree 에 대해 계산
        int leftChild = 0;
        if (root->left == nullptr) {
            // left subtree 가 empty 인 경우
            // do nothing (leftChild = 0)
        } else if ((root->left->left == nullptr) && (root->left->right == nullptr)) {
            // left subtree 가 leaf 인 경우
            leftChild = root->left->val;
        } else {
            // left subtree 가 non-leaf 인 경우
            leftChild = sumOfLeftLeaves(root->left);
        }

        // right subtree 에 대해 계산
        int rightChild = 0;
        if (root->right == nullptr) {
            // right subtree 가 empty 인 경우
            // do nothing (rightChild = 0)
        } else if ((root->right->left == nullptr) && (root->right->right == nullptr)) {
            // right subtree 가 leaf 인 경우
            // do nothing (rightChild = 0)
        } else {
            // right subtree 가 non-leaf 인 경우
            rightChild = sumOfLeftLeaves(root->right);
        }

        return leftChild + rightChild;
    }
};
