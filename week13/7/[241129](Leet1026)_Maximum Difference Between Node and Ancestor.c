/*"""Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b."""

"""Constraints:
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 105"""*/

/*수도코드
목표 : 경로 상의 max_diff값을 반환하는 helper함수를 활용, root에서부터 모든 leaf까지의 경로에서 max_diff값 반환.
*/


#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max_diff(struct TreeNode* root, int min_val, int max_val){
    if (root == NULL) return max_val - min_val; // root가 leaf의 자식이 되면(경로의 끝) 해당 경로의 max_diff 반환.
    
    if (root->val < min_val) min_val = root->val;
    if (root->val > max_val) max_val = root->val;

    int left_max_diff = max_diff(root->left, min_val, max_val);
    int right_max_diff = max_diff(root->right, min_val, max_val);

    return left_max_diff > right_max_diff ? left_max_diff : right_max_diff;
}


int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) return 0;

    return max_diff(root, root->val, root->val);
}