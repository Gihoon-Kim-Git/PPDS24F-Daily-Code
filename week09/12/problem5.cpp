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
     int cnt=0;
    void inOrder(TreeNode* root, int k, int &ans){
        if(!root) return;
        inOrder(root->left,k,ans);
        cnt+=1;
        if(cnt==k){
            ans=root->val;
        }
        inOrder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inOrder(root,k,ans);
        return ans;
    }
};