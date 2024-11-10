#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    Node(): val(0), children(vector<Node*>()){}
    Node(int _val): val(_val), children(vector<Node*>()){}
    Node(int _val, vector<Node*> _children):val(_val), children(_children) {}
};

class Solution{
public:
    int maxDepth(Node* root){
        if (! root) {
            return 0;
        }
        queue<pair<Node*, int>> queue;
        queue.push({root, 1});
        int maxDepth = 0;

        while (!queue.empty()){
            Node* node = queue.front().first;
            int depth = queue.front().second;
            queue.pop();
            maxDepth = max(maxDepth, depth);

            for (Node* child : node->children){
                queue.push({child, depth + 1});
            }
        }
        return maxDepth;
    }
};

int main() {
    // Creating a sample tree:
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution solution;
    cout << "Maximum depth of the tree: " << solution.maxDepth(root) << endl;

    // Free allocated memory
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}