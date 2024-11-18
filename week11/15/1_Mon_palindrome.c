#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char *s) {
    char string[1000];
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i])) {
            string[j++] = tolower(s[i]);
        }
    }
    string[j] = '\0';

    int len = strlen(string);
    for (int i = 0; i < len / 2; i++) {
        if (string[i] != string[len - i - 1]) {
            return false;
        }
    }
    return true;
}
