#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  struct Elem {
    int soldiers;
    int row;
  };

 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    auto cmp = [](Elem l, Elem r) {
      if (l.soldiers != r.soldiers) return l.soldiers > r.soldiers;
      return l.row > r.row;
    };

    priority_queue<Elem, vector<Elem>, decltype(cmp)> pq(cmp);

    for (int r = 0; r < n; ++r) {
      int soldiers = 0;
      for (int e : mat[r]) {
        if (e == 1) ++soldiers;
      }
      pq.push(Elem{soldiers, r});
    }

    vector<int> res(k);
    for (int i = 0; i < k; ++i) {
      res[i] = pq.top().row;
      pq.pop();
    }

    return res;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> mat1 = {{1, 1, 0, 0, 0},
                              {1, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0},
                              {1, 1, 0, 0, 0},
                              {1, 1, 1, 1, 1}};
  vector<int> ans1 = {2, 0, 3};
  assert(sol.kWeakestRows(mat1, 3) == ans1);

  vector<vector<int>> mat2 = {
      {1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  vector<int> ans2 = {0, 2};
  assert(sol.kWeakestRows(mat2, 2) == ans2);
}