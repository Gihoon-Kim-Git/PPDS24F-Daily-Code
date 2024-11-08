"""문제
There is an exam room with n seats in a single row labeled from 0 to n - 1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.

Design a class that simulates the mentioned exam room.

Implement the ExamRoom class:
    ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
    int seat() Returns the label of the seat at which the next student will set.
    void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.
"""
"""접근1 : 정렬된 리스트 활용해서 최적의 위치를 실시간으로 계산
    self.room = []  #이미 차지된 좌석들의 index를 오름차순으로 저장하는 list(set도 가능. set으로 하면 a)좌석 중복 방지 및 b)좌석 해제가 더 빠름.)
    좌석배정 원리 : 아래 세 경우 중 최대값 가지는 값 찾기
        1) 첫번째 학생(self.room[0])과 첫번재 좌석(0) 간 거리
        2) 연속된 좌석(self.room[i], self.room[i+1]) 사이의 중간값 계산 후,
            self.room[i] + 중간값
        3) 마지막 학생(self.room[-1])과 마지막 좌석(n-1) 간의 거리. 
"""
"""새롭게 알게 된 사실
    ※ import bisect 모듈의 bisect.insort(list, num)을 하면 num이 알아서 list에서 들어가야할 자리를 찾아서 들어간다."""

"""접근2 : 항상 가장 큰 간격을 우선순위에 두자.
    - segment(두 좌석 사이의 빈 공간)를 관리.
        -- 좌석배정 : 가장 공간이 큰 segment에서 중간위치 찾으면 앉을 자리.
        -- 좌석해제 : 해당 좌석을 포함하는 segment or 새로 segment 만들기.
    - 이 segment의 우선순위 관리를 위해 priority queue 사용. 
    - segment는 dictionary로 규정. (각 segment의 시작, 끝을 key로 가짐)
        ex. {0: [0-2], 2: [0-2], 4: [4-5], 5: [4-5], 7: [7-7], 9: [9-9]}
"""


###----------[접근1]-----------------------------------------------------
import bisect

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.students = []

    def seat(self) -> int:
        if not self.students:
            student = 0
        else:
            max_dist = self.students[0]
            student = 0
            for i in range(1, len(self.students)):
                prev = self.students[i - 1]
                curr = self.students[i]
                dist = (curr - prev) // 2
                if dist > max_dist:
                    max_dist = dist
                    student = prev + dist
            
            # Check the last position
            if self.n - 1 - self.students[-1] > max_dist:
                student = self.n - 1
        
        bisect.insort(self.students, student) #insort는 오름차순으로 해당되는 자리에 들어갈 수 있도록 하는 내장함수임.
        return student

    def leave(self, p: int) -> None:
        self.students.remove(p)

# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)


###--------[접근1-2]------------------
class ExamRoom:

    def __init__(self, n: int):
        # n은 시험장 좌석의 수를 나타냅니다. 좌석 번호는 0에서 n-1까지입니다.
        self.n = n
        # lst는 현재 학생이 앉아 있는 좌석 번호를 저장하는 리스트입니다.
        self.lst = []

    def seat(self) -> int:
        # 첫 번째로 학생이 앉을 경우: 좌석이 비어있으면 항상 0번 좌석에 앉습니다.
        if self.lst == []:
            self.lst.append(0)
            return 0
        else:
            # index는 새 학생이 앉을 위치를 저장합니다.
            index = 0
            # diff는 현재 가장 넓은 간격을 저장합니다. 초기값은 가장 왼쪽 좌석과 첫 번째 학생 사이의 간격으로 설정됩니다.
            diff = self.lst[0]
            
            # 좌석 간의 최대 간격을 찾아 학생이 앉을 최적의 위치를 결정합니다.
            for i in range(1, len(self.lst) + 1):
                if i == len(self.lst):
                    # 마지막 학생과 마지막 좌석(n-1) 사이의 간격을 계산합니다.
                    tmp = self.n - 1 - self.lst[i - 1]
                else:
                    # 중간 좌석의 경우, 현재와 다음 좌석 사이의 중앙에 앉을 수 있는 간격을 계산합니다.
                    tmp = (self.lst[i] - self.lst[i - 1]) // 2
                
                # 가장 넓은 간격을 찾고, 새 학생의 위치를 index에 저장합니다. (최적의 위치를 찾음)
                if tmp > diff:
                    diff = tmp
                    index = i
            
            # 최적 위치에 따라 학생을 배치하고, 해당 좌석 번호를 반환합니다.
            if index == 0:
                # 가장 왼쪽에 앉을 경우, 0번 좌석에 앉습니다.
                self.lst.insert(0, 0)
                return 0
            elif index == len(self.lst):
                # 가장 오른쪽에 앉을 경우, n-1번 좌석에 앉습니다.
                self.lst.append(self.n - 1)
                return self.n - 1
            else:
                # 중간 좌석에 앉는 경우, 두 학생 사이의 중앙에 앉습니다.
                self.lst.insert(index, self.lst[index - 1] + diff)
                return diff + self.lst[index - 1]

    def leave(self, p: int) -> None:
        # p 위치에 앉은 학생이 떠나면 그 좌석 번호를 lst에서 제거합니다.
        self.lst.remove(p)

###---------[접근2-1]---------------------------------------
import heapq
class ExamRoom:

    def __init__(self, n: int):
        self.N = n
        self.pq = []
        self.dict = {}
        self.addSegment(0, self.N - 1)

    def seat(self) -> int:
        start, end, distance = heapq.heappop(self.pq)
        self.dict.pop(start, None) #Remove old segment from dictionary
        self.dict.pop(end, None)   

        if start == end: 
            position = start
        
        elif start == 0:
            position = start
            right = self.addSegment(start + 1, end)
            
        elif end == self.N - 1:
            position = end
            left = self.addSegment(start, end - 1)
            
        elif end - start == 1: #ONLY ONE PLACE TO PUT 
            position = start
            left = self.addSegment(start + 1, end)

        else:
            position = start + (end - start) // 2
            right = self.addSegment(start, position - 1)
            left = self.addSegment(position + 1, end)

        return position
        
    def leave(self, p: int) -> None:
        left = self.dict.get(p - 1, None)
        right = self.dict.get(p + 1, None)
    
        new_start = new_end = p
        
        if left:
            self.removeSegment(left)
            new_start = left.start

        if right:
            self.removeSegment(right)
            new_end = right.end
            
        self.addSegment(new_start, new_end)

    def addSegment(self, start, end):
            segment = Segment(start, end, self.N)
            self.dict[segment.start] = segment
            self.dict[segment.end] = segment
            heapq.heappush(self.pq, segment)
            
    def removeSegment(self, segment):
            self.dict.pop(segment.start, None)
            self.dict.pop(segment.end, None)
            self.pq.remove(segment)
            
class Segment():
    def __init__(self, start, end, N):
        self.start = start
        self.end = end
        self.distance = self.calculateDistance(start, end, N)

    def __lt__(self, other_segment):
        return self.distance > other_segment.distance if self.distance != other_segment.distance else self.start < other_segment.start

    def calculateDistance(self, start, end, N):
        if start == 0:
            return end

        if end == N - 1:
            return end - start

        else:
            return (end - start) // 2  
        
    def __iter__(self):
        return iter((self.start, self.end, self.distance))
    

###---------[접근 2-2] : segment를 관리하는 방법이 다름.---------------------------------------
from heapq import heappush, heappop

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.pq = [(-n, -1, n)]
        self.nei = {-1: [None, n], n: [-1, None]} # dummy head & tail 

    def seat(self) -> int:
        while self.nei.get(self.pq[0][1], [None]*2)[1] != self.pq[0][2] or self.pq[0][1] != self.nei.get(self.pq[0][2], [None]*2)[0]: heappop(self.pq)
        _, lo, hi = heappop(self.pq)
        if lo == -1: 
            x = 0 
            if hi == self.n: heappush(self.pq, (1-hi, x, hi))
            else: heappush(self.pq, ((x-hi+1)//2, x, hi))
        elif hi == self.n: 
            x = self.n-1
            heappush(self.pq, ((lo-x+1)//2, lo, x))
        else: 
            x = (lo + hi)//2
            heappush(self.pq, ((lo-x+1)//2, lo, x))
            heappush(self.pq, ((x-hi+1)//2, x, hi))
        self.nei[x] = [lo, hi]
        self.nei[lo][1] = self.nei[hi][0] = x
        return x

    def leave(self, p: int) -> None:
        if self.nei[p][0] == -1: 
            heappush(self.pq, (-self.nei[p][1], -1, self.nei[p][1]))
        elif self.nei[p][1] == self.n: 
            heappush(self.pq, (-self.n+1+self.nei[p][0], self.nei[p][0], self.n))
        else: 
            heappush(self.pq, ((self.nei[p][0] - self.nei[p][1] + 1)//2, self.nei[p][0], self.nei[p][1]))
        self.nei[self.nei[p][0]][1] = self.nei[p][1]
        self.nei[self.nei[p][1]][0] = self.nei[p][0]
        self.nei.pop(p)
        
        
