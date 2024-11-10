#1. Brackets
#return 1 if S is properly nested and 0 otherwise

def paired(s):
    if s == ')':
        return '('
    
    elif s == '}':
        return '{'
    
    elif s == ']':
        return '['
    

def solution(S):
    if len(S) == 0:
        return 1
    
    result = []
    result.append(S[0])

    i = 1

    while i < len(S):
        # if (S[i] == ')' and result[-1] == '(') or (S[i] == '}' and result[-1] == '{') or (result[-1] == '[' and S[i] == ']'):
        if (S[i] == ')' or S[i] == '}' or S[i] == ']') and len(result) != 0:
            if result[-1] == paired(S[i]):
                result.pop()
                i += 1
            else:
                result.append(S[i])
                i+=1
        else:
            result.append(S[i])
            i+=1
    
    if len(result) == 0:
        return 1

    return 0




#2. NumberSolitai
def solution(A):
    # Implement your solution here
    dp = [0 for _ in range(len(A))]
    dp[0] = A[0]

    for i in range(1, len(A)):
        max_num = dp[i-1]
        for j in range(2,7):
            if i>=j and dp[i-j] > max_num:
                max_num = dp[i-j]
        
        dp[i] = max_num + A[i]
    
    return dp[len(A)-1]






#3. Sum of Left Leav
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root) -> int:
        if root == None:
            return 0

        summ = 0

        if root.left != None and root.left.left == None and root.left.right == None:
            summ += root.left.val

        return summ + self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)




#4. Reverse Bit
def reverse_bits(n):  # 입력값 n의 비트를 반대로 뒤집는 함수 선언
    ans = 0  # 결과값을 저장할 변수 ans를 0으로 초기화

    for i in range(32):  # 32비트 정수를 처리하기 위해 32번 반복
        ans = ans << 1  # ans를 왼쪽으로 한 칸씩 이동시킴 (자리를 확보)
        # 예시: x = 0b01001, x << 1 = 0b10010
        # 예시: x = 0b01001, x >> 1 = 0b00100

        ans = ans | (n & 1)  # n의 마지막 비트(가장 오른쪽 비트)를 ans에 추가
        n = n >> 1  # n을 오른쪽으로 한 칸씩 이동시켜 다음 비트를 처리할 준비
    return ans  # 뒤집힌 비트를 저장한 ans를 반환




#5. Maximum number of balloons
def maxNumberOfBalloons(self, text: str) -> int:
    dct = dict()
    for char in text:
        if char not in dct.keys():
            dct[char] = 1
        else:
            dct[char]+=1
    
    count = 0
    if ('b' in dct.keys() and 'a' in dct.keys() and 'l' in dct.keys() and 'o' in dct.keys() and 'n' in dct.keys()):
        while (dct['b'] > 0 and dct['a'] > 0 and dct['l'] > 1 and dct['o'] > 1 and dct['n'] > 0):
            dct['b'] -= 1
            dct['a'] -= 1
            dct['l'] -= 2
            dct['o'] -= 2
            dct['n'] -= 1
            count += 1

    return count
    