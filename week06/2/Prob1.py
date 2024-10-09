# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # Implement your solution here
    bracket = {"(":")", "{":"}", "[":"]"}
    chk = []

    for char in S:
        if bracket.get(char, False):
            # 만일 여는 괄호면 if문 안으로 들어오고, 그게 아니라면 else로 넘어가게 됨
            chk.append(char)
        else:
            # 닫는 괄호라면
            if not chk or bracket[chk.pop()] != char:
                return 0
        
    if chk:
        return 0
    else:
        return 1

        
