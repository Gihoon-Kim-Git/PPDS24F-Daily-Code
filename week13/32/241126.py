class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> loc(1000, 0);
        for (int i=0; i < trips.size(); i++) {
            for (int j=trips[i][1]; j < trips[i][2]; j++) {
                loc[j] += trips[i][0];
                if (loc[j] > capacity) {
                    return false;
                }
            }
        }
        return true;
    }
};