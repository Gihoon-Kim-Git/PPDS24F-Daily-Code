#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Start with the first string as the initial prefix
        string prefix = strs[0];

        // Compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); ++i) {
            // Find the common prefix between prefix and strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);  // Trim the last character
                if (prefix.empty()) return "";  // If there's no common prefix
            }
        }
        
        return prefix;
    }
};
