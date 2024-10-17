/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's
triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above
it as shown:
*/

/*
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
*/
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> getRow(int row_index) {
  if (row_index == 0) {
    return vector<int>{1};
  }
  if (row_index == 1) {
    return vector<int>{1, 1};
  }
  vector<int> prev = getRow(row_index - 1);
  vector<int> curr{1};
  for (int i = 0; i < prev.size() - 1; ++i) {
    curr.push_back(prev[i] + prev[i + 1]);
  }
  curr.push_back(1);

  return curr;
}

string VecToString(vector<int> v) {
  ostringstream ss;
  ss << "[";
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    ss << v[i];
    if (i < n - 1)
      ss << ", ";
    else
      ss << "]";
  }
  return ss.str();
}

int main() {
  string res = VecToString(getRow(3));
  assert(res == "[1, 3, 3, 1]");
}