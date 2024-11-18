#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].length();
        for (string str : strs) {
            if (str.length() < min_len) min_len = str.length();
        }

        string prefix = "";
        for (int i=0; i<min_len; i++) {
            char candi = strs[0][i];
            for (string str : strs) {
                if (str[i] != candi) return prefix;
            }
            prefix += candi;
        }

        return prefix;
    }
};
