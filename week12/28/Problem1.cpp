#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<pair<int, char>> freqPairs;
        for (auto& [ch, count] : freq) freqPairs.emplace_back(count, ch);
        sort(freqPairs.rbegin(), freqPairs.rend());
        string result;
        for (auto& [count, ch] : freqPairs) result.append(count, ch);
        return result;
    }
};