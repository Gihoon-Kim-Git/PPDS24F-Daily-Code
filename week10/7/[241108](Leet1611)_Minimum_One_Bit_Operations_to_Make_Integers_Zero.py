"""Given an integer n, you must transform it into 0 using the following operations any number of times:
    Change the rightmost (0th) bit in the binary representation of n.
    Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0."""

#참고 : https://youtu.be/yRI18_MaG7k?feature=shared


#----[규칙기반 방법]--------------------
class Solution(object):
    def minimumOneBitOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        
        k = 0
        while (1 << k) <= n:
            k += 1
        k -= 1
        
        return 2**(k+1) - 1 - self.minimumOneBitOperations((1<<k) ^ n)
    ㄴ
    
    # 1 << k : 1을 왼쪽으로 k비트 이동시킴으로써 2^k
    # ^ (XOR 연산) : 두 비트가 다를 때 1 반환, 같을 때는 0 반환