#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string frequencySort(const std::string& s) {
        // 빈도수를 계산
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // 빈도와 문자를 저장. freq에 있는 모든 키-값 쌍을 freqVec에 복사
        std::vector<std::pair<char, int>> freqVec(freq.begin(), freq.end()); 

        // 빈도수와 문자 순으로 정렬. 람다함수([](const auto& a, const auto& b)) 사용. 
        // return true: a가 b보다 앞에 와야 함, return false: b가 a보다 앞에 와야 함.
        std::sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first);
        });

        // 결과 문자열 생성
        std::string result;
        for (const auto& [ch, count] : freqVec) {
            result.append(count, ch);
        }

        return result;
    }
};
