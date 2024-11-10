#include <iostream>
#include <algorithm>
using namespace std;

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
        return maxDepthHelp(root, 1);
    }

    int maxDepthHelp(Node* root, int depth) {
        vector<int> maxD;
        if (root == nullptr) return 0;
        if (!root->children.empty()) {
            for (auto child: root->children) maxD.push_back(maxDepthHelp(child, depth+1));
        }
        if (maxD.empty()) return depth;
        return *max_element(maxD.begin(), maxD.end());
    }
};

int main() {
    Node *tree5 = new Node(6);
    Node *tree4 = new Node(5);
    Node *tree3 = new Node(4);
    Node *tree2 = new Node(2);
    vector<Node*> child2 = {tree4, tree5};
    Node *tree1 = new Node(3, child2);
    vector<Node*> child1 = {tree1, tree2, tree3};
    Node *root = new Node(1, child1);
    
    Solution result;
    cout << result.maxDepth(root) << endl;

    return 0;
}