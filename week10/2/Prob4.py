class ExamRoom:

    def __init__(self, n: int):
        # initialize a seat list
        self.n = n
        self.seats = [0] * n


    def seat(self) -> int:
        # seat list가 empty한 경우
        if not sum(self.seats):
            self.seats[0] = 1
            return 0
        elif sum(self.seats) == 1:
            left_len = 0
            right_len = 0
            find_one = False
            for i in range(self.n):
                if self.seats[i] == 0:
                    if find_one:
                        right_len += 1
                    else:
                        left_len += 1
                else:
                    find_one = True
            if right_len > left_len:
                self.seats[self.n-1] = 1
                return self.n-1
            else:
                self.seats[0] = 1
                return 0

        else:
            # find a maximum length between two seats
            # maxlen: max length, start index
            lenchk = [0, 0]
            maxlen = [0, 0]
            for i in range(self.n):
                if self.seats[i] == 0:
                    if lenchk[0] == 0:
                        lenchk[1] = i
                    lenchk[0] += 1
                else:
                    if maxlen[0] < (lenchk[0]+1)//2:
                        maxlen[0] = (lenchk[0]+1)//2
                        maxlen[1] = lenchk[1]
                    lenchk[0] = 0
            # for문 끝나고 다시 한번 정리
            if maxlen[0] < (lenchk[0]+1)//2:
                maxlen[0] = (lenchk[0]+1)//2
                maxlen[1] = lenchk[1]
            
            if maxlen[1] == 0 and self.seats[0] == 0:
                self.seats[0] = 1
                return 0
            else:
                self.seats[maxlen[1]-1 + maxlen[0]] = 1
                return maxlen[1]-1 + maxlen[0]
   
        

    def leave(self, p: int) -> None:
        self.seats[p] = 0
        

# Your ExamRoom object will be instantiated and called as such:
"""
input = ["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat", "seat","seat","seat","seat","leave","leave","seat","seat","leave","seat","leave","seat","leave","seat","leave","seat","leave","leave","seat","seat","leave","leave","seat","seat","leave"]
inputval = [[10],[],[],[],[0],[4],[],[],[],[],[],[],[],[],[],[0],[4],[],[],[7],[],[3],[],[3],[],[9],[],[0],[8],[],[],[0],[8],[],[],[2]]


input = ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
inputval = [[10], [], [], [], [], [4], []]


input = ["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat","seat","seat"]
inputval = [[8],[],[],[],[0],[7],[],[],[],[],[],[],[]]
"""
input = ["ExamRoom","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","leave","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat"]

inputval = [[1000000],[],[],[],[],[],[],[],[],[],[],[],[624999],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]

result = []

# 테스트 환경 구현, output check 용도
for i in range(len(input)):
    #print(i, input[i], inputval[i])
    if input[i] == "ExamRoom":
        obj = ExamRoom(inputval[i][0])
        result.append(None)
    elif input[i] == "seat":
        result.append(obj.seat())
    elif input[i] == "leave":
        result.append(obj.leave(inputval[i][0]))
    #print(obj.seats)

print(result)



