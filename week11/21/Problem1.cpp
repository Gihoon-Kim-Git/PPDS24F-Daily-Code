#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> ref;
        int len = s.length();
        for(int i=0 ; i<len ; i++){
            if(s[i]>=65 && s[i]<=90) {
                ref.push_back(s[i]+32);}
            else if(s[i]>=97 && s[i]<=122) ref.push_back(s[i]);
            else if(s[i]>=48 && s[i]<=57) ref.push_back(s[i]);
            else continue;
        }

        int len2 = ref.size();
        for(int i=0 ; i<len2 ; i++){
            if(ref[i] == ref[len2-i-1]) continue;
            else if(ref[i] != ref[len2-i-1]) return false;
        }
        return true;
    }
};