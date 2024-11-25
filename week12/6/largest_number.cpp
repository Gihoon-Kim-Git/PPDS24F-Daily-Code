#include <algorithm>
#include <cassert>
#include <cstdbool>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
  return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string largestNumber(vector<int>& nums) {
  ostringstream os;

  sort(nums.begin(), nums.end(), cmp);

  for (auto num : nums) os << num;

  string res = os.str();
  return res[0] == '0' ? "0" : res;
}

int main() {
  vector<int> ns0{0, 0};
  assert(largestNumber(ns0) == "0");
  vector<int> ns1{10, 2};
  assert(largestNumber(ns1) == "210");
  vector<int> ns2{3, 30, 34, 5, 9};
  assert(largestNumber(ns2) == "9534330");
}
