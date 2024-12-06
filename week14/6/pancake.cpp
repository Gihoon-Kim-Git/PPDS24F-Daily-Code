#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    int n = arr.size(), max;
    vector<int> res;
    std::vector<int>::iterator itr = arr.begin();
    while (n > 0) {
      max = 0;
      for (int i = 0; i < n; i++) {
        if (arr[i] > arr[max]) max = i;
      }
      int target = arr[max], pos = max;
      while (arr[n - 1] != target) {
        res.push_back(pos + 1);
        reverse(itr, itr + pos + 1);
        pos = 0;
        res.push_back(n);
        reverse(itr, itr + n);
      }
      n--;
    }
    return res;
  }
};