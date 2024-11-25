class Solution {
public:
    static bool compare(const int& a, const int& b) {
        string strA = to_string(a);
        string strB = to_string(b);
        return strA + strB > strB + strA;
    }

    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), compare);

        for (auto num : nums) {
            ans += to_string(num);
        }
        if (ans[0] == '0') return "0";

        return ans;
    }
};