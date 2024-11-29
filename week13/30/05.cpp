#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void printVec(vector<int> vec) {
        cout << "[ ";
        for (int i = 0; i < vec.size(); i++) { cout << vec[i] << " ";}
        cout << "]" << endl;
    }
    void traverse(vector<int> roots, int numNodes,  TreeNode* root, int* maxDif) {
        if (root == nullptr) {return;}

        int curMaxDif = 0;
//curMaxDif의 max를 구하자
        for (int i = 0; i < roots.size(); i++) {
            if (roots[i] != -1) {
                if (curMaxDif < abs(root->val - roots[i])) {
                    curMaxDif = abs(root->val - roots[i]);
                }
            }
        }
        

//curMaxDif와 이전까지의 maxDif를 비교하자. 
        cout << "Node Val " << root->val << " | Roots: ";
        printVec(roots); 
        // cout << "Node=" << root->val << "|| cur: " << curMaxDif << " | max: " << *maxDif;
        if (curMaxDif > *maxDif) {
            *maxDif = curMaxDif;
            // cout << "==> max updated" << *maxDif;
        }

        roots.push_back(root->val);
        traverse(roots, numNodes, root->left, maxDif);
        traverse(roots, numNodes, root->right, maxDif);
        // roots.pop_back();  &vector<int> roots 하고 나서 이거 pop_back()을 살려도 돼!!
    }

    void calNumNodes(TreeNode* root,int* numNodes ) {
        if (root==nullptr) {return ;}
        (*numNodes)++;
        calNumNodes(root->left, numNodes);
        calNumNodes(root->right, numNodes);   
    }

    int maxAncestorDiff(TreeNode* root) {
    //(1). numNodes 계산하기
        int numN = 0;
        calNumNodes(root, &numN);
    //(2). 넣어줄 arr만들기
        vector<int> rootNodesVal;
    //(3). 가장!
        int maxDif = 0;
        traverse(rootNodesVal, numN, root, &maxDif);
        return maxDif;
    }



    void freeTree(TreeNode* root) {
        if (root == nullptr) {return;}
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};

int main() {

////////////////TREE 1 /////////////
//4
    TreeNode* node4 = new  TreeNode(4);
    TreeNode* node7 = new  TreeNode(7);
    TreeNode* node13 = new  TreeNode(13);
//3
    TreeNode* node6 = new  TreeNode(6, node4, node7);
    TreeNode* node14 = new  TreeNode(14, node13, nullptr);
    TreeNode* node1 = new  TreeNode(1);
//2
    TreeNode* node3 = new  TreeNode(3, node1, node6);
    TreeNode* node10 = new  TreeNode(10, nullptr, node14);
//1
    TreeNode* node8 = new  TreeNode(8, node3, node10);


////////////TREE 2////////////////
    TreeNode* NODE3 = new  TreeNode(3);
    TreeNode* NODE0 = new  TreeNode(0, NODE3, nullptr);
    TreeNode* NODE2 = new  TreeNode(2, nullptr, NODE0);
    TreeNode* NODE1 = new  TreeNode(1, nullptr, NODE2);

    Solution mysol;
    int result1 = mysol.maxAncestorDiff(node8);
    int result2 = mysol.maxAncestorDiff(NODE1);
    mysol.freeTree(node8);
    mysol.freeTree(NODE1);
    cout << "\nResult1: " << result1 << endl;
    cout << "\nResult2: " << result2 << endl;
    return 0;
}
