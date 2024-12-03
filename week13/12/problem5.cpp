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
    int maxi=0;
    void dfs(TreeNode* root,TreeNode* curr){
        if(root==nullptr||curr==nullptr){
            return;
        }
        maxi = max(maxi,abs(root->val - curr->val));
        dfs(root,curr->left);
        dfs(root,curr->right);
    }
    void run_dfs(TreeNode* root){
            dfs(root,root);
            if(root->left!=nullptr){
                run_dfs(root->left);
            }
            if(root->right!=nullptr){
                run_dfs(root->right);
            }
    }
    int maxAncestorDiff(TreeNode* root) {
            if(root==nullptr){
                return maxi;
            }
            run_dfs(root);
            
            return maxi;
    }
};