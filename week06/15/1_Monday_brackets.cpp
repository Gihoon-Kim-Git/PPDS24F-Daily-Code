// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <string>

#include <stack>

using namespace std;

int solution(string &S) {
    // Implement your solution here
    stack<char> bracket;
    for (char c : S)
        if (c == '(' || c == '{' || c == '[')
            bracket.push(c);
        
        else if (c == ')')
            if (bracket.top() != '(') return 0;
            else bracket.pop();
        else if (c == '}') 
            if (bracket.top() != '{') return 0;
            else bracket.pop();
        else 
            if (bracket.top() != '[') return 0;
            else bracket.pop();
    
    if (bracket.empty()) return 1;
    else return 0;            
}