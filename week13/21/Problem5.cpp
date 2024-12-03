class Solution {
public:
    void func(TreeNode* root,int maxi,int mini,int &diff){
        if(root == NULL) return;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        diff=max(diff,maxi-mini);
        func(root->right, maxi, mini, diff);
        func(root->left, maxi, mini, diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi = root->val;
        int mini = root->val;
        int diff = 0;   
        func(root, maxi, mini, diff);
        return diff;
    }
};