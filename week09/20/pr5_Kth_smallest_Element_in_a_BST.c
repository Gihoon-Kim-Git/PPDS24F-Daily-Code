
//   Definition for a binary tree node.
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
 
void helper(struct TreeNode* node, int* cnt, int* result){
    if(!node) return;

    helper(node->left,cnt,result);

    (*cnt)--;
    if(*cnt==0){
        *result = node->val;
       return;
    }
    helper(node->right,cnt,result);

}

int kthSmallest(struct TreeNode* root, int k) {
    int result;
    helper(root,&k,&result);
    return result;
}