#include <map>
using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <stack>
// int main(){
//     stack<map<string,vector<int>>> s;
//     map<string,vector<int>> m;
//     m["abcd"] = {11,21};
//     cout << m["abcd"][0] << endl;
    
//     s.push({{"abcd",{1,3}}});
//     cout << s.top()["abcd"][0] <<endl;
// }



//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        stack<tuple<TreeNode*,int,int>> s;
        s.push({root,root->val,root->val});

        while(!s.empty()){
            auto [curr, maxval, minval] = s.top();
            s.pop();

            maxval = max(curr->val,maxval);
            minval = min(curr->val,minval);

            ans = max(ans,maxval-minval);

            if(curr->left) s.push({curr->left,maxval,minval});
            if(curr->right) s.push({curr->right,maxval,minval});
        }
        return ans;
    }
};