#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int n = strlen(s);
    int h = 0;
    int t = n-1;
    while(h<=t){
        if(!isalnum(s[h])){
            h++;
            continue;
        }
        else if(!isalnum(s[t])){
            t--;
            continue;
        }
        else if(tolower(s[h])!=tolower(s[t])) return false;
        else{
            h++;
            t--;
        }
    }
    return true;
}