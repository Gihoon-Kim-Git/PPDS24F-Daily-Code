// Largest Number
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.
// ex
// Input: nums = [10,2]
// Output: "210"

    bool compare(string a, string b) {
        return a + b > b + a;
    }

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> temp = {};
        for(auto i : nums){
            temp.push_back(to_string(i));
        }

        sort(temp.begin(), temp.end(), compare);

        string ans;

        for(int i=0; i<temp.size(); i++) ans += temp[i];

        return ans[0] == '0' ? "0" : ans;
    }
};