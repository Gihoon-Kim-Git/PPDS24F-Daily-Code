// 14. Longest Common Prefix
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        int pref_len = pref.size();
        for (int i = 1; i < strs.size(); ++i){
            while (pref != strs[i].substr(0, pref_len)){
                pref_len --;
                if (pref_len == 0){
                    return "";
                }
                pref = pref.substr(0, pref_len);
            }
        }
        return pref;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << sol.longestCommonPrefix(strs) << std::endl;
    return 0;
}