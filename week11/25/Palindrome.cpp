#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int count = s.size();
            
            int start =0;
            int end = count-1;

            while (start < end) {
                while (!isalnum(s[start]) && (start < count -1)) {
                    start++;
                    }
                while (!isalnum(s[end]) && (end >0)) { 
                    end--;
                    }
                if (start < end) {
                    if (tolower(s[start]) == tolower(s[end])) {start++; end--;}
                    else {return false;}
                }      
            }

            return true;
        }
};

int main(void) {
    Solution a;
    int b = a.isPalindrome(".,");
    cout << b << endl;
    return 1;
}