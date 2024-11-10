// you can use includes, for example:
#include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // Implement your solution here
    stack<char> stack;

    for (int i=0; i < S.size(); i++) {
        char currentChar = S[i];
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            stack.push(currentChar);
        }
        else if (currentChar == ')' and stack.top() == '(') {
            stack.pop();
        }
        else if (currentChar == '}' and stack.top() == '{') {
            stack.pop();
        }
        else if (currentChar == ']' and stack.top() == '[') {
            stack.pop();
        }
        else {
            stack.push(S[i]);
        }
    }
    return stack.empty() ? 1 : 0;
};