
//  * Definition for a binary tree node.
#include <stack>
using namespace std;
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
    int sumOfLeftLeaves(TreeNode* root) {
        //Stack으로 풀어보기
        int ans = 0;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            if(node->left && !node->left->left && !node->left->right){
                ans += node->left->val;
            }
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        return ans;
    }
};