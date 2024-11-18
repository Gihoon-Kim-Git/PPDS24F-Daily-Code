#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        int len1 = strs[0].length();
        int chk = 0;
        string ans = "";
        for(int i=0; i<len1; i++){
            for(int j=0; j<len; j++){

                if(strs[0][i] != strs[j][i]) {
                    chk = 1;
                }
            }
            if(chk==0) ans += strs[0][i];

            
        }
        return ans;
    }
};