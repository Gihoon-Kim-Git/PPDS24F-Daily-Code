#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> stack;

int solution(string &S){
    if (S == "") return 1;

    for (char &c: S) {

        if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) { 
                return 0;
            } else {
                if (c ==')' && stack.back() == '('){
                    stack.pop_back();
                } else if (c == ']' && stack.back() == '['){
                    stack.pop_back();
                } else if (c == '}' && stack.back() == '{'){
                    stack.pop_back();
                } else return 0;
            }
        } else if(c =='(' || c == '[' || c == '{' ) 
            stack.push_back(c);
    }
    return stack.empty();
    
}

int main(){
    
    string s1 = "([{}{}])";
    string s2 = "([)()]";
    string s3 = "";
    string s4 = ")";
    string s5 = ")()";

    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
    cout << solution(s3) << endl;
    cout << solution(s4) << endl;
    cout << solution(s5) << endl;
    
    return 0;
}

