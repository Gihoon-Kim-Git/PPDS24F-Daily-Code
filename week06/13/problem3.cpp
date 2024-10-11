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
    int sum=0;

    int sumOfLeftLeaves(TreeNode* root) {
        
        //leaf노드를 판별: left와 right이 모두 nullptr인지 확인해서 sum에 더해주기
        //left leaf를 판별할 때는, root->left->left와 root->left->right이 nullptr인지 확인하기
        if(root==nullptr)
        {
            return 0;
        }

        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            cout<<root->left->val<<endl;
            sum+=root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);

        return sum;
    }
};

//트리노드에서는 root->left->left 이런식으로 가능함!