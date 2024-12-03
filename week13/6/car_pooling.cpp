#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    auto cmp = [](const vector<int> l, const vector<int> r) {
      if (l[0] != r[0]) return l[0] > r[0];
      return l[1] > r[1];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (auto trip : trips) {
      pq.push({trip[1], trip[0]});
      pq.push({trip[2], -trip[0]});
    }

    int passengers = 0;
    while (!pq.empty()) {
      auto delta = pq.top();
      pq.pop();
      passengers += delta[1];
      if (passengers > capacity) return false;
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> t1{{2, 1, 5}, {3, 3, 7}};
  assert(!sol.carPooling(t1, 4));
  vector<vector<int>> t2{{2, 1, 5}, {3, 3, 7}};
  assert(sol.carPooling(t2, 5));
  vector<vector<int>> t3{{2, 1, 5}, {3, 5, 7}};
  assert(sol.carPooling(t3, 3));
}