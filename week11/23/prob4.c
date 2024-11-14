#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

char* longestCommonPrefix(char strs[][MAX_LENGTH], int n) {
    if (n == 0) return "";
    
    static char prefix[MAX_LENGTH];
    strcpy(prefix, strs[0]);
    int prefix_len = strlen(prefix);
    
    for (int i = 1; i < n; ++i) {
        while (strncmp(prefix, strs[i], prefix_len) != 0) {
            prefix_len--;
            if (prefix_len == 0) return "";
            prefix[prefix_len] = '\0';  // Truncate the prefix
        }
    }
    return prefix;
}

int main() {
    char strs[MAX_STRINGS][MAX_LENGTH] = {"flower", "flow", "flight"};
    int n = 3;  // Number of strings
    
    printf("%s\n", longestCommonPrefix(strs, n));
    return 0;
}
