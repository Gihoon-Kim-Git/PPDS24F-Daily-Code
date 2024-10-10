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
    void traversal(TreeNode* node, int isLeft, int& sum){
        if(node == nullptr){return;}

        if(node->left == nullptr && node->right == nullptr && isLeft == 1){
            sum += node->val;
        }
        
        traversal(node->left, 1, sum);
        traversal(node->right, 0, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traversal(root, 0, sum);
        return sum;
    }
};

