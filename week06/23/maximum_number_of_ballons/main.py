# input: text = "nlaebolko"
# output: 1


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # init HashMap (mp)
        text = text.lower()
        mp: dict = {}
        mp["b"] = 0
        mp["a"] = 0
        mp["l"] = 0
        mp["o"] = 0
        mp["n"] = 0
        
        # declare HashMap
        for txt in text:
            if txt in mp:
                mp[txt] += 1
        
        # return min -> bottleneck
        return min(mp["b"], mp["a"], mp["l"]//2, mp["o"]//2, mp["n"])



# Driver Code
if __name__=="__main__":
    text = "nlaebolko"
    sol = Solution()
    print(sol.maxNumberOfBalloons(text))
