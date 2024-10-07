int solution(char *S) {
    char stack[200000];
    int top=-1;

    for (int i=0; i < strlen(S); ++i) {
        if (S[i] == '(' || S[i] == '{' || S[i] == '[]') {
            stack[++top] = S[i];
        } else {
            if (top == -1) {
                return 0;
            }
            if ((S[i] == ')' && stack[top] == '(') ||
                (S[i] == '}' && stack[top] == '{') ||
                (S[i] == ']' && stack[top] == '[')
            ) {
                top--;
            } else {
                return 0;
            }
        }
    }
    return top == -1 ? 1 : 0;
}