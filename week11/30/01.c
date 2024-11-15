
// 목표: 알파벳만 추출해서 string으로 했을때 palin이냐 아니냐 검증 (기호, 띄어쓰기 등 다 생략)
// 전략
// 1. alpha인 i와 j(앞뒤에서 index가면서 while로) 찾는다.
// 2. 찾으면 같은지 검사하고 아니면 return false
// 3. i<=j일때까지 문제 없으면 return true

// 새로 알게된거
// alphabet(isalpha)을 다룰땐 lower upper 조심하자 (<ctype.h> -> tolower)
// '\0' char [] 끝날때를 나타내는 문자임. 
//1 <= s.length <= 2 * 105

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool isPalindrome(char* s) {


//(1). 공백으로만 이뤄졌는지 확인
    int k = 0;
    int is_blank_only = 1;  // 기본값을 1로 설정 (공백만 있는 상태)

    // 배열의 각 문자 검사
    while (s[k] != '\0') {
        if (s[k] != ' ') {  // 공백이 아닌 문자가 있을 경우
            is_blank_only = 0;  // 공백이 아닌 문자가 있으면 is_blank_only를 0으로 변경
            break;  // 더 이상 검사할 필요 없음
        }
        k++;
    }
    if (is_blank_only == 1) {
        return true;
    }

//(2). 그외 일반적인 경우. 
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while ((i <= j) && (i < len) && (j >= 0)) {
        // alpha인 i와 j를 찾는다.
        while ((isalpha(s[i]) == 0)) {
            i++;
            printf("%c is not alpha.\n", s[i]);
        }
        while ((isalpha(s[j]) == 0)) {
            j--;
            printf("%c is not alpha.\n", s[j]);
        }
        //찾았다!
        if (tolower(s[i]) != tolower(s[j])) {
            printf("%c != %c \n", s[i], s[j]);
            return false;
        };

        //체크헀으면 다음으로 가즈앙
        printf("%c == %c \n", s[i], s[j]);
        i++;
        j--;
    }    
    
    return true;
}

int main() {

    char ex1[] = "A man, a plan, a canal: Panama";
    char ex2[] = "race a car";
    char ex3[] = " ";

    printf("EX1: %s\n", isPalindrome(ex1) == true ? "true":"false" );
    printf("EX2: %s\n", isPalindrome(ex2) == true ? "true":"false" );
    printf("EX3: %s\n", isPalindrome(ex3) == true ? "true":"false" );
    return 0;
}