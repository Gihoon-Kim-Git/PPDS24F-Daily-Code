#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // priority queue의 Max-Heap 사용
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // 힙에 돌이 하나 이상 남아 있는 동안 가장 무거운 두 개의 돌을 꺼내서 check
        while (maxHeap.size() > 1) {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int second_heaviest = maxHeap.top();
            maxHeap.pop();
            
            // 두 돌의 무게가 다를 경우 새로운 돌을 힙에 추가, 무게가 같은 경우 그대로 삭제
            if (heaviest != second_heaviest) {
                maxHeap.push(heaviest - second_heaviest);
            }
        }
        
        // 힙에 남아 있는 돌이 있다면 그 무게를 반환하고, 없다면 0을 반환
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
