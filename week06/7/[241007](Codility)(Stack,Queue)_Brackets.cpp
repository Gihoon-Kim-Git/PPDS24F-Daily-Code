/* 문제 : Brackets
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
    S is empty;
    S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
    S has the form "VW" where V and W are properly nested strings.
    For example, the string "{[()()]}" is properly nested but "([)()]" is not.
Write a function:
    int solution(string &S);
that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
*/

/* 문제풀이
    1. stack 원리 이용, 
    2. S를 순회하면서 별도의 리스트(vector)에 넣는다. 조건에 맞는 경우에만 pop_back. 나머지는 push_back. 
        - pop 조건 : close bracket 이면서 리스트의 마지막 요소가 상응하는 bracket일때.
        - 주의사항 : list에 아무것도 없는 상태에서 close bracket을 append해야하면 false.
    3. 2가 끝난후 vector의 길이가 0이면 true, 0이 아니면 false
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(string &S){
    vector<char> check_l;
    for (char s : S){
        if (check_l.size() == 0 ){
            if (s == ')' || s == ']'|| s == '}' ) return 0;
            else check_l.push_back(s);
        }
        else {
            if (s == '(' || s == '['|| s == '{' ) check_l.push_back(s);
            if (s == ')') {
                if (check_l[check_l.size()-1] == '(') check_l.pop_back();
                else check_l.push_back(s);
            }
            if (s == ']') {
                if (check_l[check_l.size()-1] == '[') check_l.pop_back();
                else check_l.push_back(s);
            }
            if (s == '}') {
                if (check_l[check_l.size()-1] == '{') check_l.pop_back();
                else check_l.push_back(s);
            }
        }
    }
    // S 순회가 끝난 후 check_l 길이가 0인지 여부 확인 : 0이면 True, 아니면 False
    return check_l.size() == 0 ? 1 : 0;
}


int main(){
    string S1 =  "{[()()]}";
    cout << solution(S1) << endl; 
    string S2 =  "([)()]";
    cout << solution(S2) << endl; 
    
    return 0;
}