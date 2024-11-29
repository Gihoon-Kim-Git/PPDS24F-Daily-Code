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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;

        // 초기 호출 시 root의 값이 최소값 및 최대값
        return helper(root, root->val, root->val);
    }

private:
    int helper(TreeNode* node, int currMin, int currMax) {
        if (!node) {
            // 리프 노드에 도달하면, 최대값과 최소값의 차이를 반환
            return currMax - currMin;
        }

        // 현재 노드의 값을 기반으로 최소값과 최대값 갱신
        currMin = std::min(currMin, node->val);
        currMax = std::max(currMax, node->val);

        // 왼쪽과 오른쪽 서브트리로 재귀 호출
        int leftDiff = helper(node->left, currMin, currMax);
        int rightDiff = helper(node->right, currMin, currMax);

        // 왼쪽과 오른쪽에서 반환된 값 중 최댓값 선택
        return std::max(leftDiff, rightDiff);
    }
};
