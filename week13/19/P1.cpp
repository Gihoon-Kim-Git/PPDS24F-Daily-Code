#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i=0; i<stones.size(); i++) {
            maxHeap.push(stones[i]);
        }
        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (first > second) {
                maxHeap.push(first - second);
            }
        }
        if (maxHeap.size() > 0) return maxHeap.top();
        return 0;
    }
};

int main() {
    Solution result;
    vector<int> stones1 = {2,7,4,1,8,1};
    cout << result.lastStoneWeight(stones1) << endl;
    vector<int> stones2 = {1};
    cout << result.lastStoneWeight(stones2) << endl;

    return 0;
}