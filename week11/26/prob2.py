def minCostClimbingStairs(self, cost: List[int]) -> int:
        # identify what is changing from subproblems to subproblems: 
        # n - step #n    dp(n) - min cost to get to step #n 
        def dp(n):  
            # write down base cases
            if n < 2: 
                return cost[n] 
            # write recursive function based on what you can change (climb one or two steps)
            return cost[n] + min(dp(n-1), dp(n-2))
		
		# since we want to know the min cost to get to the final step, we use the code below 
        length = len(cost) 
        return min(dp(length-1), dp(length-2))