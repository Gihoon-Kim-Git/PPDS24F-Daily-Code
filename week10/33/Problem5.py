"""
GPT 풀이
"""

class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # Helper function for recursive transformation
        def helper(x):
            if x == 0:
                return 0
            # Find the highest bit in `x`
            b = 1
            while (1 << b) <= x:
                b += 1
            # Calculate minimum operations recursively
            return (1 << b) - 1 - helper(x ^ (1 << (b - 1)))

        return helper(n)
