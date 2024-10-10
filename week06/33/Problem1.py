# (, ), {, }, [, ] 로 구성된 string이 input으로 들어올 때
# 괄호가 제대로 닫혀있는지 return하는 함수 작성 (return 1: properly nested, 0: not properly nested)

def Solution(S: str) -> bool:
    stack = []
    for char in S:
        if char in ["(", "{", "["]:
            stack.append(char)
        else:
            if stack:
                pop = stack.pop()
                if (pop, char) not in [("(", ")"), ("{", "}"), ("[","]")]:
                    return False
            else:
                return False
    if stack:
        return False
    return True
