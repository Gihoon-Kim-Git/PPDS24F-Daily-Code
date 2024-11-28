/*"""Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b."""

"""Constraints:
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 105"""*/

/*수도코드1 : 모든 노드에 대해서 비교하는 과정에서 BFS 활용
목표 : 각 노드의 subtree에 있는 모든 노드들과의 max_diff 찾는 함수를 정의해서, 해당 함수를 Tree의 모든 노드에 대해 실행하면서 main_max_diff를 update
*/

#include <iostream>
#include <queue>
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

class Solution {
public:
    int cur_max_diff(TreeNode* cur_node){
        int max_diff = 0;

        queue<TreeNode*> q;
        q.push(cur_node);

        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            int diff = cur_node->val - cur->val;
            int abs_diff = diff > 0 ? diff : -diff;
            if (abs_diff > max_diff) max_diff = abs_diff;

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        return max_diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        int main_max_diff = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            int cur_max_d = cur_max_diff(cur);
            if (cur_max_d > main_max_diff) main_max_diff = cur_max_d;

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        return main_max_diff;
    }
};


/*DFS 활용 풀이---------------------------------------------------------------------------------------------------------*/

/*수도코드2
목표 : root에서부터 각 leaf까지의 경로를 따라 내려가면서 big, small값을 갱신하고, 경로의 끝에 도달하면 diffrence(big-small) 값을 반환하는 help함수를 정의함. root가 nullptr인 경우에는 0을 반환하고 그 외에는 helper함수를 사용해서 값을 얻는다.
*/

class Solution {
public:
    int helper(TreeNode* curNode, int min_val, int max_val){
        if (curNode == nullptr) return max_val - min_val;

        if (curNode->val > max_val) max_val = curNode->val;
        if (curNode->val < min_val) min_val = curNode->val;

        int left_max_diff = helper(curNode->left, min_val, max_val);
        int right_max_diff = helper(curNode->right, min_val, max_val);

        return left_max_diff > right_max_diff ? left_max_diff : right_max_diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        return helper(root, root->val, root->val);
    }
};