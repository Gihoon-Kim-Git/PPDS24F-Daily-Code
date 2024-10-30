/*문제
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*문제풀이
    1. Node가 NULL이면 return 0
    2. Node의 numChildren이 0이 아니면 for문 돌면서 maxDepth(child)의 최댓값을 찾고, 그 최댓값 + 1 을 return
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution{
public:
    int maxDepth(Node* root){
        if (root == nullptr) return 0;
        else {
            int max_depth_child = 0;
            for (auto r : root->children){
                int cur_depth = maxDepth(r);
                if (max_depth_child < cur_depth) max_depth_child = cur_depth;
            }
            return max_depth_child + 1;
        }
    }
};