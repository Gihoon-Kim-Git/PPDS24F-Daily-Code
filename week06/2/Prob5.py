class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic = {"b":0, "a":0, "l":0, "o":0, "n":0}
        for char in text:
            if char in dic:
                dic[char] += 1
        
        return min(dic["b"], dic["a"], dic["l"] // 2, dic["o"] // 2, dic["n"])