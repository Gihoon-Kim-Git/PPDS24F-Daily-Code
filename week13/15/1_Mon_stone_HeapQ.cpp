#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> Q;                     // priority_queue 는 Max Heap
        for (int stone : stones) Q.push(stone);

        while (Q.size() > 1) {
            int s1 = Q.top();
            Q.pop();
            int s2 = Q.top();
            Q.pop();
            if (s1 > s2) Q.push(s1-s2);            
        }

        return (Q.size() > 0) ? Q.top() : 0;
    }
};