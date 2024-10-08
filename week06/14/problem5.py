## Friday. [Maximum number of balloons](https://leetcode.com/problems/maximum-number-of-balloons/description/)

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        text = list(text)
        cnt = 0
        while(True):
            for c in "balloon":
                if c in text:
                    text.pop(text.index(c))
                else:
                    return cnt
            cnt += 1