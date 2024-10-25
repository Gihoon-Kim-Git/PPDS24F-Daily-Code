"""문제
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:
    MyCalendarTwo() Initializes the calendar object.
    boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
"""
"""Constraints
    0 <= start < end <= 109
    At most 1000 calls will be made to book.
"""

"""Hint
    Store two sorted lists of intervals: one list will be all times that are at least single booked, and another list will be all times that are definitely double booked. If none of the double bookings conflict, then the booking will succeed, and you should update your single and double bookings accordingly.
"""

"""문제풀이1 (최초시도)  => 실패..
    1. Triple booking을 추적하기 위한 방법으로, SB_list, DB_list를 각각 관리한다.
    2-1) DB_list가 비어있는가?   Yes ---> 일단 답은 True.
        그러나 SB_list 및 DB_list에 대한 조치를 해주어야 함.
        if SB_list == empty  --->  SB_list.append([start, end])
        else SB_list에 넣을 때 충돌이 발생하는가? Yes --> DB_list.append([start, end]), DB_list.append([나랑 충돌났던 예약시간])
                                                No --> 별도 조치 불필요.
    2-2) DB_list가 비어있는가?   No ---> 
            DB_list에 있는 요소와 [start,end]에 conflict가 발생하는가??  Yes ---> return False
            DB_list에 있는 요소와 [start,end]에 conflict가 발생하는가??  No ---> return True
                SB_list에 있는 요소와 [start, end]에 conflict가 발생하는가? Yes ---> conflict 발생하는 요소 식별 c = [start_c, start_e], DB_list.append([start, end]), DB_list.append([start_c, start_e])
                SB_list에 있는 요소와 [start, end]에 conflict가 발생하는가? No ---> SB_list.append
    3. 2-2만 있어도 될 것 같다. 일단 2-2만 구현..
    4. conflict가 발생하는지 여부는 어떻게 확인하지?
        - DB_list.sort()
        - SB_list.sort()
        - 각 list를 순회하면서 모든 요소에 대해서 a[i][1] <= start < end <= a[i+1][0] 이면 conflict가 없는 것임. 또는 end < a[0][0]
                            순회는, end <= a[i][0] 인동안만 하면 됨.
                            a[i][1] > start, a[i][0] < end인 경우가 하나라도 발생하면 conflict가 있음.
"""

"""문제풀이2 
    1. 겹치는 구간 개수를 구하는 코드 활용 (DB_list에다가 new_start, new_end 넣고 겹치는 구간 개수 보면 됨)
    2. 겹치는 구간 개수가 3개 이상이면 False, 그렇지 않으면 True 반환
    3. 이때, False일 경우에는 DB_list에서 new_start, new_end를 빼주어야 함. True일 경우에는 SB_list에 append. DB_list에는 interval이 2개인 경우까지만 들어가므로.. """


#풀이 2
class MyCalendarTwo(object):
    def __init__(self):
        self.DB_list = []
        self.SB_list = []
    
    def num_intervals(self):  #필요한 최대 회의실 개수 구하는 코드 응용.
        starts = sorted([i[0] for i in self.DB_list])
        ends = sorted([i[1] for i in self.DB_list])

        max_active_intervals = 0 
        active_intervals = 0 #겹치는 구간
        i, j = 0, 0
        n = len(self.DB_list)

        # starts, ends를 사용해서 구간의 시작과 끝을 추적
        while i < n and j < n:
            if starts[i] < ends[j]:  # 새 회의 시작 시간이 이전 회의 종료 시간보다 작다면
                active_intervals += 1  # 회의실 추가 필요
                max_active_intervals = max(max_active_intervals, active_intervals)  # 최대 겹침 갱신
                i += 1
            else:  # 현재 회의 종료 시간이 다음 회의 시작 시간보다 같거나 작다면
                active_intervals -= 1  # 회의 종료, 회의실 반환
                j += 1
        
        return max_active_intervals
    
    def book(self, start, end) :
        self.DB_list.append((start, end))
        num_intervals = self.num_intervals()
        if num_intervals >= 3 :
            self.DB_list.pop()
            return False
        else :
            self.SB_list.append((start, end))
            return True
        

myCalendar = MyCalendarTwo()
print(myCalendar.book(10,20)) #T
print(myCalendar.book(50,60)) #T
print(myCalendar.book(10,40)) #T
print(myCalendar.book(5,15)) #F
print(myCalendar.book(5,10)) #T
print(myCalendar.book(25,55)) #T


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)


#풀이 3
class MyCalendarTwo:
    def __init__(self):
        self.SB_list = []
        self.DB_list = []

    def book(self, start, end):
        # 이중 예약 확인
        for s, e in self.DB_list:
            if s < end and start < e:  # 겹치는 부분이 있으면 False 반환 : 기존 DB_list와 conflict가 생기는 경우.
                return False

        # 임시 리스트를 사용하여 이중 예약을 업데이트  (이 아래부분이 overlap을 푸는 핵심인듯.)
        temp = []
        for s, e in self.SB_list:
            if s < end and start < e:  # 겹치는 부분이 있으면
                overlap_start = max(s, start)
                overlap_end = min(e, end)
                temp.append((overlap_start, overlap_end))
        
        # 임시 리스트의 내용을 이중 예약 리스트에 추가
        for s, e in temp:
            self.DB_list.append((s, e))

        # 새 예약을 단일 예약 리스트에 추가
        self.SB_list.append((start, end))
        self.SB_list.sort()  # 리스트 정렬 유지

        return True