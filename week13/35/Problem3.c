class Solution {
public:
    int sol(vector<int>a){
        int c=0;
        for(auto x:a){
            if(x==1) c++;
        } return c;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         vector<int>ans;
        int n=mat.size(),m=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int cnt=sol(mat[i]);
            pq.push({cnt,i});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }return ans;
        
    }
};