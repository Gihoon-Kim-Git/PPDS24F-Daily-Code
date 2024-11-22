/*
Leetcode 179
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // An array to store the converted numbers
        vector<string> v;
        
        // Converting all the numbers into string format and storing in the array
        for(int i: nums){
            v.push_back(to_string(i));
        }
        
        // Custom Sorting based on the biggest of 2 when concatenated.
        sort(v.begin(), v.end(), [&](string a,  string b) {
            return a+b > b+a;
        });
        
        // result string to store the results
        string result = "";
        for(string c: v){
            result+=c;
        }
        
        // Checking if the result is 0
        if(result[0] == '0') return "0";
        
        // returning the result.
        return result;
    }
};