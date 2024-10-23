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

"""문제풀이
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

#%%
class MyCalendarTwo(object):

    def __init__(self):
        self.DB_list = []
        self.SB_list = []

    def is_triple_overlap(intervals):
        # 각 interval을 시작 시간과 끝 시간으로 정렬
        starts = sorted([[i][0] for i in intervals])
        ends = sorted([i[1] for i in intervals])
        
        #동시에 세 구간이 겹치기 위해서는 최소 두개의 구간이 겹쳐야 함.
        active_intervals = 0
        i, j = 0, 0
        n = len(intervals)
        
        #starts, ends를 사용해서 구간의 시작과 끝을 추적
        while i < n and j < n :
            if starts[i] <= ends[j]:
                active_intervals += 1
                #세 구간이 겹치는 경우 True 반환
                if active_intervals >= 3:
                    return True
                i += 1
            else :
                active_intervals -= 1
                j += 1
        return False

    def isDBTripleConflict(self, start, end):  
        if self.DB_list == [] : 
            return False
        self.DB_list.sort(key = lambda x : [x[1], x[0]])
        
        # conflict_count = 0 #1까지는 괜찮고, 2가되면 return True
        # for i in range(len(self.DB_list)):
        #     if self.DB_list[i][0] <= start < self.DB_list[i][1]  or self.DB_list[i][0] < end <= self.DB_list[i][1] :
        #         conflict_count += 1
        #     if conflict_count >= 2 :
        #         return True
        # if conflict_count <= 1 :
        #     return False
        
        if end <= self.DB_list[0][0] or self.DB_list[len(self.DB_list)-1][1] <= start :
            return False
        for i in range(len(self.DB_list)-1):
            if self.DB_list[i][1] <= start < end <= self.DB_list[i+1][0] :
                return False
            else :
                
                
                return  True
                # overlap1 = [-1,-1]
        # overlap2 = [-1,-1]
        # for i in range(1, len(self.DB_list)):
        #     if overlap1 == [-1, -1] :
        #         if start <= self.DB_list[i][0] < end :
        #             overlap1[0] = self.DB_list[i][0]
        #             if start <= self.DB_list[i][1] <= end:
        #                 overlap1[1] = self.DB_list[i][1]
        #             else :
        #                 overlap1[1] = end
        #     else :
        #         if overlap1[0] <= self.DB_list[i][0] < overlap1[1]:
        #             return True
        #         if overlap1[0] <= self.DB_list[i][1] <= overlap1[1] :
        #             return True
            
    def isSBConflict(self, start, end): #conflict 발생하는 요소 식별, SB_list에서 삭제 및  return 해당 요소, conflict 만드는 요소 없으면 [-1, -1] 반환
        if self.SB_list == [] : 
            return [-1,-1]
        self.SB_list.sort(key = lambda x : [x[1], x[0]]) #끝나는 시간 -> 시작시간 기준으로 정렬
        
        conflict_element = [-1, -1]
        # if end <= self.SB_list[0][0] :
        #     return [-1,-1]
        # i = 0
        # while end <= self.SB_list[i][0] :  #이부분에 지금 들어가지를 못하고 있음...
        #     print(i)
        #     print(self.SB_list[i])
        #     if start<= self.SB_list[i][0] < end :
        #         return self.SB_list[i]
        #     i += 1
        # return [-1,-1]
        for i in range(len(self.DB_list)):
            if self.SB_list[i][0] <= start < self.SB_list[i][1]  or self.SB_list[i][0] < end <= self.SB_list[i][1] : # conflict가 생기는 경우임.
                conflict_element = self.SB_list[i]
                self.SB_list[i] = [-1,-1]
        if conflict_element != [-1, -1]:
            self.SB_list.remove([-1, -1])
        return conflict_element
        
        
    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        print(self.DB_list)
        print(self.SB_list)
        if self.isDBTripleConflict(start, end) == True:
            return False
        else :
            conflict_element = self.isSBConflict(start, end)
            print(conflict_element)
            if conflict_element == [-1,-1] : #conflict가 없는 경우.
                self.SB_list.append([start, end])
            else : 
                self.DB_list.append(conflict_element)
                self.DB_list.append([start, end])
            return True
        
    

myCalendar = MyCalendarTwo()
print(myCalendar.book(10,20))
print(myCalendar.book(50,60))
print(myCalendar.book(10,40))
print(myCalendar.book(5,15))
print(myCalendar.book(5,10))
print(myCalendar.book(25,55))


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
# %%

cf. 