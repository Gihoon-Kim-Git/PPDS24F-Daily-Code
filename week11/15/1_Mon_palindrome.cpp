#include <iostream>
#include <string>
#include <cctype> // for std::isalnum, std::tolower
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // 알파벳이나 숫자가 아닐 경우 건너뜀
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }
            
            // 대소문자를 무시하고 비교
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }

        return true;
    }
};