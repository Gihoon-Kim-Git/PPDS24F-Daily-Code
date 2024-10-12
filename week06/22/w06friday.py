class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        b_count = a_count = l_count = o_count = n_count = 0
        
        for char in text:
            if char == 'b':
                b_count += 1
            elif char == 'a':
                a_count += 1
            elif char == 'l':
                l_count += 1
            elif char == 'o':
                o_count += 1
            elif char == 'n':
                n_count += 1
        
        l_count //= 2
        o_count //= 2
        
        return min(b_count, a_count, l_count, o_count, n_count)