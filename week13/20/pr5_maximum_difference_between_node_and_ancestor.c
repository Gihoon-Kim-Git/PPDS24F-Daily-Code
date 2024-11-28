
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a > b? b : a;
}

int helper(struct TreeNode* node, int maxval, int minval){
    if(!node) return maxval - minval;
    maxval = max(maxval,node->val);
    minval = min(minval,node->val);
    int left = helper(node->left,maxval,minval);
    int right = helper(node->right,maxval,minval);
    return max(left,right);
}

int maxAncestorDiff(struct TreeNode* root) {
    return helper(root,root->val,root->val);
}