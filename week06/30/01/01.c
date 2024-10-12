#include <stdio.h>
#include <stdlib.h>

#define MAX INT_MAX

//전략
//1. 시작괄호면: stack에 하나씩 쌓고 
//2. 닫는괄호면: 
// 2.1. 끝에있는거를 pop했을때 짝이 맞으면 stack에서 시작괄호도 지움. 
// 2.2. 짝이 안맞으면 false 뱉음 

int solution(char *S) {
    // 빈 문자열인 경우, 항상 올바르게 중첩된 것으로 간주
    if (S == NULL || strlen(S) == 0) {
        return 1;
    }
    
    char stack[MAX];
    int top = -1;
    
    // 문자열의 길이 계산
    int N = strlen(S);
    
    // 문자열의 각 문자에 대해 처리
    for (int i = 0; i < N; i++) {
        char current = S[i];
        
        // 여는 괄호인 경우, 스택에 추가
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;  // 스택에 push
        } else {
            // 닫는 괄호가 나오면 스택이 비어있지 않은지 확인
            if (top == -1) {
                return 0;  // 스택이 비어있으면 올바르지 않음
            }
            
            char last = stack[top--];  // 스택에서 pop
            
            // 현재 괄호와 스택의 top 괄호가 짝이 맞는지 확인
            if ((current == ')' && last != '(') ||
                (current == ']' && last != '[') ||
                (current == '}' && last != '{')) {
                return 0;  // 짝이 맞지 않으면 잘못된 중첩
            }
        }
    }
    
    // 모든 문자를 처리한 후 스택이 비어있으면 올바른 중첩, 비어있지 않으면 잘못된 중첩
    return top == -1 ? 1 : 0;
}

int main() {


    char* myStr1 = "({()[]}){}";
    char* myStr2 = "d";
    if (solution(myStr1)) {
        printf("GOOOOD.\n");
    } else {
        printf("BAD.\n");
    }
    
    if (solution(myStr2)) {
        printf("GOOOOD.\n");
    } else {
        printf("BAD.\n");
    }

    return 0;
}

