"""
<Minimum One Bit Operations to Make Integers Zero>

Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

"""

def minimum_operations(n):
    operations = 0
    
    while n > 0:
        if n & 1 == 1:
            n -= 1
        else:
            i = 1
            while (n & (1 << i)) == 0:
                i += 1
            n ^= (1 << i)
        operations += 1
        
    return operations


print(minimum_operations(3))  # 2
print(minimum_operations(6))  # 4
