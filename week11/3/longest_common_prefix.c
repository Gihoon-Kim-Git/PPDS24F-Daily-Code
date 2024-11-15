#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Problem Description:
 * --------------------
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
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
 * Constraints:
 * ------------
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 * Approach:
 * ---------
 * 1. Compare characters of the strings one by one.
 * 2. Stop when a mismatch occurs or when the end of any string is reached.
 * 3. Return the substring up to the point of mismatch.
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Start with the first string as the prefix
    char* prefix = strs[0];

    for (int i = 1; i < strsSize; i++) {
        // Compare the prefix with the next string
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;  // Increment j as long as characters match
        }
        // Truncate the prefix at the point of mismatch
        prefix[j] = '\0';

        // If the prefix becomes empty, return immediately
        if (strlen(prefix) == 0) {
            return "";
        }
    }

    return prefix;
}