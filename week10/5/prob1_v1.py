# Time Limit Exceeded

class Solution:
    def getMoneyAmount(self, n: int) -> int:

        self.memo = dict()

        money = n * (n+1)
        for pivot in range(1, n+1):
            curr = self.helper(pivot, 1, n)
            if curr < money:
                money = curr
        return money
        
    def helper(self, pivot: int, start: int, end: int) -> int:
        assert start <= pivot <= end

        if start == pivot == end:
            return 0
        
        if (pivot, start, end) in self.memo:
            return self.memo[(pivot, start, end)]

        if start + 1 < pivot:
            leftmin = end * (end+1)
            for i in range(start, pivot):
                curr = self.helper(i, start, pivot-1)
                if curr < leftmin:
                    leftmin = curr
        else:
            leftmin = 0
        
        if pivot + 1 < end:
            rightmin = end * (end+1)
            for i in range(pivot+1, end+1):
                curr = self.helper(i, pivot+1, end)
                if curr < rightmin:
                    rightmin = curr
        else:
            rightmin = 0
                
        # print(f"helper called (p:{pivot:2}, s:{start:2}, e:{end:2}) - left({leftmin:3}), right({rightmin:3}), return({pivot + max(leftmin, rightmin):3})")

        money = pivot + max(leftmin, rightmin)
        self.memo[(pivot, start, end)] = money
        return money
