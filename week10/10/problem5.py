class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        
        def recur(n):
            if n == 0:
                return 0
            
            # Find the most significant bit
            highest_bit = 0
            while (1 << (highest_bit + 1)) <= n:
                highest_bit += 1
            
            # Calculate next value by flipping the msb 
            next_value = n ^ (1 << highest_bit)
            
            return (1 << (highest_bit + 1)) - 1 - recur(next_value)
        
        # Start the recursive 
        return recur(n)