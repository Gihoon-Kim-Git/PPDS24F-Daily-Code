# sub problem

class Solution(object):    
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n ==1:
            return 0
        elif n == 2:
            return 1
        else:
            return self.getMoneyAmount(n-1) + self.getMoneyAmount(n-2)