#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> renums;
        for (int num : nums) {
            renums.push_back(to_string(num)); // 정수를 문자열로 변환
        }

        for(int i = 1; i< nums.size(); i++){
            string pivot = renums[i];
            int j = i-1;
            while(j >= 0 && renums[j] + pivot < pivot + renums[j]){
                renums[j+1] = renums[j];
                j--;
            }
            renums[j+1] = pivot;
        }

        string result;
        for (string s : renums){
            result += s;
        }
        if (result[0] == '0') return "0";
        return result;
    }

    string largestNumber2(vector<int>& nums) {
        // Step 1: Convert integers to strings
        vector<string> renums;
        for (int num : nums) {
            renums.push_back(to_string(num));
        }

        // Step 2: Sort the strings based on the custom comparator
        sort(renums.begin(), renums.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Compare concatenated results
        });

        // Step 3: Concatenate sorted strings
        string result;
        for (string s : renums) {
            result += s;
        }

        // Step 4: Handle the case where the result is all zeros
        if (result[0] == '0') return "0";

        return result;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << endl; // Output: "9534330"
    return 0;
}
