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
        if (!root) return 0;
        //node,depth
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        int depth=0;
        while(!q.empty()){
            Node* curr= q.front().first;
            int currDepth = q.front().second;
            depth= max(depth,currDepth);
            q.pop();
            if(!curr|| curr->children.empty()){
                continue;
            }
            for(auto& child:curr->children){
                q.push(make_pair(child,currDepth+1));
            }
        }
        return depth+1;
    }
};