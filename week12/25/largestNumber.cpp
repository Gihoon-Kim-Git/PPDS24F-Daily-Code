#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1: Convert integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Step 2: Sort using a custom comparator
        sort(strNums.begin(), strNums.end(), [](string& a, string& b) {
            return a + b > b + a; // Compare concatenated results
        });

        // Step 3: Handle the edge case of leading zeros
        if (strNums[0] == "0") {
            return "0";
        }

        // Step 4: Concatenate the sorted strings
        string result;
        for (string& str : strNums) {
            result += str;
        }

        return result;
    }
};