#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct Stack {
    int data[SIZE];
    int top;
}Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == SIZE - 1;
}

void add(Stack *s, int n) {
    if (is_full(s)) {
        printf("Error : Stack is full!\n");
        return;
    } else {
        s->top++;
        s->data[s->top] = n;
    }
}

int get(Stack *s) {
    if (is_empty(s)) {
        return 0;
    } else {
        return s->data[s->top--];
    }
}

int solution(char *S) {
    struct Stack s;
    init_stack(&s);
    int i = 0;
    while (S[i] == '\0') {
        if (S[i] == '{') add(&s, '}');
        else if (S[i] == '[') add(&s, ']');
        else if (S[i] == '(') add(&s, ')');
        else {
            if (S[i] != get(&s)) {
                return 0;
            }
        }
        i++;
    }
    if (!is_empty(&s)) {
        return 0;
    }
    return 1;
}

int main() {
    char *s1 = "{[()()]}";
    char *s2 = "([)()]";
    
    printf("%d\n", solution(s1));
    printf("%d\n", solution(s2));

    return 0;
}