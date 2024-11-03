#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        if(root -> children.size() == 0) return 1;
        int ans = INT_MIN;
        for(auto node: root->children){
            ans = fmax(ans, maxDepth(node)+1);
        }
        return ans;
    }
};