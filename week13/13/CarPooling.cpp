class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> num(1001, 0);

        for(auto i=0; i<trips.size(); i++){
            for(auto j=trips[i][1]; j<trips[i][2]; j++){
                num[j]+=trips[i][0];
            }
        }

        for(auto i=0; i<=1000; i++){
            if(num[i]>capacity){
                return false;
            }
        }
        return true;
    }
};


//map을 사용해서 아래와 같이 공간 효율적으로 구현할 수도 있음

//#include <vector>
// #include <map>
// using namespace std;

// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         map<int, int> changes; // 변화 기록 (위치 기반 정렬 자동 처리)

//         // 승객 태우고 내리기 기록
//         for (auto& trip : trips) {
//             int numPassengers = trip[0];
//             int from = trip[1];
//             int to = trip[2];

//             changes[from] += numPassengers; // from 위치에서 승객 태움
//             changes[to] -= numPassengers;  // to 위치에서 승객 내림
//         }

//         int currentPassengers = 0;

//         // 누적된 승객 수 확인
//         for (auto& change : changes) {
//             currentPassengers += change.second; // 현재 위치의 승객 변화 적용
//             if (currentPassengers > capacity) {
//                 return false; // 용량 초과
//             }
//         }

//         return true; // 모든 승객을 태울 수 있음
//     }
// };
