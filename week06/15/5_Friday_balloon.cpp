#include <iostream>         // 표준 입출력을 위한 헤더
#include <unordered_map>     // unordered_map을 사용하기 위한 헤더
#include <climits>           // INT_MAX 상수를 사용하기 위한 헤더
#include <string>            // string을 사용하기 위한 헤더

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> balloon = {{'b',0}, {'a',0}, {'l',0},{'o',0},{'n',0}};
        for (char letter : text) 
            if (balloon.find(letter) != balloon.end()) balloon[letter]++;
        balloon['l'] /= 2;
        balloon['o'] /= 2;

        int num = INT_MAX;
        for(const auto& pair : balloon)
            if (num > pair.second) num = pair.second;
        return num;
    }
};