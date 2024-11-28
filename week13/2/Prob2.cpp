#include<vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.size() == 0){
            return false;
        }

        // trips에서 from의 min과 to의 max값을 찾아서 trip path list를 생성
        int mins = INT_MAX;
        int maxs = -INT_MAX;
        for(int i=0; i<trips.size();i++){
            if(trips[i][1] < mins) mins = trips[i][1];
            if(trips[i][2] > maxs) maxs = trips[i][2];
        }
        // trip_path에는 현재 자동차에 탑승중인 인원을 기록
        vector<int> trip_path(maxs-mins+1);
        fill(trip_path.begin(), trip_path.end(), 0);

        // trip 변수별로 trip_path에 탑승시켜 볼 것
        for(int i=0; i<trips.size();i++){
            int start = trips[i][1] - mins;
            int end = trips[i][2] - mins; // end에서는 내리고 탈 수 있음
            for(int j=start;j<end;j++){
                trip_path[j] += trips[i][0];
                if(trip_path[j] > capacity){
                    return false;
                }
            }
        }
        return true;


    }
};