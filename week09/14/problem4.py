# week 09

## Thursday. [Max Profit](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/)

class Solution:
    def maxProfit(self, prices):
        if len(prices) <= 1:
            return 0
        profit = 0
        low = prices[0]
        for i in range(1,len(prices)):
            if prices[i] < low:
                low = prices[i]
            else:
                profit = max(prices[i]-low, profit)
        return profit
