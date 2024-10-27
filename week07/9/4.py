# need to solve
def solution(K: int, M: int, A: list[int]):
    
    def division(subA: list[int]):
        pre = 0
        nex = sum(subA)
        
        small_diff = abs(nex - pre)
        cut_point = 0

        for i in range(len(subA)):
            pre += subA[i]
            nex -= subA[i]
            if abs(pre-nex) <= small_diff:
                small_diff = abs(pre-nex)
                cut_point = i+1
        
        return [subA[:cut_point], subA[cut_point:]]

            
    def select(subA, subB):
        1 if sum(subB) > sum(subA) else 0

    for _ in range(K):
        A, B = division(A)

if __name__ == '__main__':
    pass