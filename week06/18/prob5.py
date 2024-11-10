class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        counter = {}

        # Count
        for char in text:
            if char not in counter:
                counter[char] = 1
            else:
                counter[char] += 1

        # Check b, a, n (1) l, o (2)

        count_b = counter.get('b', 0)
        count_a = counter.get('a', 0)
        count_n = counter.get('n', 0)
        count_l = counter.get('l', 0) // 2  
        count_o = counter.get('o', 0) // 2

        count = min(count_b, count_a, count_n, count_l, count_o)

        return count