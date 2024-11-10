class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int max_depth = 0;
        for (Node* child : root->children) {
            max_depth = max(max_depth, maxDepth(child));
        }
        
        return max_depth + 1;
    }
};
