#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(char *S){
    char stack[1000];
    int top = -1;
    int cur = 0;
    while(S[cur]){
        if(S[cur] == '(' || S[cur] == '{' || S[cur] == '['){
            stack[++top] = S[cur];
        }
        else if(S[cur] == ')' || S[cur] == '}' || S[cur] == ']'){
            if(top == -1){
                return 0;
            }
            char last_open = stack[top--];
            if((S[cur] == ')' && last_open != '(') || (S[cur] == '}' && last_open != '{') || (S[cur] == ']' && last_open != '[')){
                return 0;
            }
        }
        cur++; 
    }
    return top == -1 ? 1 : 0;
}

int main() {
    char *S = "{[()()]}()";
    printf("%d\n", solution(S));  // 출력: 1 (짝이 맞음)
    
    char *S2 = "{[(])}";
    printf("%d\n", solution(S2));  // 출력: 0 (짝이 맞지 않음)
    
    return 0;
}