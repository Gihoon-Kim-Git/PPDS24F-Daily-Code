#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengerNum[1001] = {0, };
        for (int i = 0; i < trips.size(); i++){
            passengerNum[trips[i][1]] += trips[i][0];
            passengerNum[trips[i][2]] -= trips[i][0];
        }
        int CurPassenger = 0;
        for(int i = 0; i < 1001; i++) {
            CurPassenger += passengerNum[i];
            if (CurPassenger > capacity) return false;
        }
        return true;

    }
};