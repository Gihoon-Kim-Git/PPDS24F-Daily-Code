"""A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

class Solution { public int solution(String S); }

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'."""

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S:str) -> int:
    # Implement your solution here
    
    # Empty case
    if not S : return 1

    from collections import deque
    lst = deque()
    
    for ch in S :
        if ch == ")" :
            if not lst or lst[-1] != "(" :
                return 0
            else :
                lst.pop()
        elif ch == "}" :
            if not lst or lst[-1] != "{" :
                return 0
            else :
                lst.pop()
        elif ch == "]" :
            if not lst or lst[-1] != "[" :
                return 0
            else :
                lst.pop()
        else :
            lst.append(ch)
    
    if lst : return 0
    else : return 1

# Time : O(N)
