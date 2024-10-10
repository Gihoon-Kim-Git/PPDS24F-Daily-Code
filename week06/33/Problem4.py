# input으로 들어오는 이진수를 거꾸로 뒤집은 뒤 그에 해당하는 int 반환
# ex) n = 1001 -> return: 6(0110)

class Solution:
    def reverseBits(self, n: int) -> int:
        ans = ''
        for i in range(32):
            ans += str(n&1)
            n >>= 1
        # str -> int 변환 시 int(value, base)로 base 지정 가능
        return int(ans, 2)
    

"""GPT 풀이"""
class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            # n의 마지막 비트를 result의 왼쪽에 추가하고 n의 비트를 한 칸 오른쪽으로 이동
            result = (result << 1) | (n & 1)
            n >>= 1
        return result