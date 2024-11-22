// 451. Sort Characters By Frequency
// Medium
// Topics
// Companies
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
 


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        map<char, int> alphaCount;
        for (char c : s) {
            alphaCount[c]++;
        }

        vector<pair<int, char>> countAlpha;
        for (auto it = alphaCount.begin(); it != alphaCount.end(); it++) {
            countAlpha.push_back({it->second, it->first});
        }

        sort(countAlpha.begin(), countAlpha.end(), greater<pair<int, char>>());

        string result = "";

        for (auto it = countAlpha.begin(); it != countAlpha.end(); it++) {
            for (int i = 0; i < it->first; i++) {
                result += it->second;
            }
        }

        return result;
    }
};