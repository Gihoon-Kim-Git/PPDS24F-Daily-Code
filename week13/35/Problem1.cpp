#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        if (stones.size() == 1)
        {
            return stones[0];
        }

        priority_queue<int> pq;

        for (auto stone : stones)
        {
            pq.push(stone);
        }

        while (pq.size() > 1)
        {
            int Largest = pq.top();
            pq.pop();
            int Second = pq.top();
            pq.pop();

            if (Largest != Second)
            {
                pq.push(Largest - Second);
            }
        }

        // If there are no stones left, return 0; otherwise, return the last stone
        return pq.empty() ? 0 : pq.top();
    }
};