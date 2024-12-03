/*You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.*/

/*아이디어  (C++의 priority_queue는 maxHeap 기반)
    1. priority_queue에 stones의 모든 값을 담고
    2. 두 개를 뺀다.
        bigger
        smaller
    3. bigger-smaller를 다시 priority_queue에 넣는다.
    4. 2~3과정을 priority_queue의 사이즈가 1 또는 0이 될 때까지 계속한다.
    5. 4가 끝나면, priority_queue의 사이즈에 따라 결과 반환
        - 사이즈가 1이면 해당 값 반환
        - 사이즈가 0이면 0 반환
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> rocks;
        for (int stone : stones){
            rocks.push(stone);
        }
        while (rocks.size() > 1) {
            int bigger = rocks.top();
            rocks.pop();
            int smaller = rocks.top();
            rocks.pop();
            rocks.push(bigger-smaller);
        }

        if (rocks.size() == 0) return 0;
        else return rocks.top();
    }
};