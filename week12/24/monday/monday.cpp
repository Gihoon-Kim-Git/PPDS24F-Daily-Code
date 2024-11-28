// Sort Characters By Frequency

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq; // 문자와 그 문자의 개수를 저장하는 해시 맵
        for (char c : s) { // s를 순회하면서 각 문자의 개수를 세고, 그 개수와 문자를 튜플로 만들어서 정렬
            freq[c]++; // 문자의 개수를 세고
        }
        vector<pair<char, int>> freq_vec(freq.begin(), freq.end()); // 해시 맵을 벡터로 변환
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) { // a와 b를 비교
            return a.second > b.second; // 문자의 개수를 기준으로 정렬 
        });
        string result; // 결과를 저장할 문자열
        for (const auto& p : freq_vec) { // 정렬된 벡터를 순회하면서 각 문자를 그 문자의 개수만큼 반복하여 문자열로 변환
            result.append(p.second, p.first); // 문자를 그 문자의 개수만큼 반복하여 문자열로 변환
        }
        return result;
    }
};