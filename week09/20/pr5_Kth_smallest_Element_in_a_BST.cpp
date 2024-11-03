
//  * Definition for a binary tree node.
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
    void inorder(TreeNode* node, int& cnt, int& ans){
        if(!node) return;
        inorder(node->left,cnt,ans);
        cnt--;
        if(cnt==0){
            ans = node->val;
            return;
        }
        else inorder(node->right,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,k,ans);
        return ans;   
    }
};