from typing import List

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        if not trips:
            return None
        
        # trips에서 from의 min과 to의 max값을 찾아서 trip path list를 생성
        mins = float('inf')
        maxs = -float('inf')
        for trip in trips:
            if trip[1] < mins:
                mins = trip[1]
            if trip[2] > maxs:
                maxs = trip[2]
        # trip_path에는 현재 자동차에 탑승중인 인원을 기록
        trip_path = [0] * (maxs - mins + 1)
        
        # trip 변수별로, trip_path에 탑승시켜 볼 것
        for trip in trips:
            start = trip[1] - mins
            end = trip[2] - mins  # end에서는 내리고 탈 수 있음!
            for i in range(start, end):
                trip_path[i] += trip[0]
                if trip_path[i] > capacity:
                    return False
        
        return True


sol = Solution()
trips = [[2,1,5],[3,5,7]]
capacity = 3
print(sol.carPooling(trips, capacity))
