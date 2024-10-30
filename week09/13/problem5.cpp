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
    int ans;

    void dfs(TreeNode* root, int num){
        if(!root) return;
        if(cnt==num) return;

        dfs(root->left, num);

        cnt++;
        if(cnt==num){
            ans=root->val;
            return;
        }

        dfs(root->right, num);
    }

    int kthSmallest(TreeNode* root, int k) {
        //가장 왼쪽끝까지 내려가서 1번 -> 부모 -> 오른쪽 자식 -> 부모 -> ... -> 루트 -> 가장 오른쪽 자식의 가장 왼쪽끝까지 내려가서 -> 부모 -> 자식 순으로 탐색
        //-->Inorder traversal

        //참고
        //postorder: 왼쪽->오른쪽->가운데
        //preorder: 가운데->왼쪽->오른쪽

        dfs(root, k);

        return ans;

    }
};