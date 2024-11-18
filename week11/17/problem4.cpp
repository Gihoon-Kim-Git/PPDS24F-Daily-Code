
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        int max_len = 0;

        for (string s: strs){
            max_len = max(max_len, (int)s.size());
        }

        for (int i=0; i < max_len; i++){

            for (string s: strs){
                if (s[i] != strs[0][i]){
                    return ans;
                }
            }

            ans += strs[0][i];

        }
        

        return ans;
    }
};