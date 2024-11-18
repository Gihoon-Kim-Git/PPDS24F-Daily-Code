/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

string BinaryLcp(string l, string r) {
  int lim = min(l.size(), r.size());
  for (int i = 0; i < lim; ++i) {
    if (l[i] != r[i]) return l.substr(0, i);
  }
  return l.substr(0, lim);
}

string LcpHelper(vector<string>& strs, int lo, int hi) {
  if (lo == hi) return strs[lo];

  int mid = (lo + hi) / 2;
  string leftLcp = LcpHelper(strs, lo, mid);
  string rightLcp = LcpHelper(strs, mid + 1, hi);

  return BinaryLcp(leftLcp, rightLcp);
}

// Using Divide and Conquer
string longestCommonPrefix(vector<string>& strs) {
  return LcpHelper(strs, 0, strs.size() - 1);
}

int main() {
  vector<string> strs1{"flower", "flow", "flight"};
  assert(longestCommonPrefix(strs1) == "fl");

  vector<string> strs2{"dog", "racecar", "car"};
  assert(longestCommonPrefix(strs2) == "");
}