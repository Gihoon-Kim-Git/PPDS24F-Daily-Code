#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

/*

A string S consisting of N characters is considered to be properly nested if
any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(string &S);
that, given a string S consisting of N characters, returns 1 if S is properly
nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S =
"([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}'
and/or ')'.

*/

/**
 * @brief Stack-based nested-bracket validator
 *
 * @param S
 * @return 1 if S is properly nested
 * @return 0 else
 */
int solution(string& S) {
  stack<char> stk{};
  set<char> opener{'(', '[', '{'};
  map<char, char> pairs{{')', '('}, {']', '['}, {'}', '{'}};

  for (const char& c : S) {
    if (opener.find(c) == opener.end()) {
      if (stk.empty()) return 0;
      auto top_char = stk.top();
      stk.pop();
      if (top_char != pairs.find(c)->second) return 0;
    } else {
      stk.push(c);
    }
  }
  if (stk.empty()) return 1;
  return 0;
}

int main() {
  string example1 = "((())[]{})";
  assert(solution(example1) == 1);
  string example2 = "(]";
  assert(solution(example2) == 0);
  string example3 = "([)]()";
  assert(solution(example3) == 0);
}