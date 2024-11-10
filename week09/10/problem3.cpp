#include <vector>
#include <queue>
using namespace std;

/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

*/

/*
// Definition for a Node.*/
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


//Recursive DFS:
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (auto child : root->children) depth = max(depth, maxDepth(child));
        return 1 + depth;
    }
};

//Recursive DFS without raw loops:
class Solution {
public:
    static int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        return 1 + transform_reduce(begin(root->children), end(root->children), 0, [](int acc, int d) { return max(acc, d); }, [](auto* node) { return maxDepth(node); });
    }
};

//Recursive DFS one-liner:
class Solution {
public:
    static int maxDepth(Node* root) {
        return root ? 1 + transform_reduce(begin(root->children), end(root->children), 0, [](int acc, int d) { return max(acc, d); }, [](auto* node) { return maxDepth(node); }) : 0;
    }
};


//BFS:
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        queue<Node*> q; q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth += 1;
            int breadth = q.size();
            for (int _ = 0; _ < breadth; ++_) {
                auto node = q.front(); q.pop();
                for (auto child : node->children) if (child) q.push(child);
            }
        }
        return depth;
    }
};


