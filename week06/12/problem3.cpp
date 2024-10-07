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
    void dfs(TreeNode* root, int &ans){
        if(root==nullptr)return;
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            ans+= root->left->val;
        }
        dfs(root->left, ans);
        dfs(root->right,ans);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int summa=0;
        dfs(root,summa);
        return summa;
    }
};