class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.lst = []

    def seat(self) -> int:
        if self.lst == []:
            self.lst.append(0)
            return 0
        else:
            index = 0 
            diff = self.lst[0]
            for i in range(1,len(self.lst)+1):
                if i == len(self.lst):
                    tmp = self.n - 1 - self.lst[i-1]
                else:
                    tmp = (self.lst[i] - self.lst[i-1])//2
                if  tmp > diff:
                    diff  = tmp
                    index = i
            #print(self.lst,diff,index)
            if index ==0: 
                self.lst.insert(0,0)
                return 0
            elif index == len(self.lst):
                self.lst.append(self.n-1)
                return self.n-1
            else:
                self.lst.insert(index,self.lst[index-1]+diff)
                return diff+self.lst[index-1]
    def leave(self, p: int) -> None:
        self.lst.remove(p)
        


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)