#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int lcpHelp(char* s1, char* s2) {
    int minlen = min(strlen(s1), strlen(s2));
    for (int i=0; i<minlen; i++) if (s1[i] != s2[i]) return i;
    return minlen;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    int minlen = strlen(strs[0]);
    for (int s=1; s<strsSize; s++) {
        int temp = lcpHelp(strs[0], strs[s]);
        if (minlen > temp) minlen = temp;
    }
    char* answer = (char*)malloc(sizeof(char) * minlen);
    strncpy(answer, strs[0], minlen);
    answer[minlen] = '\0';
    return answer;
}

int main() {
    char* strs1[] = {"flower","flow","flight"};
    printf("%s\n", longestCommonPrefix(strs1, 3));
    char* strs2[] = {"dog","racecar","car"};
    printf("%s\n", longestCommonPrefix(strs2, 3));
    char* strs3[] = {"cir","car"};
    printf("%s\n", longestCommonPrefix(strs3, 2));
    
    return 0;
}