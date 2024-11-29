class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> temp;
        for(int i=0; i<trips.size(); i++){
            temp.push_back({trips[i][1], trips[i][0]});
            temp.push_back({trips[i][2], -trips[i][0]});
        }

        sort(temp.begin(), temp.end());

        int f = 0;
        for(int i=0; i<temp.size(); i++){
            f += temp[i].second;
            if(f>capacity) return false;
        }
        return true;
    }
};