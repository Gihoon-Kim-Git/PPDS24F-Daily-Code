class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # Initialize counts for the necessary characters
        b_count = 0
        a_count = 0
        l_count = 0
        o_count = 0
        n_count = 0
        
        # Count the occurrences of 'b', 'a', 'l', 'o', and 'n'
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

        # Calculate the maximum number of "balloon" that can be formed
        # We need 2 'l's and 2 'o's, so we divide those counts by 2
        return min(b_count, a_count, l_count // 2, o_count // 2, n_count)