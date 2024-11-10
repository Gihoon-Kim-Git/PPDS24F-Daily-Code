//QUEUE + BFS
#include <vector>
#include <queue>
using namespace std;
#include <stack>
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
        // BFS with Queue
        if(!root) return 0;

        queue<Node*> q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                for(auto x : curr->children) q.push(x);
            }
            cnt++;
        }
        return cnt;
    }
};

// STACK + DFS
/*
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
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int max_depth = 0;
        if(!root) return max_depth;

        stack<pair<Node*,int>> s;
        s.push({root,1});

        while(!s.empty()){
            Node* curr = s.top().first;
            int dept = s.top().second;
            s.pop();
            max_depth = max(max_depth,dept);
            for(auto x : curr->children){
                s.push({x,dept+1});
            }
        }
        return max_depth;
    }
};