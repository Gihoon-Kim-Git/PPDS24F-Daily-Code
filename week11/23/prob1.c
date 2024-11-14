#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

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
    char s[] = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
