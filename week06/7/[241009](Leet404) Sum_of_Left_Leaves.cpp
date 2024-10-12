/*문제
binary tree의 root가 주어졌을 때, sum of all left leaves를 구하라.

left leaf : child가 없으면서, 부모 노드의 left child인 노드.*/

/*문제풀이 : Recursive 방식
    1. 현재노드가 반환하는 값
        - nullptr일 때 : 0반환
        - nullptr는 아닐 때.
            -- 자식이 하나도 없을때, 내가 left child이면 본인의 val을 반환. 그렇지 않으면(오른 child)이면 0 반환
            -- 자식이 하나 이상 있을 때, 함수(현재->left) + 함수(현재->right)
    2.  이때, 함수 argument에는 (노드, 이게 leftchild인지 표시)를 함께 내려주어야 별도로 parent를 관리하지 않아도 됨.
*/

#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int dfs(TreeNode* root, bool isLeft){
        if (root==nullptr) return 0;
        else if (root -> left == nullptr && root-> right == nullptr) return isLeft? root->val : 0;
        return dfs(root->left, 1) + dfs(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root){
        return dfs(root,0);
    }
};