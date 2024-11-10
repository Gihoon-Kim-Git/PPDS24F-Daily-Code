class Solution:
    def getMoneyAmount(self, n: int) -> int:
        if n==1:
            return 0

        self.memo = dict()

        if n % 2 == 0:
            qlist = [1 + 2*i for i in range(n//2)]
        else:
            qlist = [2 + 2*i for i in range(n//2)]

        money = n * (n+1)
        for pivot in range(len(qlist)):
            curr = self.helper(qlist, pivot, 0, len(qlist)-1)
            if curr < money:
                money = curr
        return money
        
    def helper(self, qlist: list[int], pivot: int, start: int, end: int) -> int:
        if (pivot, start, end) in self.memo:
            return self.memo[(pivot, start, end)]

        if start == pivot:
            leftmin = 0
        else:
            leftmin = qlist[pivot] * (qlist[pivot]+1)
            for i in range(start, pivot):
                curr = self.helper(qlist, i, start, pivot-1)
                if curr < leftmin:
                    leftmin = curr

        if pivot == end:
            rightmin = 0
        else:
            rightmin = qlist[end] * (qlist[end]+1)
            for i in range(pivot+1, end+1):
                curr = self.helper(qlist, i, pivot+1, end)
                if curr < rightmin:
                    rightmin = curr

        # print(f"helper called (p:{qlist[pivot]:2}, s:{qlist[start]:2}, e:{qlist[end]:2}) - left({leftmin:3}), right({rightmin:3}), return({qlist[pivot] + max(leftmin, rightmin):3})")
        money = qlist[pivot] + max(leftmin, rightmin)
        self.memo[(pivot, start, end)] = money

        return money
