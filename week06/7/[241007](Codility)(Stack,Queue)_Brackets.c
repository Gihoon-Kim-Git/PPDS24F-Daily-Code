/* 문제 : Brackets
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
    S is empty;
    S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
    S has the form "VW" where V and W are properly nested strings.
    For example, the string "{[()()]}" is properly nested but "([)()]" is not.
Write a function:
    int solution(char *S);
    that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
*/

/* 문제풀이
    1. stack 원리 이용, list 대신 array로. 그리고 마지막 자리요소를 추적하기 위해서 int length 변수 관리.
    2. S를 순회하면서 별도의 리스트에 넣는다. 조건에 맞는 경우에만 pop. 나머지는 append. 
        - pop 조건 : close bracket 이면서 리스트의 마지막 요소가 상응하는 bracket일때.
        - 주의사항 : list에 아무것도 없는 상태에서 close bracket을 append해야하면 false.
    3. 2가 끝난후 vector의 길이가 0이면 true, 0이 아니면 false
*/

#include <stdio.h>
#include <stdlib.h>
#define max_length 200000

int solution(char *S){
    char check[max_length] ;
    int cur_len = 0;

    int i = 0;
    while (S[i]){
        if (S[i] == '('|| S[i] == '['|| S[i] == '{') check[cur_len++] = S[i];
        else { // (S[i] == ')'|| S[i] == '}'|| S[i] == ']')
            if (cur_len == 0) return 0;
            if (S[i] == ')') {
                if (check[cur_len-1] == '(') cur_len--;
                else check[cur_len++] = S[i];
            }
            if (S[i] == ']') {
                if (check[cur_len-1] == '[') cur_len--;
                else check[cur_len++] = S[i];
            } 
            if (S[i] == '}') {
                if (check[cur_len-1] == '{') cur_len--;
                else check[cur_len++] = S[i];
            }         
        }
        //현재 ch 확인이 끝나면
        i++;
    }
    // S 순회 종료 후 cur_len이 0인지 확인.
    return cur_len == 0? 1 : 0;
}

int main(){
    char S1[9] =  "{[()()]}";
    printf("%d\n", solution(S1)); 
    char S2[6] =  "([)()]";
    printf("%d\n", solution(S2)); 
    
    return 0;
}