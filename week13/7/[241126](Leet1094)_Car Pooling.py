"""There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
"""

"""Constraints:
    1 <= trips.length <= 1000
    trips[i].length == 3
    1 <= numPassengersi <= 100
    0 <= fromi < toi <= 1000
    1 <= capacity <= 105
"""

#★ python의 heapq는 항상 element의 첫번째 요소를 기준으로 최소힙을 구성한다! key=lambda식으로 기준을 임의로 정할 수 없다. 따라서,  내가 key로 삼고 싶은 것을 튜플의 맨 처음 요소로 넣어주는 변형이 필요하다.
"""수도코드
목표 : heapq에 trip을 차례로 넣고 빼면서, cur_people을 추적하되, cur_people > caacity이면 return False. 끝까지 다 돌면, return True

1. trips를 "from"(trips[i][1]) 순서대로 정렬

2. heapq 초기화 (to 순서대로 나열하도록 heapq에 넣어줄 때 변형해서 넣어주자.)
    cur_people 초기화 : heapq안에 들어있는 trip들의 passenger 수를 더하는 변수

3. trips의 요소 trip을 순회한다.
    heapq에 바로 trip을 넣는다.
    extract_trip = heapq의 top (heapq[0])
    ★(while)만약 extract_trip의 "to"가 trip의 "from"보다 빠르면 (이거를 하나만 비교하면 되는 게 아니라, 더 작은 요소들은 다 pop해줘야 함.)
        heapq.pop()
        cur_people = cur_people - extract_trip[0]
        extract_trip = q[0] #갱신

    만약 cur_people > capacity 이면 
        return False

4. 3을 끝가지 수행으면
    return True
"""
#%%
import heapq

class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        trips.sort(key = lambda x : x[1])
        
        q = []
        cur_people = 0

        for trip in trips :  # (to, start, passenger)로 변형해서 넣기. to 기준으로 heapify 하고 싶기 때문.
            heapq.heappush(q, (trip[2], trip[1], trip[0]))
            cur_people += trip[0]
            extract_trip = q[0]
            
            while extract_trip[0] <= trip[1] :# 작은 게 있으면 여러 개 전부 다 pop해야 함.
                heapq.heappop(q)
                cur_people = cur_people - extract_trip[2]
                extract_trip = q[0]

            if cur_people > capacity:
                return False
        
        return True


sol1 = Solution()
trips = [[3,2,8],[4,4,6],[10,8,9]]
capacity = 11
sol1.carPooling(trips, capacity)
# %% 다른 풀이 (재우님)

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        start = []
        end = []
        for trip in trips:
            start.append([trip[1], trip[0]])
            end.append([trip[2], trip[0]])
        start.sort(key=lambda x: x[0])
        end.sort(key=lambda x: x[0])
        m = 0
        n = 0
        curpas = 0
        while(m < len(start) and n < len(end)):
            if start[m][0] < end[n][0]:
                curpas += start[m][1]
                m+=1
                if curpas > capacity:
                    return False
            else:
                curpas -= end[n][1]
                n+=1
        return True