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
    int cnt=0;
    int max=0;

    void dfsRecursive(Node* root) {
        cnt++;
        std::cout<<max<<" "<< root->val << endl;
        if (!root) 
        {
            return;
        }

        // 자식 노드들을 재귀적으로 방문, 자식노드가 없으면 그냥 넘어감
        for (Node* child : root->children) {
            dfsRecursive(child);
        }

        if(cnt>max){
            max=cnt;
        }
        cnt--;
    }

    int maxDepth(Node* root) {
        //children이 벡터라는 사실을 염두에 두자! 첫번째 자식
        //root=root->children[0];

        Node* array=root;

        if (root==nullptr){
            return 0;
        }

        dfsRecursive(array);

        return max;
    }

};