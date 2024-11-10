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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; // To count the nodes we've visited
        int result = -1; // To store the result
        
        // Helper function for in-order traversal
        inOrderTraversal(root, k, count, result);
        
        return result;
    }
    
    void inOrderTraversal(TreeNode* node, int k, int &count, int &result) {
        if (!node || count >= k) return;
        
        // Traverse left subtree
        inOrderTraversal(node->left, k, count, result);
        
        // Process the current node
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        
        // Traverse right subtree
        inOrderTraversal(node->right, k, count, result);
    }
};