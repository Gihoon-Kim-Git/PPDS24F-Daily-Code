"""문제 : Brackets
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
    S is empty;
    S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
    S has the form "VW" where V and W are properly nested strings.
    For example, the string "{[()()]}" is properly nested but "([)()]" is not.
Write a function:
    def solution(S)
that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
"""

"""문제풀이
    1. stack 방식으로 풀면 된다. 
        가장 최근에 열린 bracket이 닫혀야 그 다음 닫기가 가능하다.
        bracket이 닫히려면, 그에 상응한 bracket이 열린상태여야 한다.
    2. open : (,  [, {
        close : ), ], }
    3. S를 순회하면서 새로운 리스트에 넣는다. 최종적으로 list에 아무것도 남아있지 않으면 1, 남아있으면 0이다.
        - { 또는 [ 또는 ( 이면 맨 뒤에 append.
        - }, ], )이 들어왔을 때는, list의 맨 뒤 요소가 상응하면 bracket이면 해당 bracket을 pop, 상응하지 않으면 그냥 넣기.
"""

def solution(S):
    check_l = []
    for s in S :
        if len(check_l) == 0 and s in ")]}":
            return 0 # 바로 wrong
        if s in "([{" :
            check_l.append(s)
        if s == ')' :
            if check_l[-1] == '(' :
                check_l.pop()
            else :
                check_l.append(s)
        if s == ']' :
            if check_l[-1] == '[' :
                check_l.pop()
            else :
                check_l.append(s)
        if s == '}' :
            if check_l[-1] == '{' :
                check_l.pop()
            else :
                check_l.append(s)
    
    return 1 if  len(check_l) == 0 else 0

if __name__ == "__main__":
    print(solution("{[()()]}")) #1
    print(solution("([)()]"))  #0