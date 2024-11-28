#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool Compare(vector<int>& trip1, vector<int>& trip2) {
        return trip1[1] < trip2[1]; // 시작 시간을 기준으로 정렬
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 시작 시간 기준으로 정렬
        sort(trips.begin(), trips.end(), Compare);

        // 최소 힙을 사용하여 종료 시간을 관리
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        int currentPassengers = 0;

        for (const auto& trip : trips) {
            // 현재 시점까지 완료된 모든 여정을 제거
            while (!heap.empty() && heap.top().first <= trip[1]) {
                currentPassengers -= heap.top().second; // 여정 인원 감소
                heap.pop();
            }

            // 새로운 여정을 추가
            currentPassengers += trip[0]; // 승객 추가
            heap.push({trip[2], trip[0]}); // 종료 시간과 승객 수 저장

            // 현재 승객이 용량 초과인지 확인
            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true; // 모든 여정을 처리할 수 있으면 true 반환
    }
};

/*
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 시작 시간 기준으로 trips 정렬
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // 시작 시간 기준 정렬
        });

        // 최소 힙 (종료 시간 기준)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int currentCapacity = 0;

        for (const auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            // 현재 시점 이전에 내릴 승객 처리
            while (!minHeap.empty() && minHeap.top().first <= start) {
                currentCapacity -= minHeap.top().second;
                minHeap.pop();
            }

            // 새로운 승객 태우기
            minHeap.emplace(end, passengers);
            currentCapacity += passengers;

            // 용량 초과 확인
            if (currentCapacity > capacity) {
                return false;
            }
        }

        return true;
    }
};

*/