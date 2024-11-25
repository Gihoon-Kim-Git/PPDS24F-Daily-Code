#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Store the characters and their frequencies in a vector
        vector<pair<int, char>> freqVec;
        for (auto& [ch, freq] : freqMap) {
            freqVec.push_back({freq, ch});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](pair<int, char>& a, pair<int, char>& b) {
            return a.first > b.first; // Sort by frequency descending
        });

        // Step 4: Build the resulting string
        string result;
        for (auto& [freq, ch] : freqVec) {
            result.append(freq, ch); // Append 'freq' times the character 'ch'
        }

        return result;
    }
};