class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        n = bin(n)[2:]
        if '1' not in n:
            return 0
        n = tuple(list(n))

        @lru_cache(None)
        def zero(n): # min number of operations to transform n to all 0 bits
            n = list(n)
            if all(bit == '0' for bit in n):
                return 0
            if n[0] == '0':
                if len(n) == 1:
                    return 0
                else:
                    return zero(tuple(n[1:])) # if first bit is 0, we only need to transform the rest
            else:
                if len(n) == 1:
                    return 1
                else:
				    # if first bit is 1, we need to:
					# 1. transform first bit to 0, what means, we need:
					#        a. transform the rest of the bits to 10000... format
					#        b. flip the first bit
					# 2. transform the rest bits to zero, after step 1 we end up with 010000...
                    ops = one(tuple(n[1:])) + 1
                    nei = ['0' for i in range(len(n) - 1)]
                    nei[0] = '1'
                    return ops + zero(tuple(nei))

        @lru_cache(None)
        def one(n): # min number of operations to transform n to first bit 1 and all other bits 0
            n = list(n)
            if n[0] == '1' and all(bit == '0' for bit in n[1:]):
                return 0
            if n[0] == '1':
                if len(n) == 1:
                    return 0
                else:
                    return zero(tuple(n[1:])) # if first bit is 1, we only need to change the rest to 0
            else:
                if len(n) == 1:
                    return 1
                else:
					# Similar to the zero() function, if first bit is 0, we need to:
					# 1. transform first bit to 1, what means, we need:
					#        a. transform the rest of the bits to 10000... format
					#        b. flip the first bit
					# 2. transform the rest bits to zero, after step 1 we end up with 110000...
                    ops = one(tuple(n[1:])) + 1
                    nei = ['0' for i in range(len(n) - 1)]
                    nei[0] = '1'
                    return ops + zero(tuple(nei))
        return zero(n)