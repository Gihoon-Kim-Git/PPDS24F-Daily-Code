#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nums(TreeNode* root, vector<int> &v){
        if (root == NULL) return;

        v.push_back(root->val);
        nums(root->left,v);
        nums(root->right,v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        nums(root, v);
        sort(v.begin(), v.end());
        return v[k-1];    
    }
};