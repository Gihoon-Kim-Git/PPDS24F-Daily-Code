// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
#include <iostream>
using namespace std;
int solution(string &S) {
    // Implement your solution here
    if(S.empty()) return 1;
    stack<char> s;
    for(const char ch : S){
        if(ch==')'){
            if(s.empty() || s.top()!='(') return 0;
            else s.pop();
        }
        else if(ch=='}'){
            if(s.empty() || s.top()!='{') return 0;
            else s.pop();
        }
        else if(ch==']'){
            if(s.empty() || s.top()!='[') return 0;
            else s.pop();
        }
        else s.push(ch);
    }
    if(s.empty()) return 1;
    else return 0;
}