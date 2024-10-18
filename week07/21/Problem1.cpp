#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if (rowIndex == 0) return ans;
        else if (rowIndex == 1) {
            ans.push_back(1);
            // cout << "when rowidx is 1 : "<< ans[0]<<" "<<ans[1]<<endl;
            return ans;
        }
        else{
            vector<int> pre = getRow(rowIndex-1);
            for(int i = 2; i<rowIndex+1; i++){
                // int temp=0;
                // cout<<"check:"<<rowIndex<<" "<<rowIndex-1<<" "<<i-1<<"and"<<i<<endl;
                // cout<<"summation:"<<getRow(rowIndex-1)[i-1]<<"+"<<getRow(rowIndex-1)[i]<<endl;
                // temp = pre[i-2] + pre[i-1]; 
                ans.push_back(pre[i-2] + pre[i-1]);
            }
            ans.push_back(1);
            return ans;
        }
    }
};


// int main(void) {
//     Solution sol;  
//     vector<int> result0 = sol.getRow(0);
//     vector<int> result1 = sol.getRow(1);
//     vector<int> result2 = sol.getRow(2);
    
//     for (int x : result0) cout << x << " ";
//     cout << endl;
//     for (int x : result1) cout << x << " ";
//     cout << endl;
//     for (int x : result2) cout << x << " ";
//     cout << endl;

//     return 0;
// }