#include <iostream>
using namespace std;

class Solution {
public:
    int lcpHelp(string s1, string s2) {
        int minlen = min(s1.size(), s2.size());
        for (int i=0; i<minlen; i++) if (s1[i] != s2[i]) return i;
        return minlen;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minlen = strs[0].size();
        for (int s=1; s<strs.size(); s++) {
            int temp = lcpHelp(strs[0], strs[s]);
            if (minlen > temp) minlen = temp;
        }
        string answer = strs[0].substr(0, minlen);
        return answer;
    }   
};

int main() {
    Solution result;
    vector<string> strs1 = {"flower","flow","flight"};
    cout << result.longestCommonPrefix(strs1) << endl;
    vector<string> strs2 = {"dog","racecar","car"};
    cout << result.longestCommonPrefix(strs2) << endl;
    vector<string> strs3 = {"cir","car"};
    cout << result.longestCommonPrefix(strs3) << endl;

    return 0;
}