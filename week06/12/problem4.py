class Solution:
    def reverseBits(self, n: int) -> int:
        binary_str = format(n, '032b')[::-1]
        ans= int(binary_str,2)
        
        return ans