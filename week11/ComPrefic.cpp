#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_size = INT_MAX;
        for (auto each : strs) {
            if (each.size() < min_size) {min_size = each.size();}
        }

        int count = 0;
        string result = "";
        
        while (count < min_size) {
            char check = strs[0][count];
            bool check_b = true;
            for (auto each : strs) {
                if (check != each[count]) {
                    check_b = false;
                }
            }
            if (check_b == true) {result.push_back(check); ++count;}
            else {
                break;
            }
        }
        
        return result;
    }
};

int main(void) {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(strs);
    cout << result << endl;
    return 1;
}