#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        int len = temp.size();
        string ans = "";

        for(int i=0;i<len;i++){
            for(string str : strs){
                if(i==str.size() || str[i]!=temp[i]) return ans;
            }
            ans += temp[i];
        }
        return ans;
    }
};