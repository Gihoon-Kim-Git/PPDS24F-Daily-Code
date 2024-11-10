#%%
#거꾸로 생각해서 해당 비트를 만들어보기

# 00000 -> 00001 -> 00011 -> 00010 -> 00110 -> 00111 -> 00101 -> 00100 -> 01100 -> 01101 -> 01111
#  -> 01110 -> 01010 -> 01011 -> 01001 -> 01000 -> 11000 -> 11001 -> 11011 -> 11010 -> 11110 -> 11111
# -> 11101 -> 11100 -> 10100 -> 10101 -> 10111 -> 10110 -> 10010 -> 10011 -> 10001 -> 10000 -> 100000


# 0 -> 1 -> 3 -> 2 -> 6 -> 7 -> 5 -> 4 -> 12 -> 13 -> 15 -> 14 -> 10 -> 11 -> 9 -> 8 -> 24 -> 25 -> 27 -> 26 -> 30 -> 31
# -> 29 -> 28 -> 20 -> 21 -> 23 -> 22 -> 18 -> 19 -> 17 -> 16

# 보면 2에서 0갈땐 3번, 4에선 7번, 8에선 15번, 16에선 31번일거임
# 0에서 시작하면 +1
# 2에서 시작하면 +1   +2 -1
# 4에서 시작하면 +1    +2 -1    +4 +1 -2 -1    
# 8에서 시작하면 +1    +2 -1    +4 +1 -2 -1    +8 +1 +2 -1 -4 +1 -2 -1 

# 여기서 규칙을 찾을 수 있다
# 추측해보면 16에서 시작하면 +1   +2 -1    +4 +1 -2 -1    +8 +1 +2 -1 -4 +1 -2 -1   +16 +1 +2 -1 +4 +1 -2 -1 -8 +1 +2 -1 -4 +1 -2 -1


# leetcode accept는 안됐지만, 이 로직에서는 이 이상 최적화가 어렵다...
# 비트 shift하는 리트코드 솔루션 봐도 이해 어렵다. 담에 시간 있으면 다시 보기

# 세 번째 시도
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        
        pow = 1
        ops = [1]
        while 2*pow <= n:
            ops = [ops[0] * 2] + [-x for x in ops[::-1]] + ops[1:]
            pow *= 2
            
        acc, count = pow // 2, pow - 1

        # 연산 리스트를 순회하여 결과를 찾기
        for op in ops:
            acc += op
            count += 1
            if acc == n:
                return count

        print("error")
        return -1
    
    

#%%
# 메모리 터짐
# 두 번째 시도
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        pow = 1
        prev = [1]
        while 2*pow <= n:
            # 다음 recursion에서 실행할 ops 생성
            ops = [pow * 2]

            # 이전에 있던 op들을 음수로 한 뒤 거꾸로 뒤집기
            ops.extend([x*-1 for x in prev[::-1]])

            prev = prev + ops
            
            pow *= 2
            
        acc = pow / 2
        count = pow - 1

        for op in ops:
            acc += op
            count += 1
            if acc == n:
                return count

        if acc > n:
            return print("error")


#%%
# 메모리 터짐
# 첫 시도
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        ops = [1]
        acc = 0
        count = 0
        bef = [1]
        return help(n, ops, bef, acc, count)
        

def help(n, ops, bef, acc, count):
    #이 함수의 역할은 sum에 operation을 더해서 n이 되는지 체크
    #만약 op가 없으면 op 채워서 Recursion

    for op in ops:
        acc += op
        count += 1
        if acc == n:
            return count
    print(acc)

    if acc > n:
        return print("error")
    
    # 다음 recursion에서 실행할 ops 생성
    new = [acc * 2]

    # 이전에 있던 op들을 음수로 한 뒤 거꾸로 뒤집기
    new.extend([x*-1 for x in bef[::-1]])

    return help(n, new, bef + new, acc, count)

#%%
s = Solution()
s.minimumOneBitOperations(39769175)

# %%
