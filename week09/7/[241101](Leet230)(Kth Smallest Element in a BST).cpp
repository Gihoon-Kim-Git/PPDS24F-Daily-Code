/*문제
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

/*Constraints:
    The number of nodes in the tree is n.
    1 <= k <= n <= 104
    0 <= Node.val <= 104
*/

/*문제풀이 1: 통과.
    1. BFT(또는 DFT)로 모든 value를 vector에 저장한 후에 
    2. vector를 sort
    3. 해당 vector[k-1]를 return
*/

/*문제풀이 2: BST의 원리 활용
    1.inorder Traversal하면 값 순서대로 나열된다는 것을 활용.
    2.DFT를 수행하되, inorder로 구현. 
    3. return values[k-1]
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//풀이1 =====================================================================================
void merge(vector<int>& result, vector<int>& left, vector<int>& right) {
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());
}

void merge_sort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    size_t mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    merge_sort(left);
    merge_sort(right);
    
    arr.clear();
    merge(arr, left, right);
}

class Solution{
public:
    vector<int> DFT(TreeNode* root){
        vector<int> values = {};
        if (root == NULL) return values;
        if (root) values.push_back(root->val);
        if (root->left) {
            vector<int> left_values = DFT(root->left);
            values.insert(values.end(), left_values.begin(), left_values.end());
        }
        if (root->right){
            vector<int> right_values = DFT(root->right);
            values.insert(values.end(), right_values.begin(), right_values.end());
        }
        return values; 
    }

    vector<int> BFT(TreeNode* root){
        vector<int> values = {};
        vector<TreeNode*> q;
        
        q.push_back(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            if (cur != nullptr) values.push_back(cur->val);
            q.erase(q.begin());

            if (cur->left != nullptr) q.push_back(cur->left);
            if (cur->right != nullptr) q.push_back(cur->right);
        }
        return values;
    }

    int kthSmallest(TreeNode* root, int k){
        // 1. Traversal로 모든 요소 vector 찾기
        vector<int> values = BFT(root);
       // vector<int> values = DFT(root);

        // 2. vector를 sort
        //sort(values.begin(), values.end());
        merge_sort(values);
        return values[k-1];
    }
};

//풀이2 : Inorder Traversal 활용=====================================================
class Solution{
public:
    vector<int> DFT(TreeNode* root){
        vector<int> values = {};
        if (root == NULL) return values;
        if (root->left) {
            vector<int> left_values = DFT(root->left);
            values.insert(values.end(), left_values.begin(), left_values.end());
        }
        if (root) values.push_back(root->val);
        if (root->right){
            vector<int> right_values = DFT(root->right);
            values.insert(values.end(), right_values.begin(), right_values.end());
        }
        return values; 
    }


    int kthSmallest(TreeNode* root, int k){
        // 1. Traversal로 모든 요소 vector 찾기
        vector<int> values = DFT(root);

        return values[k-1];
    }
};


//풀이3: 다른 사람 풀이 참고 (values를 저장하는 vector를 생성하지 않음)----------------------

class Solution{

    int Ans = -1;

    void Search(TreeNode* a, int& K) //K를 reference로 받는 게 중요함
    {
        if (!a)return;

        Search(a->left, K);
        K--; //해당 노드가 방문되면 K값을 1 줄이는 것임
        if (K == 0) {Ans = a->val; return; }
        
        Search(a->right, K);
    }

public:
    int kthSmallest(TreeNode* a, int k) {
        int K = k;
        Search(a, k);
        return Ans;
    }
};