
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 

#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> numStr;
        for (int num : nums) {
            numStr.push_back(to_string(num));
        }

        sort(numStr.begin(), numStr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string result = "";
        for (string s : numStr) {
            result += s;
        }

        return result[0] == '0' ? "0" : result;
        
    }
};