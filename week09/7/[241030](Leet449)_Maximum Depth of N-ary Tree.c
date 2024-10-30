/*문제
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*문제풀이
    1. Node가 NULL이면 return 0
    2. Node의 numChildren이 0이 아니면 for문 돌면서 maxDepth(child)의 최댓값을 찾고, 그 최댓값 + 1 을 return
*/



#include <stdio.h>
#include <stdlib.h>

//Definition for a node
struct Node{
    int val;
    int numChildren;
    struct Node** children;
};

int maxDepth(struct Node* root){
    if (root == NULL) return 0;

    int max_depth_child = 0;
    for (int i = 0; i < root->numChildren;i++){
        int cur_depth = maxDepth(root->children[i]);
        if (cur_depth > max_depth_child) max_depth_child = cur_depth;
    }
    return max_depth_child + 1;
}