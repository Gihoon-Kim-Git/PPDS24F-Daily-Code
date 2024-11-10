#include <stdio.h>
#include <string.h>

#define MAX_LEN 200000

// Stack structure
typedef struct {
    char data[MAX_LEN];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(Stack *stack, char c) {
    stack->data[++(stack->top)] = c;
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (stack->top == -1) return '\0'; // Return null character if stack is empty
    return stack->data[(stack->top)--];
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the opening and closing brackets match
int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if the string S is properly nested
int solution(char *S) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; S[i] != '\0'; i++) {
        char ch = S[i];
        
        // Push opening brackets to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // For closing brackets, check if it matches the top of the stack
        else {
            if (isEmpty(&stack)) return 0; // No matching opening bracket
            
            char top = pop(&stack);
            
            if (!isMatchingPair(top, ch)) {
                return 0; // Mismatched pair
            }
        }
    }
    
    // In the end, the stack should be empty if all brackets matched properly
    return isEmpty(&stack) ? 1 : 0;
}

int main() {
    char S1[] = "{[()()]}";
    char S2[] = "([)()]";
    
    printf("%d\n", solution(S1)); // Output: 1
    printf("%d\n", solution(S2)); // Output: 0
    
    return 0;
}
