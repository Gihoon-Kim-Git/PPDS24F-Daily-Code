/*
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> //isalnum

//recursive한 풀이
    //s의 start, end 글자가 같으면 s(start+1, end-1)를 확인.
    // 만약 start > end가 되면 return True
    // 만약 s[start] != s[end] 이면 return False

bool isPalindrome_help(char* text, int start, int end){
    if (start >= end) return true;
    if (text[start] != text[end]) return false;
    return isPalindrome_help(text, start+1, end-1);
}

bool isPalindrome(char* s) {
    //검사용인 text의 끝에 한글자씩 더한다. s를 돌면서 숫자와 영어소문자는 더하고, 대문자는 소문자로 전환하고.
    int s_len = 0;
    while(s[s_len] != '\0'){
        s_len++;
    } 

    char* cleaned_s = (char*)malloc(sizeof(char)*(s_len+1)); // '\0'을 고려한 길이
    int j = 0;
    for (int i = 0; i < s_len; i++){
        if (isalnum(s[i])){
            //if (isupper(s[i])) cleaned_s[j] = tolower(s[i]);
            if (65 <= s[i] && s[i] <=90) cleaned_s[j] = s[i]+32;  
            else cleaned_s[j] = s[i];
            j++;
        }
    }
    cleaned_s[j] = '\0';
    
    if (j <= 1) return true; //길이가 0 또는 1이면 무조건 palindrome

    int start = 0;
    int end = j-1;

    return isPalindrome_help(cleaned_s, start, end);
}