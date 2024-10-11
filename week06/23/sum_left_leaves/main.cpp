#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform DFS and calculate the sum of left leaves
void dfs(TreeNode* node, bool isLeft, int &total) {
    if (!node) return;

    // If it's a leaf node and it's a left child
    if (!node->left && !node->right && isLeft) {
        total += node->val;
    }

    // Recursively check left and right children
    dfs(node->left, true, total);  // isLeft = true for left child
    dfs(node->right, false, total); // isLeft = false for right child
}

// Function to find the sum of left leaves
int sumOfLeftLeaves(TreeNode* root) {
    int total = 0;
    dfs(root, false, total); // Start the DFS traversal with root, isLeft = false (not a left child)
    return total;
}

// Helper function to create a new tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Driver code to test the function
int main() {
    // Create a binary tree
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    // Test the sumOfLeftLeaves function
    int result = sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl;  // Output should be 24 (9 + 15)

    // Clean up dynamically allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
