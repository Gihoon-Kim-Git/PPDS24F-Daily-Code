#include <string>
#include <vector>

using namespace std;

/*
 * Class: Solution
 * ----------------
 * Provides a method to find the longest common prefix string amongst an array of strings.
 */
class Solution {
public:
    /*
     * Function: longestCommonPrefix
     * ------------------------------
     * Finds the longest common prefix among a list of strings.
     *
     * Examples:
     * ---------
     * Input: strs = ["flower","flow","flight"]
     * Output: "fl"
     *
     * Input: strs = ["dog","racecar","car"]
     * Output: ""
     * Explanation: There is no common prefix among the input strings.
     *
     * Approach:
     * ---------
     * 1. Start with the first string as the prefix.
     * 2. Compare the prefix with each string in the array.
     * 3. Truncate the prefix at the point of mismatch.
     * 4. Return the prefix or an empty string if no common prefix exists.
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Start with the first string as the prefix
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            // Compare the prefix with the next string
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;  // Increment j as long as characters match
            }
            // Truncate the prefix at the point of mismatch
            prefix = prefix.substr(0, j);

            // If the prefix becomes empty, return immediately
            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};