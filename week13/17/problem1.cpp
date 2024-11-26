

// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

// priority queue

#include <vector>
#include <queue>
 
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(), stones.end());

        while (!pq.empty()){

            if (pq.size() == 1) {
                return pq.top();
            }

            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x != y) {
                pq.push(x - y);
            }

        }

        return 0;
        
    }
};
