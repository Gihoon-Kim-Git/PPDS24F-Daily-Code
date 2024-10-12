#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int topidx;
    char *arr;
} stack;

char pop(stack *s)
{
    if (IsEmpty(s))
    {
        // 에러 발생시켜야?
        printf("Stack is Empty");
    }
    return s->arr[s->topidx--];
}

int IsEmpty(stack *s)
{
    return s->topidx == -1;
}
void push(stack *s, char c)
{
    s->topidx++;
    s->arr[s->topidx] = c;
}

int Is_matching(char open, char close)
{
    if ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
    {
        return 1;
    }
    return 0;
}

int solution(char *S)
{
    int len = strlen(S);
    stack *ps; // stack선언만 함, 초기화 해야함!

    ps = (stack *)malloc(sizeof(stack));
    ps->arr = (char *)malloc(sizeof(char) * (len + 1)); // null character
    ps->topidx = -1;

    for (int i = 0; i < len; i++)
    {
        if (S[i] == '(' || S[i] == '{' || S[i] == '[')
        {
            push(ps, S[i]);
        }
        else if (S[i] == ')' || S[i] == '}' || S[i] == ']')
        {
            char c = pop(ps);
            if (!Is_matching(c, S[i]))
            {
                free(ps->arr);
                free(ps);
                return 0;
            }
        }
    }

    int result = IsEmpty(ps) ? 1 : 0;
    free(ps->arr);
    free(ps);
    return result;
}