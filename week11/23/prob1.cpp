#include <iostream>
#include <cctype>
#include <string>

bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare the characters after converting to lowercase
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
