// 125. Valid Palindrome
// Easy
// Topics
// Companies
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {

        // 포인터 하나씩 옮겨가면서 ...
        int left = 0;
        int right = s.size() - 1;

        while (left < right){

            if (!isalnum(s[left])){
                left++;
                continue;
            }

            if (!isalnum(s[right])){
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;

    }

};

