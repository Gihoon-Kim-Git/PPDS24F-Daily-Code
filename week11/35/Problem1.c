#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int s_len = strlen(s);

    int front = 0;
    int rear = s_len-1;
    //bool flag = false;


    while (front < rear) {
        // 공백 및 알파벳과 숫자가 아닌 경우 앞쪽 포인터 이동
        if (!isalpha(s[front]) && !isdigit(s[front])) {
            front++;
            continue;
        }
        // 공백 및 알파벳과 숫자가 아닌 경우 뒤쪽 포인터 이동
        if (!isalpha(s[rear]) && !isdigit(s[rear])) {
            rear--;
            continue;
        }

        // 대소문자를 무시하며 비교
        if (tolower(s[front]) != tolower(s[rear])) {
            return false;
        }
        
        // 양쪽 포인터 이동
        front++;
        rear--;
    }

    return true;
}