

// 1026. Maximum Difference Between Node and Ancestor
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.


// 내 밑에 애들 중에서 제일 작은 노드와 가장 큰 노드를 반환
// 내 값이랑 비교하고, 제일 큰 diff update






#include <algorithm>

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
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        pair<int, int> minMax = getMinMax(root);

        int diff = max(abs(minMax.first - root->val), abs(minMax.second - root->val));

        int left = maxAncestorDiff(root->left);
        int right = maxAncestorDiff(root->right);

        return max(diff, max(left, right));
    }

    pair<int, int> getMinMax(TreeNode* root){
        // 내 왼쪽에서 최소, 최대
        // 내 오른쪽에서 최소, 최대 가져와서
        // 내 값이랑 비교해서 최소, 최대 업데이트

        // base case (leaf node)
        if (root == nullptr){
            return {INT_MAX, INT_MIN};
        } 

        pair<int, int> left = getMinMax(root->left);
        pair<int, int> right = getMinMax(root->right);

        int minVal = min(left.first, right.first);
        int maxVal = max(left.second, right.second);

        return {min(minVal, root->val), max(maxVal, root->val)};
    }

    // // 다른 답변

    // int dfs_iterative(TreeNode* root){
    //     vector<pair<TreeNode*, pair<int, int>>> stack = {
    //         {root, {root->val, root->val}}
    //     };


    //     int res = 0;
    //     pair<TreeNode*, pair<int, int>> curr;
    //     while(!stack.empty()){
    //         curr = stack.back();
    //         stack.pop_back();

    //         TreeNode* node = curr.first;
    //         int minVal = curr.second.first;
    //         int maxVal = curr.second.second;

    //         if (node == nullptr){
    //             res = max(res, maxVal - minVal);
    //             continue;
    //         }

    //         int newMin = min(minVal, node->val);
    //         int newMax = max(maxVal, node->val);

    //         stack.push_back({node->left, {newMin, newMax}});
    //         stack.push_back({node->right, {newMin, newMax}});
    //     }
    //     return res;
    // }

    // int dfs_recursive(TreeNode* root, int minVal, int maxVal){
    //     if (root == nullptr){
    //         return maxVal - minVal;
    //     }

    //     minVal = min(minVal, root->val);
    //     maxVal = max(maxVal, root->val);

    //     int left = dfs_recursive(root->left, minVal, maxVal);
    //     int right = dfs_recursive(root->right, minVal, maxVal);

    //     return max(left, right);
    // }

    // int maxAncestorDiff(TreeNode* root) {
    //     return dfs_iterative(root);
    // }
    

};