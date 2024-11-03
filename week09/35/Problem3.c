#include <stdio.h>


/**
 * Definition for a Node.
이거 23년도 3월 논자시 1번이잖아...height구하는거..23년도 9월에 height구하는거 나옴..ㅠㅠ
 */
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};
int maxDepth(struct Node* root) {
    if (!root) {
        return 0; // Base case: empty node has a depth of 0
    }
    
    int max_depth = 0;
    
    // Iterate through each child and calculate their depth
    for (int i = 0; i < root->numChildren; i++) {
        int child_depth = maxDepth(root->children[i]);
        if (child_depth > max_depth) {
            max_depth = child_depth;
        }
    }
    
    return max_depth + 1; // Add 1 to include the current node in the depth count
}

