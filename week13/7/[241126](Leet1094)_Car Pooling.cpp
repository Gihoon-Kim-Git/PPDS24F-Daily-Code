/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
*/

/*Constraints:
    1 <= trips.length <= 1000
    trips[i].length == 3
    1 <= numPassengersi <= 100
    0 <= fromi < toi <= 1000
    1 <= capacity <= 105
*/

/*수도코드 : minheap 구현 필요
목표 : trips를 순회하면서, to를 기준으로 minheap에 넣을 때, 들어오는 trip의 from과 minheap[0]의 to가 겹칠 때까지 minheap.pop을 수행한다. cur_passenger는 heapq에 들어있는 trip의 numPassengers의 합. cur_passenger > capacity이면 return False.

0. trips를 sort (from 순서대로)

1. min_heap 선언
    cur_people = 0 으로 초기화

2. trips를 순회하면서, 
    (trip[i][2], trip[i][0])를 pair로 min_heap에 넣음
    cur_people += trip[i][0]
    min_heap[0]의 to와 trip[i]의 from을 비교.
        만약 min_heap[0]의 to가 trip[i]의 from보다 작거나 같으면, 
            extracted_trip = min_heap에서 pop
            cur_people -= extracted_trip[1]
        (min_heap[0]의 to가 trip[i]의 from보다 클 때까지 반복)
    만약 cur_people > capacity이면
        return False

3. trips 순회가 끝났으면 return True
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {


public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //sort 유의!!
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q;

        int cur_people = 0;

        for (auto trip: trips){
            q.push(make_pair(trip[2], trip[0]));
            cur_people += trip[0];
            while (q.top().first <= trip[1]){
                cur_people = cur_people - q.top().second;
                q.pop();
            }
            if (cur_people > capacity) return false;
        }
        return true;
    }
};