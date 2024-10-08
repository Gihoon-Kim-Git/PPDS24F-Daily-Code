class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ans = 0
        dic = {}
        for x in text :
            if x not in dic:
                dic[x] = 1
            else : dic[x]+=1
        num_b = dic['b'] if 'b' in dic else 0
        num_a = dic['a'] if 'a' in dic else 0
        num_l = dic['l'] if 'l' in dic else 0
        num_o = dic['o'] if 'o' in dic else 0
        num_n = dic['n'] if 'n' in dic else 0

        return min(num_b,num_a,num_l//2,num_o//2,num_n)