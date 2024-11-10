"""문제
Reverse bits of a given 32 bits unsigned integer.

input, output은 int 타입의 n.
n의 binary를 reverse한 후, 그 binary가 만드는 int n을 반환.
"""

"""나의 풀이
    1. n의 binary를 만든다. 2로 나누면서 나머지를 1의자리부터 채우면 됨.
        1을 할 때 32칸짜리 list로 구한다. 뒤칸에서부터 채우기에는 str보다 list가 쉽기 때문.
    2. n의 binary로 이루어진 32칸짜리 list의 요소를 반대로 가져오는, binary_reverse list를 만든다. (필수는 아님. 1에서 만든 list의 index 접근 순서 조정으로도 대체 가능)
    3. output이 될 n2에다가 
        2에서 만든 list의 각 i번째 요소에 2**(31-i)을 더해주면 됨.
"""

def reverseBits(n):
    n_binary = ['0']*32
    i = 31
    while n >= 1:
        b = n%2
        n = n//2
        n_binary[i] = str(b)
        i -= 1
    # print(n_binary)
    # s = "".join(n_binary)
    # print(s)

    # n_reverse_binary = ['0']*32
    # for i in range(32) :
    #     n_reverse_binary[i] = n_binary[31-i]
    
    n_reverse = 0
    for i in range(32):
        n_reverse += int(n_binary[31-i]) * 2**(31-i)
    #   n_reverse += int(n_reverse_binary[i]) * 2**(31-i)

    return n_reverse
    
if __name__ == "__main__":
    print(reverseBits(43261596)) #964176192 
    print(reverseBits(4294967293)) #3221225471 
    

# 다른 솔루션
    def reverseBits(self, n: int) -> int:
        res = 0
        for _ in range(32):
            res = (res<<1) + (n&1)  #res에 n의 비트를 역순으로 쌓는 연산
                    # (res<<1) : res를 왼쪽으로 한 비트 이동시켜서, 새로운 비트를 추가할 공간 만듦 
                    # (n&1) : n의 가장 낮은 비트(최하위 비트)를 추출 (n의 마지막 비트가 1인지 0인지를 확인해서 그 값 반환)
                    # + : 추출된 비트를 res의 가장 오른쪽에 추가.
            n>>=1 # n을 오른쪽으로 한 비트 이동: n의 다음비트가 최하위 비트 위치로 이동되고, 그게 다음 반복에서 처리된다.
        return res