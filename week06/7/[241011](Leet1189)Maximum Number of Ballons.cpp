/*문제 :
text가 주어졌을 때, text가 최대한 많은 'balloon'을 만들도록 하고 싶다. text 안의 character는 최대 한 번만 사용할 수 잇음. 
만들 수 있는 'balloon'의 최대 개수*/

/* 문제풀이  : map을 써도되지만 굳이 쓰지 않았음. unordered_map<char, int>
    1. b, a, l,o,n의 횟수를 세는 변수 선언.
    2. text를 처음부터 끝까지 순회하면서 1에서 선언한 변수의 값 키우기
    3. while b, a, n >= 1 이고 l, o >= 2인 동안 answer ++, b--, a--, n--, l -= 2, o -=2
*/

#include <iostream>
#include <string>

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cntB = 0, cntA = 0, cntL = 0, cntO = 0, cntN = 0 ;

        for (char c : text){
            if (c == 'b') cntB++;
            if (c == 'a') cntA++;
            if (c == 'l') cntL++;
            if (c == 'o') cntO++;
            if (c == 'n') cntN++;
        }

        int ans = 0;
        while (cntB >= 1 && cntA >= 1 && cntN >= 1 && cntL >=2 && cntO >=2){
            ans++;
            cntB--;
            cntA--;
            cntN--;
            cntL -= 2;
            cntO -= 2;
        }

        return ans;
    }
};