#include <string>
#include <vector>
#include <algorithm> // to use sort()

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstring;
        for (int num : nums) numstring.push_back(to_string(num));

        auto compare = [](const string& x, const string& y) {
            return x + y > y + x;
        };

        sort(numstring.begin(), numstring.end(), compare);

        string result;
        for (const string& numstr : numstring) result += numstr;

        // return to_string(stoi(result));
        return result[0] == '0' ? "0" : result;
    }
};