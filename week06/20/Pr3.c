
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int sumOfLeftLeaves(struct TreeNode* root) {
    // Recursive Solution
    // Base case
    if(!root) return 0;
    int ans = 0;
    if(root->left && !root->left->left && !root->left->right){
        ans += root->left->val;
    }
    ans += sumOfLeftLeaves(root->right);
    ans += sumOfLeftLeaves(root->left);

    return ans;
}