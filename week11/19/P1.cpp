#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){start++; continue;}
            if(!isalnum(s[end])){end--;continue;}
            if(tolower(s[start])!=tolower(s[end]))return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }   
};

int main() {
    Solution result;
    cout << result.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << result.isPalindrome("race a car") << endl;
    cout << result.isPalindrome(" ") << endl;

    return 0;
}