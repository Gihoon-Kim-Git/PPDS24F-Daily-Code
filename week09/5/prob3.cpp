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

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            int maxDepth = -1;
            dfs_helper(root, 1, maxDepth);
            return maxDepth;
        }
    }

    void dfs_helper(Node* curr, int depth, int& maxDepth) {
        // base case : no child
        if (curr->children.size() == 0) {
            if (depth > maxDepth) {
                maxDepth = depth;
            }
        }
        // recursive case
        else {
            for (Node* child : curr->children) {
                dfs_helper(child, depth+1, maxDepth);
            }
        }
    }
};

// 좀 더 함수형 스타일
// recursion
// call by reference 를 사용하지 않음
class Solution2 {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs_helper(root, 1);
    }

    int dfs_helper(Node* curr, int depth) {
        int max_depth = depth;
        for (Node* child : curr->children) {
            max_depth = std::max(max_depth, dfs_helper(child, depth + 1));
        }
        return max_depth;
    }
};

// iterative
class Solution3 {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = 0;
        for (Node* child : root->children) {
            depth = std::max(depth, maxDepth(child));  // 각 자식의 최대 깊이를 계산
        }
        
        return depth + 1;  // 현재 노드의 깊이를 더해 반환
    }
};
