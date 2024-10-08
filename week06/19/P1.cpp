#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int solution(string S) {
        stack<char> s;
        int i = 0;
        while (i < S.size()) {
            if (S[i] == '{') s.push('}');
            else if (S[i] == '[') s.push(']');
            else if (S[i] == '(') s.push(')');
            else {
                if (s.empty() || S[i] != s.top()) {
                    return 0;
                }
                s.pop();
            }
            i++;
        }
        if (!s.empty()) {
            return 0;
        }
        return 1;
    }
};

int main() {
    string s1 = "{[()()]}";
    string s2 = "([)()]";
    
    Solution result;
    cout << result.solution(s1) << endl;
    cout << result.solution(s2) << endl;

    return 0;
}