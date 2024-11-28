#include <iostream>
#include <queue>
using namespace std;
#include <vector>
#include <algorithm>
// int main(){
//     priority_queue<int,vector<int>,greater<int>> pq;
//     pq.push(3);
//     pq.push(1);
//     pq.push(5);
//     for(int i=0;i<3;i++){
//         cout << pq.top() << " ";
//         pq.pop();
//     }
//     cout<<endl;
//     vector<int> vec = {1,1,1,1,0};
//     cout<<count(vec.begin(),vec.end(),1);   
// }
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(int i=0; i < mat.size(); i++){
            minheap.push({count(mat[i].begin(),mat[i].end(),1),i});
        }
        vector<int> ans;
        for(int j=0;j<k;j++){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
    }
};