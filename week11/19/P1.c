#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int start=0;
    int end=strlen(s)-1;
    while(start<=end){
        if(!isalnum(s[start])){start++; continue;}
        if(!isalnum(s[end])){end--;continue;}
        if(tolower(s[start])!=tolower(s[end]))return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
    printf("%d\n", isPalindrome("race a car"));
    printf("%d\n", isPalindrome(" "));
    return 0;
}