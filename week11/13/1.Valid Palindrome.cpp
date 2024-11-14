#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    // Helper function to check if a character is alphanumeric
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    // Helper function to convert uppercase letters to lowercase
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A'); // Convert to lowercase
        }
        return c; // Return as is if already lowercase or a digit
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }
            
            // Convert characters to lowercase and compare
            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
