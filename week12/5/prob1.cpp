#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // initialize
        unordered_map<char, int> chars;
        for(char c{'A'}; c<='Z'; c++) {
            chars[c] = 0;
        }
        for(char c{'a'}; c<='z'; c++) {
            chars[c] = 0;
        }
        // for(const auto& pair : chars) {
        //     cout << pair.first << " ";
        // }
        
        // char count
        for(char c : s) {
            chars[c] += 1;
        }

        string answer;
        // pop max
        for(int i = s.size(); i>=0; i--) {
            for(auto& pair : chars) {
                if (pair.second == i) {
                    answer += string(pair.second, pair.first);
                    pair.second = 0;
                }
            }
        }
        return answer;
    }
};
