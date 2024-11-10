#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Solution1(char* S) {
    int size = strlen(S);
    char* copy = (char*)malloc(size*sizeof(char)); // stack 역할
    int copy_pointer = 0;

    if (S[0] == '}' || S[0]==')' || S[0]==']') {return 0;}

    for (int i=0; i<size; ++i) {
        if (S[i] == '{' || S[i]=='(' || S[i]=='[') {
            copy[copy_pointer] = S[i];
            copy_pointer++;
        }
        else if (S[i] == '}') {
            if (copy[copy_pointer-1] == '{') {copy_pointer--;}
            else {free(copy); return 0;}
        }
        else if (S[i] == ']') {
            if (copy[copy_pointer-1] == '[') {copy_pointer--;}
            else {free(copy); return 0;}
        }
        else if (S[i] == ')') {
            if (copy[copy_pointer-1] == '(') {copy_pointer--;}
            else {free(copy); return 0;}
        }
        else {free(copy); return 0;}
    }

    int check = (copy_pointer == 0);
    free(copy);
    return check;
}

int main(void) {
    return 1;
}