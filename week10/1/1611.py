class Solution(object):
    def toBinaryString(n):
        
        return binary
    
    def minimumOneBitOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        out = 0
        if n == 0:
            return 0
        elif n==1:
            return 1
        else: # len(binary) > 2
            binary = toBinaryString(n)
            for i in range(1, len(binary)):
                # check all n-i left numbers
                if binary[i] == 1:
                    binary[i-1] = 0
                    out +=1
            return out

        