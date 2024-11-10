class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,int> mp;
        for (int start=0;start<n;start++){
            if(mp[start])continue;
            mp[start]=0;
            queue<int>q;
            q.push(start);
            while(!q.empty()){
                int curr= q.front();
                q.pop();
                for(auto&it:graph[curr]){
                    if(!mp[it]){
                        mp[it]= 1-mp[curr];
                        q.push(it);
                    }
                    else if (mp[it]==mp[curr]){
                        return false;
                    }
                }
            }

        }
        return true;
    }
};