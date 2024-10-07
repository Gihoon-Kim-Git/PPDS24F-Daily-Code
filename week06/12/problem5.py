from collections import Counter as c

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ans= c(text)
        balloon= {'b':1,'a':1,'l':2,'o':2,'n':1}
        cnt=0
        while True:
            for key,value in balloon.items():
                if (key not in ans) or( ans[key]-value <0):
                    return cnt
                ans[key]-=value
            cnt+=1
        
        return cnt