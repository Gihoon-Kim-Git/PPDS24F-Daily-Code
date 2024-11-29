#include <cassert>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;

    for (auto stone : stones) pq.push(stone);

    int el1, el2;
    while (!pq.empty()) {
      el1 = pq.top();
      pq.pop();
      if (pq.empty()) return el1;
      el2 = pq.top();
      pq.pop();
      if (el1 != el2) {
        pq.push(abs(el1 - el2));
      }
    }

    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> s1{2, 7, 4, 1, 8, 1};
  assert(sol.lastStoneWeight(s1) == 1);
  vector<int> s2{2, 2};
  assert(sol.lastStoneWeight(s2) == 0);
}