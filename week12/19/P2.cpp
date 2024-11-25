#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string answer("");
        answer[0] = '\0';
        if (nums.size() == 0) return "";
        sort(nums.begin(), nums.end(), compare);
        for (int i=0; i<nums.size(); i++) {
            answer += to_string(nums[i]);
        }
        if (answer[0] == '0') return "0";
        return answer;
    }
};

int main() {
    vector<int> nums1 = {10, 2};
    vector<int> nums2 = {3, 30, 34, 5, 9};

    Solution result;
    cout << result.largestNumber(nums1) << endl;
    cout << result.largestNumber(nums2) << endl;
    
    return 0;
}