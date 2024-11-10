import copy

class MyCalendarTwo1(object):

    def __init__(self):
        self.cal = {"1" : [[-1,-1],[float('inf'),float('inf')]], "2" : [[-1,-1],[float('inf'),float('inf')]], "3" : [[-1,-1],[float('inf'),float('inf')]]}

    def book(self, start, end):
        backup = copy.deepcopy(self.cal)
        self.bookHelp(start, end, 1)
        if len(self.cal["3"]) > 2:
            self.cal = backup
            return False
        return True
    
    def bookHelp(self, start, end, it):
        if (it == 4 or start >= end):
            return
        i = 0
        while(i < len(self.cal[str(it)])-1):
            if start >= self.cal[str(it)][i][0] and end <= self.cal[str(it)][i][1]: # 부분
                self.bookHelp(start, end, it+1)
                pass
            elif start > self.cal[str(it)][i][1] and end < self.cal[str(it)][i+1][0]: # 추가
                self.cal[str(it)].insert(i+1, [start, end])
                i += 1
            elif start <= self.cal[str(it)][i][1] and end >= self.cal[str(it)][i][0]: # 연장
                self.bookHelp(max(start, self.cal[str(it)][i][0]), min(end, self.cal[str(it)][i][1]), it+1)
                self.cal[str(it)][i][0] = min(start, self.cal[str(it)][i][0])
                while end >= self.cal[str(it)][i+1][0]: # 병합
                    self.bookHelp(self.cal[str(it)][i+1][0], min(end, self.cal[str(it)][i+1][1]), it+1)
                    self.cal[str(it)][i][1] = self.cal[str(it)][i+1][1]
                    del self.cal[str(it)][i+1]
                self.cal[str(it)][i][1] = max(end, self.cal[str(it)][i][1])
            i += 1

class MyCalendarTwo2(object):

    def __init__(self):
        # 초기 예약 상태: 각 레벨별로 저장
        self.single_bookings = []  # 1번 중복
        self.double_bookings = []  # 2번 중복

    def book(self, start, end):
        # 이중 예약과 겹치는지 확인 (세 번 이상 중복을 허용하지 않음)
        for s, e in self.double_bookings:
            if start < e and end > s:  # 겹치는 구간이 있는지 확인
                return False

        # 중복 예약을 double_bookings에 추가
        for s, e in self.single_bookings:
            if start < e and end > s:  # 겹치는 구간을 추가
                self.double_bookings.append((max(start, s), min(end, e)))

        # 새로운 예약을 single_bookings에 추가
        self.single_bookings.append((start, end))

        return True

if __name__ == "__main__":
    # seq = [[],[24,40],[43,50],[27,43],[5,21],[30,40],[14,29],[3,19],[3,14],[25,39],[6,19]]
    seq = [[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]
    # seq = [[],[47,50],[1,10],[27,36],[40,47],[20,27],[15,23],[10,18],[27,36],[17,25],[8,17],[24,33],[23,28],[21,27],[47,50],[14,21],[26,32],[16,21],[2,7],[24,33],[6,13],[44,50],[33,39],[30,36],[6,15],[21,27],[49,50],[38,45],[4,12],[46,50],[13,21]]
    # seq = [[],[21,22],[86,87],[71,72],[76,77],[50,51],[92,93],[99,100],[5,6],[71,72],[42,43],[72,73],[22,23],[51,52],[15,16],[70,71],[64,65],[57,58],[47,48],[4,5],[14,15],[2,3],[28,29],[35,36],[86,87],[72,73],[99,100],[50,51],[25,26],[8,9],[69,70],[37,38],[55,56],[0,1],[20,21],[21,22],[96,97],[88,89],[40,41],[20,21],[94,95],[99,100],[19,20],[41,42],[0,1],[47,48],[51,52],[62,63],[32,33],[83,84],[39,40],[70,71],[36,37],[16,17],[63,64],[32,33],[35,36],[57,58],[68,69],[24,25],[73,74],[94,95],[32,33],[36,37],[21,22],[47,48],[54,55],[61,62],[67,68],[89,90],[57,58],[65,66],[23,24],[85,86],[79,80],[66,67],[2,3],[83,84],[46,47],[58,59],[69,70],[15,16],[89,90],[48,49],[93,94],[28,29],[22,23],[53,54],[50,51],[19,20],[1,2],[53,54],[70,71],[44,45],[36,37],[85,86],[4,5],[10,11],[14,15],[81,82],[9,10],[88,89],[21,22],[57,58],[91,92],[35,36],[77,78],[95,96],[39,40],[92,93],[43,44],[10,11],[73,74],[84,85],[42,43],[58,59],[22,23],[73,74],[85,86],[47,48],[68,69],[43,44],[94,95],[95,96],[31,32],[18,19],[35,36],[55,56],[54,55],[53,54],[28,29],[16,17],[42,43],[23,24],[22,23],[5,6],[69,70],[25,26],[9,10],[69,70],[55,56],[0,1],[33,34],[8,9],[91,92],[97,98],[42,43],[69,70],[50,51],[86,87],[63,64],[31,32],[55,56],[17,18],[26,27],[16,17],[10,11],[66,67],[90,91],[83,84],[52,53],[77,78],[3,4],[13,14],[7,8],[82,83],[85,86],[72,73],[82,83],[28,29],[98,99],[1,2],[92,93],[83,84],[52,53],[24,25],[6,7],[20,21],[56,57],[59,60],[29,30],[51,52],[37,38],[42,43],[40,41],[35,36],[36,37],[1,2],[50,51],[67,68],[57,58],[49,50],[22,23],[41,42],[49,50],[38,39],[37,38],[9,10],[87,88],[11,12],[47,48],[44,45],[85,86],[32,33],[64,65],[63,64],[24,25],[28,29],[88,89],[59,60],[90,91],[12,13],[90,91],[60,61],[38,39],[72,73],[45,46],[5,6],[70,71],[4,5],[53,54],[57,58],[29,30],[43,44],[95,96],[75,76],[10,11],[22,23],[35,36],[62,63],[74,75],[21,22],[54,55],[84,85],[49,50],[25,26],[78,79],[85,86],[54,55],[89,90],[48,49],[43,44],[83,84],[28,29],[55,56],[87,88],[56,57],[11,12],[40,41],[69,70],[0,1],[44,45],[20,21],[57,58],[32,33],[60,61],[82,83],[45,46],[54,55],[71,72],[43,44],[65,66],[31,32],[59,60],[12,13],[16,17],[71,72],[24,25],[1,2],[70,71],[91,92],[28,29],[11,12],[27,28],[48,49],[46,47],[16,17],[17,18],[75,76],[70,71],[31,32],[14,15],[74,75],[32,33],[9,10],[47,48],[24,25],[61,62],[51,52],[30,31],[86,87],[56,57],[31,32],[11,12],[65,66],[57,58],[28,29],[96,97],[81,82],[97,98],[48,49],[44,45],[8,9],[17,18],[31,32],[72,73],[95,96],[64,65],[85,86],[3,4],[67,68],[5,6],[81,82],[69,70],[67,68],[36,37],[6,7],[33,34],[20,21],[83,84],[70,71],[94,95],[25,26],[49,50],[4,5],[25,26],[64,65],[73,74],[63,64],[5,6],[14,15],[5,6],[72,73],[54,55],[73,74],[71,72],[46,47],[31,32],[80,81],[33,34],[4,5],[61,62],[19,20],[99,100],[30,31],[74,75],[79,80],[13,14],[23,24],[57,58],[82,83],[96,97],[36,37],[17,18],[29,30],[32,33],[70,71],[29,30],[10,11],[45,46],[99,100],[23,24],[57,58],[67,68],[80,81],[50,51],[96,97],[50,51],[76,77],[74,75],[5,6],[42,43],[64,65],[65,66],[52,53],[75,76],[12,13],[30,31],[66,67],[47,48],[27,28],[99,100],[80,81],[52,53],[37,38],[65,66],[78,79],[40,41],[11,12],[91,92],[29,30],[50,51],[96,97],[43,44],[94,95],[26,27],[98,99],[3,4],[40,41],[53,54],[31,32]]
    # myCalendarTwo = MyCalendarTwo1()
    myCalendarTwo = MyCalendarTwo2()
    for i in range(len(seq)):
        if seq[i] == []:
            print('null')
        else:
            print(i, myCalendarTwo.book(seq[i][0], seq[i][1]))