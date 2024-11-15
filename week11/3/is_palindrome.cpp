#include <string>
#include <cctype>  // For isalnum() and tolower()

using namespace std;

/*
 * Class: Solution
 * ----------------
 *  Provides a method to check if a given string `s` is a palindrome.
 */
class Solution {
public:
    /*
     * Function: isPalindrome
     * ----------------------
     *  Checks if the given string `s` is a palindrome.
     *
     *  Steps:
     *  1. Convert all uppercase letters to lowercase.
     *  2. Remove all non-alphanumeric characters.
     *  3. Compare the cleaned string with its reverse to check if it is a palindrome.
     *
     *  Input:
     *    - s: The input string (consists of printable ASCII characters).
     *
     *  Output:
     *    - true if `s` is a palindrome, false otherwise.
     */
    bool isPalindrome(string s) {
        int left = 0;                    // Pointer to the start of the string
        int right = s.length() - 1;      // Pointer to the end of the string

        while (left < right) {           // Traverse until pointers meet
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // Compare lowercase versions of the characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;            // Mismatch means not a palindrome
            }
            left++;                      // Move to the next character
            right--;
        }
        return true;                     // String is a palindrome
    }
};