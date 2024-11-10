// ## Wednesday. [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)]


// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000




// traverse하면서 sum 하는게 가능한가?
// queue 사용해서 하나씩 자식 여부 확인. left, right 여부 확인할 수만 있으면 됨. 
// 방향 queue랑 노드 queue 두개 만들기


#include <queue>

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


        // queue<TreeNode*> nodeQueue;
        // queue<char> positionQueue;


        queue<pair<TreeNode*, char>> nodeQueue;
        nodeQueue.push(make_pair(root, 'c'));

        TreeNode* curr;
        char currPos;

        int sum = 0;


        while (!nodeQueue.empty()){
            curr = nodeQueue.front().first;
            currPos = nodeQueue.front().second;

            if (currPos == 'l' && curr->left == nullptr && curr->right == nullptr){
                sum += curr->val;
            }

            if (curr->left != nullptr){
                nodeQueue.push(make_pair(curr->left, 'l'));
            }
            if (curr->right != nullptr){
                nodeQueue.push(make_pair(curr->right, 'r'));
            }

            nodeQueue.pop();
        }

        return sum;
        
    }
};