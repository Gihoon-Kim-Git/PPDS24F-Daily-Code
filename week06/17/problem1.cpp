// # week 06

// ## Monday. [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)

// A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

// S is empty;
// S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
// S has the form "VW" where V and W are properly nested strings.
// For example, the string "{[()()]}" is properly nested but "([)()]" is not.

// Write a function:

// int solution(string &S);

// that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

// For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..200,000];
// string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.



#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;


int solution(string &S){

    // stack ...

    // char 하나씩 가져와서, 
    // {, [, ( 중에 하나면 stack에 넣음
    // }, ], ) 중에 하나면 stack에서 하나 빼서 동일한지 확인 -> stack에 아무것도 없거나, 동일하지 않으면 return 0
    // S의 끝까지 갔는데, stack 원소가 0개면 return 1, 그 이상이면 0

    map<char, char> parenthesis_set;
    parenthesis_set['}'] = '{';
    parenthesis_set[']'] = '[';
    parenthesis_set[')'] = '(';

    stack<char> char_stack;
    int str_length = S.length();

    for (int i=0; i<str_length; i++){
        if (S[i] == '{' || S[i] == '(' || S[i] == '['){
            char_stack.push(S[i]);
        } else{
            if (char_stack.empty() || char_stack.top() != parenthesis_set[S[i]]){
                return 0;
            }
            char_stack.pop();
        }
    }
    
    if (char_stack.empty()){
        return 1;
    }

    return 0;
}

int main(){

    string S = "{[()()]}";
    cout << solution(S) << endl;

    return 0;
}