/*

Given a string text, you want to use the characters of text to form as many
instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of
instances that can be formed.

*/
#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>

using namespace std;

int MaxNumberOfBalloons(string text) {
  map<char, int> cnt;
  set<char> balloon;
  for (const char& c : "balloon") {
    cnt[c] = 0;
    balloon.insert(c);
  }
  cnt.erase('\0');
  balloon.erase('\0');

  for (const char& c : text) {
    if (balloon.find(c) != balloon.end()) {
      cnt[c]++;
    }
  }

  // These require double the amount
  cnt['l'] /= 2;
  cnt['o'] /= 2;

  using CntVal = decltype(cnt)::value_type;

  return min_element(
             cnt.begin(), cnt.end(),
             [](CntVal& l, CntVal& r) -> bool { return l.second < r.second; })
      ->second;
}

int main() {
  string text1 = "nlaebolko";
  assert(MaxNumberOfBalloons(text1) == 1);

  string text2 = "loonbalxballpoon";
  assert(MaxNumberOfBalloons(text2) == 2);

  string text3 = "leetcode";
  assert(MaxNumberOfBalloons(text3) == 0);

  string text4 = "balon";
  assert(MaxNumberOfBalloons(text4) == 0);
}